#include <stdio.h>

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
    Book a = {"Don Quixote", 1000, 750.0f};
    Book *p = &a;
    print_book(p);

    /* p points to a stack object; do not call free(p). */
    return 0;
}
