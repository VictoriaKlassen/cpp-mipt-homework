#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(const char* a, const char* b)
{
    size_t na = strlen(a);
    size_t nb = strlen(b);
    if (na > (size_t)-1 - nb - 1)
        return NULL;

    char* result = malloc(na + nb + 1);
    if (result == NULL)
        return NULL;

    memcpy(result, a, na);
    memcpy(result + na, b, nb + 1);
    return result;
}

int main(void)
{
    char* p = concat("Hello, ", "World!");
    if (p == NULL)
        return 1;

    printf("%s\n", p);
    free(p);
    return 0;
}
