#include "dynarray.h"

#include <assert.h>
#include <stdio.h>

int main(void)
{
    Dynarray a;
    init(&a, 3);
    assert(a.size == 3 && a.capacity == 3);
    assert(get(&a, 0) == 0 && get(&a, 1) == 0 && get(&a, 2) == 0);
    set(&a, 0, 10);
    set(&a, 1, 20);
    set(&a, 2, 30);
    push_back(&a, 40);
    assert(a.size == 4 && a.capacity == 6);
    push_back(&a, 50);
    push_back(&a, 60);
    assert(a.size == 6 && a.capacity == 6);
    push_back(&a, 70);
    assert(a.size == 7 && a.capacity == 12);
    for (size_t i = 0; i < a.size; ++i)
        assert(get(&a, i) == (int)(10 * (i + 1)));
    reserve(&a, 20);
    assert(a.capacity == 20);
    reserve(&a, 2);
    assert(a.capacity == 20);
    destroy(&a);
    assert(a.data == NULL && a.size == 0 && a.capacity == 0);
    puts("All Dynarray tests passed.");
    return 0;
}
