#include <stdio.h>

void encrypt(char* str, int k)
{
    k %= 26;

    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = (char)('A' + (str[i] - 'A' + k + 26) % 26);
        else if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = (char)('a' + (str[i] - 'a' + k + 26) % 26);
    }
}

int main()
{
    int k;
    char str[1000];

    scanf("%d ", &k);
    fgets(str, sizeof(str), stdin);

    encrypt(str, k);
    printf("%s", str);

    return 0;
}
