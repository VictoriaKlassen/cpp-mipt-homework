#include <stdio.h>
#include <ctype.h>

int main()
{
    char c;
    scanf("%c", &c);

    /* (a) Без строковых литералов и ctype.h:
       if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
           printf("Letter\n");
       else if (c >= 48 && c <= 57)
           printf("Digit\n");
       else
           printf("Other\n");
    */

    /* (b) Со строковыми литералами, но без ctype.h:
       if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
           printf("Letter\n");
       else if (c >= '0' && c <= '9')
           printf("Digit\n");
       else
           printf("Other\n");
    */

    /* (c) С ctype.h: */
    if (isalpha((unsigned char)c))
        printf("Letter\n");
    else if (isdigit((unsigned char)c))
        printf("Digit\n");
    else
        printf("Other\n");

    return 0;
}
