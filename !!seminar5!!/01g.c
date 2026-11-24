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
    Book* p = malloc(3 * sizeof(*p));
    if (p == NULL)
        return 1;

    p[0] = (Book){"Don Quixote", 1000, 750.0f};
    p[1] = (Book){"Oblomov", 400, 250.0f};
    p[2] = (Book){"The Odyssey", 500, 500.0f};

    for (size_t i = 0; i < 3; i++)
        print_book(&p[i]);

    free(p);
    return 0;
}
