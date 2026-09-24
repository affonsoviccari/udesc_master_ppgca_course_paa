#include <stdio.h>

void troca(int **ppa, int **ppb) {
    // a b *pa *pb
    // 1 2  2   1
    int * ptemp;
    ptemp = *ppa;
    *ppa = *ppb;
    *ppb = ptemp;
}

int main(){

    int a, b;
    int *pa, *pb;
    pa = &a;
    pb = &b;
    scanf("%d %d", &a, &b);
    troca(&pa, &pb);
    printf("%d %d %d %d\n", a, b, *pa, *pb);

    return 0;
}

