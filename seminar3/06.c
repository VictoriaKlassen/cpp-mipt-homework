#include <stdio.h>
#include <string.h>

int is_palindrom(const char str[])
{
    size_t len = strlen(str);

    for (size_t i = 0; i < len / 2; ++i)
    {
        if (str[i] != str[len - 1 - i])
            return 0;
    }

    return 1;
}

int main()
{
    char str[1000];
    scanf("%999s", str);

    if (is_palindrom(str))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
