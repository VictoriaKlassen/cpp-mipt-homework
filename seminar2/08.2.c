#include <stdio.h>

void reverse(int array[], int size)
{
    for (int i = 0; i < size / 2; ++i)
    {
        int temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
}

int main()
{
    int array[] = {10, 20, 30, 40, 50};
    int size = 5;

    reverse(array, size);

    for (int i = 0; i < size; ++i)
        printf("%i ", array[i]);

    printf("\n");

}
