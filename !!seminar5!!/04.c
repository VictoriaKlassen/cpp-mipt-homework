#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** get_test_strings(void)
{
    const char* names[3] = {"Cat", "Mouse", "Elephant"};
    char** words = calloc(4, sizeof(*words));
    if (words == NULL)
        return NULL;

    for (size_t i = 0; i < 3; i++)
    {
        words[i] = malloc(strlen(names[i]) + 1);
        if (words[i] == NULL)
        {
            for (size_t j = 0; j < i; j++)
                free(words[j]);
            free(words);
            return NULL;
        }
        strcpy(words[i], names[i]);
    }
    return words;
}

void print_strings(const char** string_array)
{
    if (string_array == NULL)
        return;
    for (size_t i = 0; string_array[i] != NULL; i++)
        printf("%s\n", string_array[i]);
}

size_t* get_sizes(const char** string_array)
{
    if (string_array == NULL)
        return NULL;
    size_t n = 0;
    while (string_array[n] != NULL)
        n++;
    size_t* sizes = malloc((n ? n : 1) * sizeof(*sizes));
    if (sizes == NULL)
        return NULL;
    for (size_t i = 0; i < n; i++)
        sizes[i] = strlen(string_array[i]);
    return sizes;
}

void destroy_strings(char*** p_string_array)
{
    if (p_string_array == NULL || *p_string_array == NULL)
        return;
    for (size_t i = 0; (*p_string_array)[i] != NULL; i++)
        free((*p_string_array)[i]);
    free(*p_string_array);
    *p_string_array = NULL;
}

void sort_strings(char** words)
{
    if (words == NULL)
        return;
    for (size_t i = 0; words[i] != NULL; i++)
        for (size_t j = i + 1; words[j] != NULL; j++)
            if (strcmp(words[i], words[j]) > 0)
            {
                char* temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
}

char** load_lines(const char* filename)
{
    FILE* f = fopen(filename, "rb");
    if (f == NULL)
        return NULL;

    size_t capacity = 4;
    size_t count = 0;
    char** lines = malloc((capacity + 1) * sizeof(*lines));
    if (lines == NULL)
    {
        fclose(f);
        return NULL;
    }
    lines[0] = NULL;

    for (;;)
    {
        size_t len = 0;
        size_t line_capacity = 64;
        char* line = malloc(line_capacity);
        if (line == NULL)
            goto error;

        int ch;
        while ((ch = fgetc(f)) != EOF && ch != '\n')
        {
            if (len + 1 >= line_capacity)
            {
                if (line_capacity > (size_t)-1 / 2)
                {
                    free(line);
                    goto error;
                }
                line_capacity *= 2;
                char* temp = realloc(line, line_capacity);
                if (temp == NULL)
                {
                    free(line);
                    goto error;
                }
                line = temp;
            }
            line[len++] = (char)ch;
        }

        if (ch == EOF && len == 0)
        {
            free(line);
            break;
        }
        if (len > 0 && line[len - 1] == '\r')
            len--;
        line[len] = '\0';

        if (count == capacity)
        {
            if (capacity > ((size_t)-1 / sizeof(*lines) - 1) / 2)
            {
                free(line);
                goto error;
            }
            capacity *= 2;
            char** temp = realloc(lines, (capacity + 1) * sizeof(*lines));
            if (temp == NULL)
            {
                free(line);
                goto error;
            }
            lines = temp;
        }
        lines[count++] = line;
        lines[count] = NULL;
        if (ch == EOF)
            break;
    }

    if (ferror(f))
        goto error;
    fclose(f);
    return lines;

error:
    for (size_t i = 0; i < count; i++)
        free(lines[i]);
    free(lines);
    fclose(f);
    return NULL;
}

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s input.txt output.txt\n", argv[0]);
        return 1;
    }

    char** words = load_lines(argv[1]);
    if (words == NULL)
    {
        fprintf(stderr, "Cannot read input file\n");
        return 1;
    }

    sort_strings(words);
    FILE* f = fopen(argv[2], "w");
    if (f == NULL)
    {
        destroy_strings(&words);
        return 1;
    }

    int failed = 0;
    for (size_t i = 0; words[i] != NULL; i++)
        if (fprintf(f, "%s\n", words[i]) < 0)
            failed = 1;
    if (fclose(f) != 0)
        failed = 1;

    destroy_strings(&words);
    return failed ? 1 : 0;
}
