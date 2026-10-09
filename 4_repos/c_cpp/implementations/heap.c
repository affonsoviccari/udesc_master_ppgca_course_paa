/**
 * Implementação: Heap binária, Heapsort (Heap de Máximo)
 * Fonte: Prof. Yuri Kaszubowski Lopes 
 */
#include <stdio.h>

int get_parent(int i) {
    return (i-1)/2;
}

int get_left(int i) {
    return (2*i)+1;
}

int get_right(int i) {
    return (2*i)+2;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void max_heapify(int arr[], int i, int heap_size) {
    int left = get_left(i);
    int right = get_right(i);
    int largest = i;
    if ((left <= heap_size)&&(arr[left]>arr[largest])){
        largest = left;
    }
    if ((right <= heap_size)&&(arr[right]>arr[largest])){
        largest = right;
    }
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        max_heapify(arr, largest, heap_size);
    }
}

void build_max_heap(int arr[], int heap_size) {
    for (int i = (heap_size/2)-1;i>=0;i--){
        max_heapify(arr, i, heap_size-1);
    }
}

void heapsort(int arr[], int heap_size){
    build_max_heap(arr, heap_size);
    for (int i = heap_size-1; i>0; i--){
        swap(&arr[0], &arr[i]);
        max_heapify(arr, 0, i-1);
    }
}

void main(){
    int arr[9] = {12, 11, 13, 5, 8, 6, 7, 10, 22};
    int heap_size = 9;
    heapsort(arr, heap_size);
    for (int i=0; i<heap_size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}