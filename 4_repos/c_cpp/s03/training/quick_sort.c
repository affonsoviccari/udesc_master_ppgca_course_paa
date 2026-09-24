#include <stdio.h>

void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int partition(int v[], int p, int r){
    int pivot = v[r];
    int i = p;

    for (int j = p; j < r; j++){
        if (v[j] < pivot) {
            swap(&v[i], &v[j]);
            i++;
        }
    }
    swap(&v[i], &v[r]);
    return i;
}

void quicksort(int v[], int lenght, int p, int r){

    if (p >= r) return;

    int q = partition(v, p, r);
    quicksort(v, lenght, p, q-1);
    quicksort(v, lenght, q+1, r);
}

int main(){

    int lenght;
    scanf("%d", &lenght);

    int v[lenght];
    for (int i=0; i < lenght; i++){
        scanf("%d", &v[i]);
    }

    quicksort(v, lenght, 0, lenght - 1);

    for (int i=0; i < lenght; i++){
        printf("%d ", v[i]);
    }

    return 0;
}