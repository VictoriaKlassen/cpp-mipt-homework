#include <stdio.h>
#include <stddef.h>

int less(int a, int b)
{
    return a < b;
}

int greater(int a, int b)
{
    return a > b;
}

int last_digit_less(int a, int b)
{
    return a % 10 < b % 10;
}

void sort(int* a, size_t n, int (*cmp)(int, int))
{
    for (size_t j = 0; j < n; j++)
    {
        size_t best = j;
        for (size_t i = j + 1; i < n; i++)
            if (cmp(a[i], a[best]))
                best = i;

        int temp = a[j];
        a[j] = a[best];
        a[best] = temp;
    }
}

void print(const int* a, size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(void)
{
    int a[] = {32, 63, 29, 54, 81};
    sort(a, 5, less);
    print(a, 5);
    sort(a, 5, greater);
    print(a, 5);
    sort(a, 5, last_digit_less);
    print(a, 5);
    return 0;
}
