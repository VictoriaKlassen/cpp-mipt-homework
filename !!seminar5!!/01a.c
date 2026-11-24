#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t* p = malloc(sizeof(*p));
    if (p == NULL)
        return 1;

    *p = 123;
    printf("%zu\n", *p);
    free(p);
    return 0;
}
