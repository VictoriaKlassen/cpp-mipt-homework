#include <stdio.h>
#include <stdlib.h>

float* get_geometric_progression(float a, float r, int n)
{
    if (n <= 0)
        return NULL;

    float* p = malloc((size_t)n * sizeof(*p));
    if (p == NULL)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        p[i] = a;
        a *= r;
    }
    return p;
}

int main(void)
{
    float* p = get_geometric_progression(1.0f, 3.0f, 10);
    if (p == NULL)
        return 1;

    for (int i = 0; i < 10; i++)
        printf("%.0f ", p[i]);
    printf("\n");
    free(p);
    return 0;
}
