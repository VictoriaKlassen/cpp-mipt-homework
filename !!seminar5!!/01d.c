#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book
{
    char title[50];
    int pages;
    float price;
} Book;

void print_book(const Book* p)
{
    printf("%s, %d, %.1f\n", p->title, p->pages, p->price);
}

int main(void)
{
    Book* p = malloc(sizeof(*p));
    if (p == NULL)
        return 1;

    strcpy(p->title, "Don Quixote");
    p->pages = 1000;
    p->price = 750.0f;
    print_book(p);
    free(p);
    return 0;
}
