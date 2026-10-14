#include <stdio.h>
typedef struct node { int value; struct node* ptr; } Node;
int main(void) {
    Node a = {10, NULL}, b = {20, NULL}, c = {30, NULL};
    a.ptr = &b;
    b.ptr = &c;
    c.ptr = &a;
    Node* p = &a;
    while (1) {
        printf("%d\n", p->value);
        p = p->ptr;
    }
}
