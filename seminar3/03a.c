#include <stdio.h>

int main()
{
    char c;
    scanf("%c", &c);

    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        printf("Letter\n");
    else if (c >= 48 && c <= 57)
        printf("Digit\n");
    else
        printf("Other\n");

    return 0;
}
