#include <stdio.h>
#include <stdlib.h>

typedef struct book {
    char title[50];
    int pages;
    float price;
} Book;

static void print_book(const Book *book)
{
    printf("%s — %d pages — %.1f\n",
           book->title, book->pages, book->price);
}

int main(void)
{
    const size_t n = 3;
    Book *p = malloc(n * sizeof *p);
    if (p == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    p[0] = (Book){"Don Quixote", 1000, 750.0f};
    p[1] = (Book){"Oblomov", 400, 250.0f};
    p[2] = (Book){"The Odyssey", 500, 500.0f};

    for (size_t i = 0; i < n; ++i)
        print_book(&p[i]);

    free(p);
    return 0;
}
