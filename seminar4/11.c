#include <stdio.h>
#include <math.h>
typedef struct point { double x; double y; } Point;
typedef struct triangle { Point a, b, c; } Triangle;
void print_point(Point p) { printf("(%.2f, %.2f)", p.x, p.y); }
void print_triangle(const Triangle* t) {
    printf("{"); print_point(t->a); printf(", ");
    print_point(t->b); printf(", "); print_point(t->c);
    printf("}\n");
}
double distance(Point a, Point b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
double get_triangle_perimeter(const Triangle* t) {
    return distance(t->a, t->b) + distance(t->b, t->c) + distance(t->c, t->a);
}
Triangle moved_triangle(const Triangle* t, Point d) {
    Triangle r = *t;
    r.a.x += d.x; r.a.y += d.y;
    r.b.x += d.x; r.b.y += d.y;
    r.c.x += d.x; r.c.y += d.y;
    return r;
}
void move_triangle(Triangle* t, Point d) {
    t->a.x += d.x; t->a.y += d.y;
    t->b.x += d.x; t->b.y += d.y;
    t->c.x += d.x; t->c.y += d.y;
}
int main(void) {
    Triangle t = {{1.00, 0.00}, {0.50, 2.00}, {0.00, 1.50}};
    printf("Perimeter = %.2f\n", get_triangle_perimeter(&t));
    Point d = {1.0, 1.0};
    print_triangle(&t); move_triangle(&t, d); print_triangle(&t);
    return 0;
}
