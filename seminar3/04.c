#include <stdio.h>
#include <string.h>

int main()
{
    char a[100], b[100];

    scanf("%99s %99s", a, b);

    size_t i = 0;
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);

    while (i < len_a || i < len_b)
    {
        if (i < len_a)
            printf("%c", a[i]);

        if (i < len_b)
            printf("%c", b[i]);

        ++i;
    }

    printf("\n");
    return 0;
}
