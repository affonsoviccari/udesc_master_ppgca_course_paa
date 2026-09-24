#include <stdio.h>

typedef struct {
    float x;
    float y;
} Point;

void deslocamento(Point *p, float dx, float dy) {
    p->x += dx;
    p->y += dy;
}

int main() {
    Point p;

    p.x = 10;
    p.y = 20;

    float dx, dy;

    scanf("%f %f", &dx, &dy);
    deslocamento(&p, dx, dy);

    printf("%.2f %.2f \n", p.x, p.y);

    return 0;
}