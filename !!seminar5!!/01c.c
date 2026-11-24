#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char** p = malloc(sizeof(*p));
    if (p == NULL)
        return 1;

    const char* text = "Cats and Dogs";
    *p = malloc(strlen(text) + 1);
    if (*p == NULL)
    {
        free(p);
        return 1;
    }

    strcpy(*p, text);
    printf("%s\n", *p);
    free(*p);
    free(p);
    return 0;
}
