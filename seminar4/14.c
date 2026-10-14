#include <stdio.h>
#include <stddef.h>
struct cat { char x; size_t y; };
struct dog { size_t y; char x; };
struct mouse { char x; char y; size_t z; };
struct rat { char x; size_t z; char y; };
struct fox { char x; struct mouse y; };
#define PRINT_TYPE(T) printf("%-20s size=%zu align=%zu\n", #T, sizeof(T), _Alignof(T))
int main(void) {
    PRINT_TYPE(char);
    PRINT_TYPE(int);
    PRINT_TYPE(size_t);
    PRINT_TYPE(int[10]);
    PRINT_TYPE(int*);
    PRINT_TYPE(struct cat);
    PRINT_TYPE(struct dog);
    PRINT_TYPE(struct mouse);
    PRINT_TYPE(struct rat);
    PRINT_TYPE(struct fox);
    return 0;
}
