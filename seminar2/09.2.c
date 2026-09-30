#include <stdio.h>

void bob(int n);

void alice(int n)
{
    n = 3 * n + 1;
    printf("Alice: %i\n", n);
    bob(n);
}

void bob(int n)
{
    n /= 2;
    printf("Bob: %i\n", n);

    if (n == 1)
        return;

    if (n % 2 == 0)
        bob(n);
    else
        alice(n);
}

int main()
{
    int n;
    scanf("%i", &n);

    alice(n);
}
