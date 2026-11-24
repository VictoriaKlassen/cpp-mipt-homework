#include <stdio.h>

int adder(int x)
{
    static int sum = 0;
    sum += x;
    return sum;
}

int main(void)
{
    printf("%d\n", adder(10));
    printf("%d\n", adder(15));
    printf("%d\n", adder(70));
    return 0;
}
