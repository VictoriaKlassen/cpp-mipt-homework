#include <stdio.h>

#define MAX 200

void assign(int A[MAX][MAX], int B[MAX][MAX], int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            A[i][j] = B[i][j];
}

void multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            C[i][j] = 0;

            for (int p = 0; p < n; ++p)
                C[i][j] += A[i][p] * B[p][j];
        }
    }
}

void power(int A[MAX][MAX], int C[MAX][MAX], int n, int k)
{
    int B[MAX][MAX];

    if (k == 0)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                    C[i][j] = 1;
                else
                    C[i][j] = 0;
            }
        }
        return;
    }

    assign(B, A, n);
    assign(C, A, n);

    for (int i = 1; i < k; ++i)
    {
        multiply(A, B, C, n);
        assign(B, C, n);
    }
}

int main()
{
    int n = 3;
    int k = 4;

    int A[MAX][MAX] = {
        {7, 7, 2},
        {1, 8, 3},
        {2, 1, 6}
    };

    int C[MAX][MAX];

    power(A, C, n, k);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            printf("%i ", C[i][j]);

        printf("\n");
    }

}
