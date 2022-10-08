/*#include "estruturas.h"

//Implementações de funções de filas;
Queue* queue_create() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->fst = q->end = NULL;
    return q;
}
void queue_push(Queue* q, int x) {
    List* l = (List*)malloc(sizeof(List));

    l->info = x;
    l->next = NULL;
    if (q->end != NULL) q->end->next = l;
    else q->fst = l;
    q->end = l;

}
int queue_pop(Queue* q) {
    List* l;
    int x;
    if (void_queue(q)) {
        printf("Fila vazia");
        return(ERRO_1);
    }
    l = q->fst;
    x = l->info;
    q->fst = l->next;
    if (q->fst == NULL) q->end = NULL;
    free(l);
    return x;

}
int void_queue(Queue* q) {
    return (q->fst == NULL);
}
void free_queue(Queue* q) {
    List* l = q->fst;
    while (l != NULL)
    {
        List* t = l->next;
        free(l);
        l = t;
    }
    free(q);
}*/