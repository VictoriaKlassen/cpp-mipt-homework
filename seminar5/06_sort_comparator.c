#include <stdio.h>
#include <stddef.h>

typedef int (*Comparator)(int, int);

static int less(int a, int b)
{
    return a < b;
}

static int greater(int a, int b)
{
    return a > b;
}

static int last_digit_less(int a, int b)
{
    int da = a % 10;
    int db = b % 10;
    return da < db;
}

void sort(int *a, size_t n, Comparator compare)
{
    if (a == NULL || compare == NULL)
        return;

    for (size_t j = 0; j < n; ++j) {
        size_t best = j;
        for (size_t i = j + 1; i < n; ++i) {
            if (compare(a[i], a[best]))
                best = i;
        }

        int temp = a[j];
        a[j] = a[best];
        a[best] = temp;
    }
}

static void print_array(const int *a, size_t n)
{
    for (size_t i = 0; i < n; ++i)
        printf("%d%c", a[i], i + 1 == n ? '\n' : ' ');
}

int main(void)
{
    int a[] = {32, 63, 29, 54, 81};
    size_t n = sizeof a / sizeof a[0];

    sort(a, n, less);
    print_array(a, n);          /* 29 32 54 63 81 */

    sort(a, n, greater);
    print_array(a, n);          /* 81 63 54 32 29 */

    sort(a, n, last_digit_less);
    print_array(a, n);          /* 81 32 63 54 29 */
    return 0;
}
