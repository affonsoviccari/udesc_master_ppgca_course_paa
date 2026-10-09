/**
 * Implementação: Fila Simplesmente Encadeada de Inteiros (FSEI)
 * Fonte: Prof. Yuri Kaszubowski Lopes 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct queue_node_s {
    int data;
    struct queue_node_s * next;
} queue_node_t;

typedef struct {
    queue_node_t * front, *rear;
    size_t size;
} queue_t;

queue_t * queue_init() {
    queue_t * q = malloc(sizeof(queue_t));
    if (q == NULL) {
        return NULL;
    }
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    printf("Queue initialized!\n");
    return q;
}

int queue_enqueue(queue_t * q, int v) {
    if (q == NULL) {
        return 1;
    }
    queue_node_t * n = malloc(sizeof(queue_node_t));
    if (n == NULL) {
        return 1;
    }
    n->data = v;
    n->next = NULL;
    if (q->rear == NULL) {
        q->front = n;
    } else {
        /**
         * Colando o novo valor como sendo o próximo valor do último node da fila.
         * Ou seja, o último node da fila (q->rear), indereça como próximo o novo node.
         * q->rear->next = n;
         */
        q->rear->next = n;
    }
    q->rear=n; // Por fim, o novo último node da fila vai ser o novo node.
    q->size++;
    return 0;
}

int queue_dequeue(queue_t * q, int * v) { 
    if (q == NULL || v == NULL) {
        return 1;
    }
    if (q->front == NULL) {
        // Fila vazia
        return 1;
    }
    queue_node_t * n = q->front; // Pego o primeiro
    *v = n->data;
    q->front = n->next; // Seto o primeiro como o próximo node (mesmo não sabendo se existe)
    if (n->next == NULL){
        q->rear = NULL; // Caso não exista o próximo, seta o rear como NULL (fila vazia)
    }
    free(n);
    q->size--;
    return 0;
}

int queue_is_empty(queue_t * q) {
    if (q==NULL | q->front==NULL){
        return 1;
    }
    return 0;
}

int queue_size(queue_t * q) {
    if (q == NULL) {
        return 0;
    }
    return q->size;
}

void queue_destroy(queue_t * q) {
    if (q == NULL) return;
    queue_node_t * n = q->front;
    while(n!=NULL){
        queue_node_t * c = n;
        n = n->next;
        free(c);
    }
    free(q);
    return;
}

void queue_print(queue_t * q) {
    if (q == NULL) {
        return;
    }
    if (q->front == NULL) {
        printf("[]\n");
        return;
    }
    queue_node_t * n = q->front;
    printf("[");
    while (n!=NULL){
        printf("%d", n->data);
        n = n->next;
        if (n!=NULL) {
            printf(", ");
        }
    }
    printf("]\n");
    return;
}

/**
 * @brief Queue (ou fila), FIFO, o primeiro elemento a entrar é o primeiro elemento a sair.
 */
void main () {
    queue_t * q = queue_init();
    queue_enqueue(q, 5);
    queue_enqueue(q, 10);
    queue_enqueue(q, 7);
    queue_print(q);
    int v;
    int ret = queue_dequeue(q, &v);
    printf("[%d] dequeued value: %d\n", ret, v);
    queue_print(q);
    ret = queue_dequeue(q, &v);
    printf("[%d] dequeued value: %d\n", ret, v);
    queue_print(q);
    ret = queue_dequeue(q, &v);
    printf("[%d] dequeued value: %d\n", ret, v);
    queue_print(q);
    ret = queue_dequeue(q, &v);
    printf("[%d] dequeued value: %d\n", ret, v);
    queue_print(q);
    
    return;
}
