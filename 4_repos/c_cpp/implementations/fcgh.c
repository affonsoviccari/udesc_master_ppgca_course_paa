/**
 * Implementação: Fila circular genérica homogênia.
 * Fonte: Prof. Yuri Kaszubowski Lopes 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    void * data;
    int front;
    int rear;
    int capacity;
    int size;
    size_t data_size;

} circular_queue_t;

circular_queue_t * queue_init(int capacity, size_t data_size){
    if (capacity <= 0 || data_size <= 0){
        return NULL;
    }
    circular_queue_t * q = malloc(sizeof(circular_queue_t));
    if (q == NULL) {
        return NULL;
    }
    q->data = malloc(data_size * capacity);
    if (q->data == NULL) {
        free(q);
        return NULL;
    }
    q->front = 0;
    q->rear = 0;
    q->capacity = capacity;
    q->size = 0;
    q->data_size = data_size;
    printf("Queue initialized!\n");
    return q;
}

/**
 * @brief A função `queue_enqueue` faz o cálculo do endereço de memória.
 * Como `q->data` é um pointeiro genérico `void *` é necessário casting com `char *`.
 * `q->rear * q->data_size` calcula o deslocamento a partir do início do array.
 * Por fim, `memcpy` copia os dados `d` para o destino `dest` e especifica o tamanho do 
 * dado `q->data_size`.
 * 
 * @example Se tratando de uma fila homogênea, onde todos os `data_size` possuem 4 bytes
 * se o rear for 2, ou seja, a posição desejada. O `(char *)q->data` é o endereço inicial 
 * da fila.
 * Nesse caso, então, 0x7f (posição inicial) + 8 (2*4, posição desejada + tamanho de cada elemento).
 */
int queue_enqueue(circular_queue_t * q, const void *d) {
    if (q == NULL || d == NULL) {
        return 1;
    }
    if (q->size == q->capacity) {
        return 1;
    }
    void * dest = (char *)q->data + q->rear * q->data_size;
    memcpy(dest, d, q->data_size);
    q->size++;
    q->rear = (q->rear+1)%q->capacity;
    return 0;
}

int queue_dequeue(circular_queue_t * q, void *d) {
    if (q == NULL | d == NULL) {
        return 1;
    }
    if (q->size == 0) {
        return 1;
    }
    void * dest = (char *)q->data + q->front * q->data_size;
    memcpy(d, dest, q->data_size);
    q->size--;
    q->front = (q->front+1)%q->capacity;

    /**
     * 0   1   2   3   4   5   6
     * 0   0   7   0   0   0   0
     * 0 (front) | 2 (rear) | size == 3 | capacity == 7
     * 
     * 0   1   2   3   4   5   6
     * 0   0  10   5   0   0   0
     *     2 (front) | 3 (rear) | size == 1 | capacity == 7
     * 
     */
}

void queue_destroy(circular_queue_t * q) {
    if (q == NULL) {
        return;
    }
    free(q->data);
    free(q);
}

void queue_print(circular_queue_t * q) {
    if (q == NULL) {
        return;
    }
    if (q->size == 0) {
        printf("[]");
        return;
    }
    printf("[");
    for (int i = 0; i < q->size; i++) {
        int idx = (q->front + i) % q->capacity;
        int v;
        memcpy(&v, (char*)q->data + idx*q->data_size, q->data_size);
        if (i > 0){
            printf(", ");
        }
        printf("%d", v);
    }
    printf("]\n");
}

void main () {
    circular_queue_t * q_int = queue_init(7, sizeof(int));
    int a = 5, b = 17, c = 29;
    queue_enqueue(q_int, &a);
    queue_enqueue(q_int, &b);
    queue_enqueue(q_int, &c);
    int v;
    queue_dequeue(q_int, &v);
    queue_dequeue(q_int, &v);
    queue_dequeue(q_int, &v);
    queue_enqueue(q_int, &c);
    queue_enqueue(q_int, &b);
    queue_enqueue(q_int, &a);
    queue_dequeue(q_int, &v);
    queue_dequeue(q_int, &v);
    queue_enqueue(q_int, &c);
    queue_print(q_int);
    return;
}