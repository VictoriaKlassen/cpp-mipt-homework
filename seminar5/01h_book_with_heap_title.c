#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book {
    char *title;
    int pages;
    float price;
} Book;

static int book_set(Book *book, const char *title, int pages, float price)
{
    book->title = malloc(strlen(title) + 1);
    if (book->title == NULL)
        return 0;

    strcpy(book->title, title);
    book->pages = pages;
    book->price = price;
    return 1;
}

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

    if (!book_set(p, "Don Quixote", 1000, 750.0f)) {
        perror("malloc");
        free(p);
        return EXIT_FAILURE;
    }

    print_book(p);
    free(p->title);
    free(p);
    return 0;
}
