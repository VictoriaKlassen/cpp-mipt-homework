#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **get_test_strings(void)
{
    char **strings = calloc(4, sizeof *strings); /* 3 strings + NULL */
    if (strings == NULL)
        return NULL;

    const char *source[] = {"Cat", "Mouse", "Elephant"};
    for (size_t i = 0; i < 3; ++i) {
        strings[i] = malloc(strlen(source[i]) + 1);
        if (strings[i] == NULL) {
            for (size_t j = 0; j < i; ++j)
                free(strings[j]);
            free(strings);
            return NULL;
        }
        strcpy(strings[i], source[i]);
    }
    return strings;
}

void print_strings(const char **string_array)
{
    if (string_array == NULL)
        return;

    for (size_t i = 0; string_array[i] != NULL; ++i)
        puts(string_array[i]);
}

size_t *get_sizes(const char **string_array)
{
    if (string_array == NULL)
        return NULL;

    size_t n = 0;
    while (string_array[n] != NULL)
        ++n;

    size_t *sizes = malloc(n * sizeof *sizes);
    if (n != 0 && sizes == NULL)
        return NULL;

    for (size_t i = 0; i < n; ++i)
        sizes[i] = strlen(string_array[i]);

    return sizes;
}

char **load_lines(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
        return NULL;

    char **lines = NULL;
    size_t count = 0;
    size_t capacity = 0;
    char *line = NULL;
    size_t line_capacity = 0;
    ssize_t length;

    while ((length = getline(&line, &line_capacity, file)) != -1) {
        if (length > 0 && line[length - 1] == '\n')
            line[--length] = '\0';

        if (count + 1 >= capacity) {
            size_t new_capacity = capacity == 0 ? 8 : capacity * 2;
            char **tmp = realloc(lines, new_capacity * sizeof *lines);
            if (tmp == NULL)
                goto fail;
            lines = tmp;
            capacity = new_capacity;
        }

        lines[count] = malloc((size_t)length + 1);
        if (lines[count] == NULL)
            goto fail;
        memcpy(lines[count], line, (size_t)length + 1);
        ++count;
        lines[count] = NULL;
    }

    if (ferror(file))
        goto fail;

    if (lines == NULL) {
        lines = calloc(1, sizeof *lines);
        if (lines == NULL)
            goto fail;
    } else {
        char **tmp = realloc(lines, (count + 1) * sizeof *lines);
        if (tmp != NULL)
            lines = tmp;
    }

    free(line);
    fclose(file);
    return lines;

fail:
    if (lines != NULL) {
        for (size_t i = 0; i < count; ++i)
            free(lines[i]);
    }
    free(lines);
    free(line);
    fclose(file);
    return NULL;
}

void destroy_strings(char ***p_string_array)
{
    if (p_string_array == NULL || *p_string_array == NULL)
        return;

    for (size_t i = 0; (*p_string_array)[i] != NULL; ++i)
        free((*p_string_array)[i]);

    free(*p_string_array);
    *p_string_array = NULL;
}

static int compare_strings(const void *a, const void *b)
{
    const char *const *sa = a;
    const char *const *sb = b;
    return strcmp(*sa, *sb);
}

void sort_strings(char **words)
{
    if (words == NULL)
        return;

    size_t n = 0;
    while (words[n] != NULL)
        ++n;

    qsort(words, n, sizeof *words, compare_strings);
}

int main(int argc, char **argv)
{
    if (argc == 3) {
        char **lines = load_lines(argv[1]);
        if (lines == NULL) {
            perror(argv[1]);
            return EXIT_FAILURE;
        }

        sort_strings(lines);
        FILE *output = fopen(argv[2], "w");
        if (output == NULL) {
            perror(argv[2]);
            destroy_strings(&lines);
            return EXIT_FAILURE;
        }

        for (size_t i = 0; lines[i] != NULL; ++i)
            fprintf(output, "%s\n", lines[i]);

        int failed = ferror(output);
        if (fclose(output) != 0)
            failed = 1;
        destroy_strings(&lines);
        return failed ? EXIT_FAILURE : EXIT_SUCCESS;
    }

    char **strings = get_test_strings();
    if (strings == NULL) {
        perror("get_test_strings");
        return EXIT_FAILURE;
    }

    puts("Original strings:");
    print_strings((const char **)strings);

    size_t *sizes = get_sizes((const char **)strings);
    if (sizes == NULL) {
        destroy_strings(&strings);
        return EXIT_FAILURE;
    }
    printf("Sizes: %zu %zu %zu\n", sizes[0], sizes[1], sizes[2]);
    free(sizes);

    sort_strings(strings);
    puts("Sorted strings:");
    print_strings((const char **)strings);
    destroy_strings(&strings);

    fprintf(stderr, "Usage for file sorting: %s input.txt output.txt\n", argv[0]);
    return 0;
}
