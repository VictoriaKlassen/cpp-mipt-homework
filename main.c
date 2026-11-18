#include "dynarray.h"

int main(void)
{
    Dynarray a;
    init(&a, 0);
    for (int i = 0; i < 100; ++i)
        push_back(&a, i);
    print(&a);
    destroy(&a);
    return 0;
}
