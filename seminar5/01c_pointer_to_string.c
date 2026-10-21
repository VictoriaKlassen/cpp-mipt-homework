#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char *source = "Cats and Dogs";
    char **p = malloc(sizeof *p);
    if (p == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    *p = malloc(strlen(source) + 1);
    if (*p == NULL) {
        perror("malloc");
        free(p);
        return EXIT_FAILURE;
    }

    strcpy(*p, source);
    printf("%s\n", *p);

    free(*p);
    free(p);
    return 0;
}
