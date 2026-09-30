#include <stdio.h>

int count_even(int array[], int size)
{
    int count = 0;

    for (int i = 0; i < size; ++i)
    {
        if (array[i] % 2 == 0)
            count += 1;
    }

    return count;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};

    printf("%i\n", count_even(array, 5));
}
