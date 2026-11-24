#include <stdio.h>
#include <stdlib.h>

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
    Book a = {"Don Quixote", 1000, 750.0f};
    Book** p = malloc(sizeof(*p));
    if (p == NULL)
        return 1;

    *p = &a;
    print_book(*p);
    free(p);
    return 0;
}
