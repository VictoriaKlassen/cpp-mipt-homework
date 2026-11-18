#include "dynarray.h"

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static void* ecmalloc(size_t n)
{
    void* p = malloc(n);
    if (p == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

static void check_capacity(size_t capacity)
{
    if (capacity > SIZE_MAX / sizeof(int)) {
        fprintf(stderr, "Array capacity is too large.\n");
        exit(EXIT_FAILURE);
    }
}

void init(Dynarray* pd, size_t initial_size)
{
    assert(pd != NULL);
    pd->size = initial_size;
    pd->capacity = initial_size;
    pd->data = NULL;
    if (initial_size != 0) {
        check_capacity(initial_size);
        pd->data = ecmalloc(initial_size * sizeof(int));
        for (size_t i = 0; i < initial_size; ++i)
            pd->data[i] = 0;
    }
}

int get(const Dynarray* pd, size_t index)
{
    assert(pd != NULL && index < pd->size);
    return pd->data[index];
}

void set(Dynarray* pd, size_t index, int value)
{
    assert(pd != NULL && index < pd->size);
    pd->data[index] = value;
}

void reserve(Dynarray* pd, size_t new_capacity)
{
    assert(pd != NULL);
    if (new_capacity <= pd->capacity)
        return;
    check_capacity(new_capacity);
    int* new_data = ecmalloc(new_capacity * sizeof(int));
    for (size_t i = 0; i < pd->size; ++i)
        new_data[i] = pd->data[i];
    free(pd->data);
    pd->data = new_data;
    pd->capacity = new_capacity;
}

void push_back(Dynarray* pd, int value)
{
    assert(pd != NULL);
    if (pd->size == pd->capacity) {
        size_t new_capacity;
        if (pd->capacity == 0)
            new_capacity = 1;
        else if (pd->capacity > SIZE_MAX / 2)
            new_capacity = SIZE_MAX / sizeof(int);
        else
            new_capacity = pd->capacity * 2;
        if (new_capacity <= pd->size) {
            fprintf(stderr, "Array is too large.\n");
            exit(EXIT_FAILURE);
        }
        reserve(pd, new_capacity);
    }
    pd->data[pd->size] = value;
    ++pd->size;
}

void print(const Dynarray* pd)
{
    assert(pd != NULL);
    printf("dynarray: ");
    for (size_t i = 0; i < pd->size; ++i)
        printf("%d ", pd->data[i]);
    printf("\n");
}

void destroy(Dynarray* pd)
{
    assert(pd != NULL);
    free(pd->data);
    pd->data = NULL;
    pd->size = 0;
    pd->capacity = 0;
}
