#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(const char *a, const char *b)
{
    if (a == NULL || b == NULL)
        return NULL;

    size_t len_a = strlen(a);
    size_t len_b = strlen(b);

    if (len_a > (size_t)-1 - len_b - 1)
        return NULL;

    char *result = malloc(len_a + len_b + 1);
    if (result == NULL)
        return NULL;

    memcpy(result, a, len_a);
    memcpy(result + len_a, b, len_b + 1);
    return result;
}

int main(void)
{
    char *result = concat("Hello, ", "world!");
    if (result == NULL) {
        fprintf(stderr, "Could not concatenate strings\n");
        return EXIT_FAILURE;
    }

    puts(result);
    free(result);
    return 0;
}
