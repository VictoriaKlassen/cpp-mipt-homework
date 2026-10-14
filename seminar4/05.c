#include <math.h>
int solve_quadratic(double a, double b, double c, double* px1, double* px2) {
    const double eps = 1e-10;
    if (fabs(a) < eps) {
        if (fabs(b) < eps) return 0;
        *px1 = -c / b;
        return 1;
    }
    double D = b * b - 4.0 * a * c;
    if (D < -eps) return 0;
    if (fabs(D) <= eps) {
        *px1 = -b / (2.0 * a);
        return 1;
    }
    double sqrtD = sqrt(D);
    *px1 = (-b - sqrtD) / (2.0 * a);
    *px2 = (-b + sqrtD) / (2.0 * a);
    return 2;
}
