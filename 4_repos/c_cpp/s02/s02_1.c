#include <stdio.h>

void troca(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    troca(&a, &b);

    printf("%d %d\n", a, b);

    return 0;
}