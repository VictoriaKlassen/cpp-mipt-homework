#include <stdio.h>
#include <math.h>

int main()
{
    double x1, y1, r1;
    double x2, y2, r2;

    scanf("%lf%lf%lf", &x1, &y1, &r1);
    scanf("%lf%lf%lf", &x2, &y2, &r2);

    double dx = x1 - x2;
    double dy = y1 - y2;
    double d = sqrt(dx * dx + dy * dy);

    double eps = 1e-5;
    double sum = r1 + r2;
    double diff = fabs(r1 - r2);

    if (fabs(d - sum) < eps || fabs(d - diff) < eps)
        printf("Touch\n");
    else if (d > sum || d < diff)
        printf("Do not intersect\n");
    else
        printf("Intersect\n");

}
