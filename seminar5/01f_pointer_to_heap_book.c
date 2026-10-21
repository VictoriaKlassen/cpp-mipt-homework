#include <stdio.h>
#include <stdlib.h>

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
    Book **p = malloc(sizeof *p);
    if (p == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    *p = malloc(sizeof **p);
    if (*p == NULL) {
        perror("malloc");
        free(p);
        return EXIT_FAILURE;
    }

    **p = (Book){"Don Quixote", 1000, 750.0f};
    print_book(*p);

    free(*p);
    free(p);
    return 0;
}
