#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TITLE_SIZE 256
#define MAX_GAMES 1000
typedef struct { char title[TITLE_SIZE]; double average; } Game;
static void trim_newline(char* s) {
    size_t n = strlen(s);
    while (n && (s[n-1] == '\n' || s[n-1] == '\r')) s[--n] = '\0';
}
int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n < 0 || n > MAX_GAMES) return 1;
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
    Game games[MAX_GAMES];
    for (int i = 0; i < n; ++i) {
        char line[4096];
        if (!fgets(line, sizeof(line), stdin)) return 1;
        trim_newline(line);
        char* colon = strchr(line, ':');
        if (!colon) return 1;
        *colon = '\0';
        strncpy(games[i].title, line, TITLE_SIZE - 1);
        games[i].title[TITLE_SIZE - 1] = '\0';
        char* p = colon + 1;
        while (*p == ' ' || *p == '\t') ++p;
        char* endptr;
        long k_long = strtol(p, &endptr, 10);
        if (endptr == p || k_long <= 0) return 1;
        int k = (int)k_long;
        p = endptr;
        long sum = 0;
        for (int j = 0; j < k; ++j) {
            while (*p == ' ' || *p == '\t') ++p;
            long score = strtol(p, &endptr, 10);
            if (endptr == p) return 1;
            sum += score;
            p = endptr;
        }
        games[i].average = (double)sum / k;
    }
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (games[j].average > games[i].average) {
                Game tmp = games[i]; games[i] = games[j]; games[j] = tmp;
            }
    for (int i = 0; i < n; ++i) printf("%s, %.3f\n", games[i].title, games[i].average);
    return 0;
}
