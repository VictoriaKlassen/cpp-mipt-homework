#include <stdio.h>

int main()
{
    int a;
    int b;
    int c;

    scanf("%i%i%i", &a, &b, &c);

    if (c < 0)
        c = -c;

    int first = a;
    int remainder = first % c;

    if (remainder > 0)
        first += c - remainder;
    else if (remainder < 0)
        first -= remainder;

    for (int i = first; i <= b; i += c)
        printf("%i ", i);

    printf("\n");
}