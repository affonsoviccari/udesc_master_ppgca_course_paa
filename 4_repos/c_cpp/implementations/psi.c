/**
 * Implementação: Pilha Sequencial de Inteiros (PSI)
 * Fonte: Prof. Yuri Kaszubowski Lopes 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int capacity;
    int * data;
    size_t top; // próximo item disponível
} seq_stack_t;

seq_stack_t * stack_init(int capacity) {
    if (capacity <= 0) {
        return NULL;
    }
    seq_stack_t * s = malloc(sizeof(seq_stack_t));
    if (s == NULL) {
        return NULL;
    }
    s->data = malloc(capacity * sizeof(int));
    if (s -> data == NULL) {
        free(s);
        return NULL;
    }
    s->top = 0;
    s->capacity=capacity;
    printf("Pilha inicializada!\n");
    return s;
}

int stack_push(seq_stack_t * s, int value) {
    if (s == NULL) {
        return 1;
    }
    if (s->top == s->capacity){
        return 1;
    }
    s->data[s->top]=value;
    s->top++;
    return 0;
}

int stack_pop(seq_stack_t * s, int * value) {
    if (s == NULL) {
        return 1;
    }
    if (s -> top == 0) {
        return 1;
    }
    s->top--;
    printf("value: %d\n", s->data[s->top]);
    * value = s->data[s->top];
    s->data[s->top] = 0;
    return 0;
}

int stack_is_empty(seq_stack_t * s){
    if (s == NULL) {
        return 0;
    }
    return s->top == 0;
}

int stack_size(seq_stack_t * s){
    if (s == NULL) {
        return 0;
    }
    return s->top;
}

void stack_destroy(seq_stack_t * s) {
    if (s == NULL) {
        return;
    }
    free(s->data);
    free(s);
}

void stack_print(seq_stack_t * s){
    printf("[");
    for (int i = 0 ; i < s->capacity; i++){
        if (i > 0) {
            printf(", ");
        }
        printf("%d", s->data[i]);
    }
    printf("]\n");
}

/**
 * @brief Stack (ou Pilha), cada novo elemento é adicionado em sequência na pilha por um `stack_push`.
 * O `stack_drop` remove o primeiro elemento da pilha.
 */
void main (){
    seq_stack_t * s = stack_init(10);
    stack_push(s, 10);
    stack_push(s, 7);
    stack_push(s, 4);
    stack_push(s, 1);
    stack_print(s);
    int v;
    int ret = stack_pop(s, &v);
    printf("[%d] Value dropped: %d\n",ret, v);
    stack_print(s);
    ret = stack_pop(s, &v);
    printf("[%d] Value dropped: %d\n",ret, v);
    stack_print(s);
    ret = stack_pop(s, &v);
    printf("[%d] Value dropped: %d\n",ret, v);
    stack_print(s);
    ret = stack_pop(s, &v);
    printf("[%d] Value dropped: %d\n",ret, v);
    stack_print(s);
    ret = stack_pop(s, &v);
    printf("[%d] Value dropped: %d\n",ret, v);
    stack_print(s);
    ret = stack_pop(s, &v);
    stack_destroy(s);
    return;
}