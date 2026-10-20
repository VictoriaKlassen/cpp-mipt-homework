#include <stdio.h>
#include <string.h>

void used_chars(const char* str, char* used)
{
    int seen[26] = {0};

    for (const char* p = str; *p; p++)
    {
        char c = *p;
        if (c >= 'A' && c <= 'Z')
            c = c - 'A' + 'a';
        if (c >= 'a' && c <= 'z')
            seen[c - 'a'] = 1;
    }

    char* q = used;
    for (int i = 0; i < 26; i++)
        if (seen[i])
            *q++ = 'a' + i;
    *q = '\0';
}

int main(void)
{
    char s[50] = "Sapere Aude";
    char u[30];
    used_chars(s, u);
    printf("%s\n", u);   // adeprsu

    strcpy(s, "123!$@");
    used_chars(s, u);
    printf("%s\n", u);   // пустая строка

    strcpy(s, "The Quick Brown Fox Jumps Over The Lazy Dog!");
    used_chars(s, u);
    printf("%s\n", u);   // abcdefghijklmnopqrstuvwxyz

    return 0;
}
