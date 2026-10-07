#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc != 3)
        return 1;

    int n;
    if (sscanf(argv[2], "%d", &n) != 1)
        return 1;

    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
            printf(" ");

        printf("%s", argv[1]);
    }

    printf("\n");

    return 0;
}
