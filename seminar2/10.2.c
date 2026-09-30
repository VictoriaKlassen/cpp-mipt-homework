#include <stdio.h>

#define MAX 200

void assign(float A[MAX][MAX], float B[MAX][MAX], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            A[i][j] = B[i][j];
    }
}

int main()
{
    int n = 3;

    float A[MAX][MAX] = {0};
    float B[MAX][MAX] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    assign(A, B, n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            printf("%g ", A[i][j]);

        printf("\n");
    }

}
