#include <stdio.h>

int main()
{
    int n;
    int m;

    scanf("%i%i", &n, &m);

    int sum[1000] = {0};

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int a;
            scanf("%i", &a);

            sum[j] += a;
        }
    }

    for (int j = 0; j < m; ++j)
        printf("%i ", sum[j]);

    printf("\n");
}