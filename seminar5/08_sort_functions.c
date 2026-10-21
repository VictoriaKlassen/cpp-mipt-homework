#include <stdio.h>
#include <stddef.h>

int sum(int x, int y)    { return x + y; }
int diff(int x, int y)   { return x - y; }
int mult(int x, int y)   { return x * y; }
int sqdiff(int x, int y) { return x * x - y * y; }
int lin(int x, int y)    { return 5 * x - y; }

typedef int (*FuncPtr)(int, int);

void print_func_name(FuncPtr p)
{
    if (p == sum) puts("sum");
    else if (p == diff) puts("diff");
    else if (p == mult) puts("mult");
    else if (p == sqdiff) puts("sqdiff");
    else if (p == lin) puts("lin");
    else puts("other");
}

void print_array_names(FuncPtr *array, size_t n)
{
    for (size_t i = 0; i < n; ++i)
        print_func_name(array[i]);
}

void sort_funcs(FuncPtr *a, size_t n, int x, int y)
{
    if (a == NULL)
        return;

    for (size_t j = 0; j < n; ++j) {
        size_t min_index = j;
        for (size_t i = j + 1; i < n; ++i) {
            if (a[i](x, y) < a[min_index](x, y))
                min_index = i;
        }

        FuncPtr temp = a[j];
        a[j] = a[min_index];
        a[min_index] = temp;
    }
}

int main(void)
{
    FuncPtr array[5] = {sum, diff, mult, sqdiff, lin};

    print_array_names(array, 5);
    puts("--- sorted for (2, 2) ---");
    sort_funcs(array, 5, 2, 2);
    print_array_names(array, 5);
    puts("--- sorted for (8, 1) ---");
    sort_funcs(array, 5, 8, 1);
    print_array_names(array, 5);
    return 0;
}
