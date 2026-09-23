#include <stdio.h>

int main()
{
    int n;

    scanf("%i", &n);

    int a[10000];
    int b[10000];
    int c[10000];

    for (int i = 0; i < n * n; ++i)
        scanf("%i", &a[i]);

    for (int i = 0; i < n * n; ++i)
        scanf("%i", &b[i]);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            c[i * n + j] = 0;

            for (int k = 0; k < n; ++k)
                c[i * n + j] += a[i * n + k] * b[k * n + j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            printf("%i ", c[i * n + j]);

        printf("\n");
    }
}