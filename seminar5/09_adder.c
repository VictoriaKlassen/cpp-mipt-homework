#include <stdio.h>

int adder(int value)
{
    static int total = 0;
    total += value;
    return total;
}

int main(void)
{
    printf("%d\n", adder(10)); /* 10 */
    printf("%d\n", adder(15)); /* 25 */
    printf("%d\n", adder(70)); /* 95 */
    return 0;
}
