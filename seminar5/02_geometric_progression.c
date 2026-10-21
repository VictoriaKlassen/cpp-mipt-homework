#include <stdio.h>
#include <stdlib.h>

float *get_geometric_progression(float a, float r, int n)
{
    if (n < 0)
        return NULL;

    if (n == 0)
        return NULL;

    float *values = malloc((size_t)n * sizeof *values);
    if (values == NULL)
        return NULL;

    values[0] = a;
    for (int i = 1; i < n; ++i)
        values[i] = values[i - 1] * r;

    return values;
}

int main(void)
{
    float *p = get_geometric_progression(1.0f, 3.0f, 10);
    if (p == NULL) {
        fprintf(stderr, "Could not allocate progression\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 10; ++i)
        printf("%.0f%c", p[i], i == 9 ? '\n' : ' ');

    free(p);
    return 0;
}
