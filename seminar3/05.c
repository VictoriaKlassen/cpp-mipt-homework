#include <stdio.h>

int main()
{
    char number[110];
    scanf("%109s", number);

    int sum = 0;

    for (int i = 0; number[i] != '\0'; ++i)
        sum += number[i] - '0';

    printf("%i\n", sum);

    return 0;
}
