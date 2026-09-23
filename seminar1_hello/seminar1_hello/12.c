#include <stdio.h>

int main()
{
    int a[10000];
    int sum[10000];
    int n;

    scanf("%i", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%i", &a[i]);

        int x = a[i];

        if (x < 0)
            x = -x;

        sum[i] = 0;

        while (x > 0)
        {
            sum[i] += x % 10;
            x /= 10;
        }
    }

    for (int j = 0; j < n; ++j)
    {
        for (int i = 0; i < n - 1 - j; ++i)
        {
            if (sum[i] > sum[i + 1])
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;

                temp = sum[i];
                sum[i] = sum[i + 1];
                sum[i + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; ++i)
        printf("%i ", a[i]);

    printf("\n");
}