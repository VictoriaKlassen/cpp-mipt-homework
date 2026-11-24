#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char* text = "Elephant";
    char* p = malloc(strlen(text) + 1);
    if (p == NULL)
        return 1;

    strcpy(p, text);
    printf("%s\n", p);
    free(p);
    return 0;
}
