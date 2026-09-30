#include <stdio.h>
#include <math.h>

const double step = 1e-2;
const double eps = 1e-10;

double f(double t, double x)
{
    return pow(t, x - 1) * exp(-t);
}

double gamma(double x)
{
    double result = 0;
    double t = 0;

    while (1)
    {
        double area = (f(t, x) + f(t + step, x)) * step / 2;
        result += area;
        t += step;

        if (t > x && area < eps)
            break;
    }

    return result;
}

int main()
{
    double x;
    scanf("%lf", &x);

    printf("%.10g\n", gamma(x));

}
