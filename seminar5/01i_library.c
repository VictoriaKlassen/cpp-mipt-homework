#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book {
    char *title;
    int pages;
    float price;
} Book;

typedef struct library {
    Book *books;
    int number_of_books;
} Library;

static void print_book(const Book *book)
{
    if (book == NULL) {
        puts("(null book)");
        return;
    }
    printf("Title: %s\nPages: %d\nPrice: %.1f\n",
           book->title, book->pages, book->price);
}

static int library_create(Library *library, int count)
{
    if (library == NULL || count < 0)
        return 0;

    library->books = NULL;
    library->number_of_books = 0;

    if (count == 0)
        return 1;

    library->books = calloc((size_t)count, sizeof *library->books);
    if (library->books == NULL)
        return 0;

    library->number_of_books = count;
    return 1;
}

static int library_set(Library *library, int i, const char *title,
                       int pages, float price)
{
    if (library == NULL || i < 0 || i >= library->number_of_books ||
        title == NULL)
        return 0;

    char *copy = malloc(strlen(title) + 1);
    if (copy == NULL)
        return 0;
    strcpy(copy, title);

    free(library->books[i].title);
    library->books[i].title = copy;
    library->books[i].pages = pages;
    library->books[i].price = price;
    return 1;
}

static Book *library_get(Library *library, int i)
{
    if (library == NULL || i < 0 || i >= library->number_of_books)
        return NULL;
    return &library->books[i];
}

static void library_print(const Library *library)
{
    if (library == NULL)
        return;

    for (int i = 0; i < library->number_of_books; ++i) {
        printf("Book %d:\n", i);
        print_book(&library->books[i]);
    }
}

static void library_destroy(Library *library)
{
    if (library == NULL)
        return;

    for (int i = 0; i < library->number_of_books; ++i)
        free(library->books[i].title);

    free(library->books);
    library->books = NULL;
    library->number_of_books = 0;
}

int main(void)
{
    Library a;
    if (!library_create(&a, 3)) {
        perror("library_create");
        return EXIT_FAILURE;
    }

    if (!library_set(&a, 0, "Don Quixote", 1000, 750.0f) ||
        !library_set(&a, 1, "Oblomov", 400, 250.0f) ||
        !library_set(&a, 2, "The Odyssey", 500, 500.0f)) {
        library_destroy(&a);
        perror("library_set");
        return EXIT_FAILURE;
    }

    library_print(&a);
    print_book(library_get(&a, 1));
    library_destroy(&a);
    return 0;
}
