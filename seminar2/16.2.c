#include <stdio.h>

int main()
{
    int n;
    scanf("%i", &n);

    double sum = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (i % 2 == 1)
            sum += 1.0 / (2 * i - 1);
        else
            sum -= 1.0 / (2 * i - 1);
    }

    double pi = 4 * sum;

    printf("%.10f\n", pi);

}
