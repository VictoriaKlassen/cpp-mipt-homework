#include <stdio.h>
#include <string.h>
#include <stddef.h>
char* strmax(char** strings, size_t n) {
    if (n == 0) return NULL;
    char* best = strings[0];
    for (size_t i = 1; i < n; ++i)
        if (strcmp(strings[i], best) > 0) best = strings[i];
    return best;
}
int main(void) {
    char a[] = "Cat", b[] = "Mouse", c[] = "Wolf";
    char d[] = "Kangaroo", e[] = "Elephant";
    char* animals[5] = {a, b, c, d, e};
    printf("%s\n", strmax(animals, 5));
    return 0;
}
