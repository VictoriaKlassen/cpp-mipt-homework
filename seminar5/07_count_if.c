#include <stdio.h>
#include <stddef.h>

typedef int (*Predicate)(int);

size_t count_if(const int *a, size_t n, Predicate predicate)
{
    if (a == NULL || predicate == NULL)
        return 0;

    size_t count = 0;
    for (size_t i = 0; i < n; ++i) {
        if (predicate(a[i]))
            ++count;
    }
    return count;
}

static int is_negative(int x)
{
    return x < 0;
}

static int is_even(int x)
{
    return x % 2 == 0;
}

static int is_square(int x)
{
    if (x < 0)
        return 0;

    for (int i = 0; i <= x / (i == 0 ? 1 : i); ++i) {
        if (i * i == x)
            return 1;
        if (i > 0 && i > x / i)
            break;
    }
    return 0;
}

int main(void)
{
    int a[] = {89, 81, 28, 52, 44, 16, -64, 49, 52, -79};
    size_t n = sizeof a / sizeof a[0];

    printf("%zu\n", count_if(a, n, is_negative)); /* 2 */
    printf("%zu\n", count_if(a, n, is_even));     /* 6 */
    printf("%zu\n", count_if(a, n, is_square));   /* 3 */
    return 0;
}
