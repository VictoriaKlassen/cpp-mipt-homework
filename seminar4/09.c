#include <stdio.h>
#include <ctype.h>
#include <string.h>
void used_chars(const char* str, char* used) {
    int present[26] = {0};
    while (*str != '\0') {
        unsigned char c = (unsigned char)*str;
        if (isalpha(c)) {
            c = (unsigned char)tolower(c);
            if (c >= 'a' && c <= 'z') present[c - 'a'] = 1;
        }
        ++str;
    }
    int j = 0;
    for (int i = 0; i < 26; ++i)
        if (present[i]) used[j++] = (char)('a' + i);
    used[j] = '\0';
}
int main(void) {
    char s[100] = "Sapere Aude", u[30];
    used_chars(s, u); printf("%s\n", u);
    strcpy(s, "123!$@"); used_chars(s, u); printf("%s\n", u);
    strcpy(s, "The Quick Brown Fox Jumps Over The Lazy Dog!");
    used_chars(s, u); printf("%s\n", u);
    return 0;
}
