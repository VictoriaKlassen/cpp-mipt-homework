#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book {
    char title[50];
    int pages;
    float price;
} Book;

static void print_book(const Book *book)
{
    printf("Title: %s\nPages: %d\nPrice: %.1f\n",
           book->title, book->pages, book->price);
}

int main(void)
{
    Book *p = malloc(sizeof *p);
    if (p == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    snprintf(p->title, sizeof p->title, "%s", "Don Quixote");
    p->pages = 1000;
    p->price = 750.0f;
    print_book(p);

    free(p);
    return 0;
}
