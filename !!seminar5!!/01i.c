#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book
{
    char* title;
    int pages;
    float price;
} Book;

typedef struct library
{
    Book* books;
    int number_of_books;
} Library;

void print_book(const Book* book)
{
    if (book != NULL && book->title != NULL)
        printf("%s, %d, %.1f\n", book->title, book->pages, book->price);
}

void library_create(Library* lib, int n)
{
    if (lib == NULL || n < 0)
        exit(EXIT_FAILURE);

    lib->books = NULL;
    lib->number_of_books = 0;
    if (n == 0)
        return;

    lib->books = calloc((size_t)n, sizeof(*lib->books));
    if (lib->books == NULL)
        exit(EXIT_FAILURE);
    lib->number_of_books = n;
}

void library_set(Library lib, int i, const char* title, int pages, float price)
{
    if (i < 0 || i >= lib.number_of_books || title == NULL)
        exit(EXIT_FAILURE);

    char* copy = malloc(strlen(title) + 1);
    if (copy == NULL)
        exit(EXIT_FAILURE);

    strcpy(copy, title);
    free(lib.books[i].title);
    lib.books[i].title = copy;
    lib.books[i].pages = pages;
    lib.books[i].price = price;
}

Book* library_get(Library lib, int i)
{
    if (i < 0 || i >= lib.number_of_books)
        return NULL;
    return &lib.books[i];
}

void library_print(Library lib)
{
    for (int i = 0; i < lib.number_of_books; i++)
        print_book(&lib.books[i]);
}

void library_destroy(Library* lib)
{
    if (lib == NULL)
        return;

    for (int i = 0; i < lib->number_of_books; i++)
        free(lib->books[i].title);
    free(lib->books);
    lib->books = NULL;
    lib->number_of_books = 0;
}

int main(void)
{
    Library a;
    library_create(&a, 3);
    library_set(a, 0, "Don Quixote", 1000, 750.0f);
    library_set(a, 1, "Oblomov", 400, 250.0f);
    library_set(a, 2, "The Odyssey", 500, 500.0f);
    library_print(a);
    print_book(library_get(a, 1));
    library_destroy(&a);
    return 0;
}
