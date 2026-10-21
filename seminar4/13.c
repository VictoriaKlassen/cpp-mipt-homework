#include <stdio.h>

#define MAX_GAMES 100
#define TITLE_SIZE 50

typedef struct
{
    char title[TITLE_SIZE];
    double average;
} Game;

int main(void)
{
    int n;

    if (scanf("%d", &n) != 1 ||
        n < 0 || n > MAX_GAMES)
    {
        return 1;
    }

    Game games[MAX_GAMES];

    for (int i = 0; i < n; ++i)
    {
        char separator;
        int k;
        int sum = 0;

        if (scanf(" %49[^:]", games[i].title) != 1)
            return 1;

        if (scanf("%c", &separator) != 1 ||
            separator != ':')
        {
            return 1;
        }

        if (scanf("%d", &k) != 1 || k <= 0)
            return 1;

        for (int j = 0; j < k; ++j)
        {
            int rating;

            if (scanf("%d", &rating) != 1)
                return 1;

            sum += rating;
        }

        games[i].average = (double)sum / k;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (games[j].average > games[i].average)
            {
                Game temp = games[i];
                games[i] = games[j];
                games[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        printf("%s, %.3f\n",
               games[i].title,
               games[i].average);
    }

    return 0;
}
