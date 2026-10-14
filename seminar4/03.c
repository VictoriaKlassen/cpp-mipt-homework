#include <stdio.h>
void cube(float* px) { *px = *px * *px * *px; }
int main(void) {
    float x = 2.0f;
    cube(&x);
    printf("%f\n", x);
    return 0;
}
