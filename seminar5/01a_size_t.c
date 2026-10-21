#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t *p = malloc(sizeof *p);
    if (p == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    *p = 123;
    printf("%zu\n", *p);

    free(p);
    return 0;
}
