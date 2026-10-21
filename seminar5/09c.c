#include <stdio.h>
#include <stddef.h>

#define SIZE 1000000UL

int main(void)
{
    /* Большой локальный массив обычно размещается на стеке. */
    char data[SIZE];

    getchar();
    puts("1. Setting first char to 'A'");
    data[0] = 'A';

    getchar();
    puts("Setting last char to 'B'");
    data[SIZE - 1] = 'B';

    getchar();
    printf("Printing first char = %c\n", data[0]);

    getchar();
    printf("Printing last char = %c\n", data[SIZE - 1]);

    getchar();
    puts("Setting many chars to X");
    for (size_t i = 0; i < SIZE; i += 1000)
        data[i] = 'X';

    getchar();
    puts("Printing all set chars");
    for (size_t i = 0; i < SIZE; i += 1000)
        printf("%c ", data[i]);
    putchar('\n');

    getchar();
    return 0;
}
