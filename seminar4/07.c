#include <stdio.h>
int* max(int* pa, int* pb) { return (*pa >= *pb) ? pa : pb; }
int main(void) {
    int a = 10, b = 30, c = 20;
    *max(max(&a, &b), &c) += 1;
    printf("%i %i %i\n", a, b, c);
    return 0;
}
