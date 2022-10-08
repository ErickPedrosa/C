#include "estruturas.h"


//Implementações de funções de pilhas;
Stack* stack_create(){

    Stack *s = (Stack*) malloc (sizeof(Stack));
    s->first = NULL;
    return  s;

}
void stack_push(Stack *st, int c){

    List *l = (List*)malloc(sizeof(Stack));
    l->info = c;
    l->next = st->first;
    st->first = l;

}
int stack_pop(Stack *st){

    List *l;
    char c;

    if (void_stack(st))
    {
        printf("Pilha vazia");
        return(ERRO_1);
    }
    
    l = st->first;
    c = l->info;
    st->first = l->next;

    free(l);

    return(c);
}
int void_stack(Stack *st){

    return(st->first == NULL);
}
void free_stack(Stack *st){

    List *l = st->first;
    while(l != NULL){
        List *buffer = l->next;
        free(l);
        l = buffer;

    }

    free(st);
}

//Implementações de funções de filas;
Queue *queue_create(){
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->fst = q->end = NULL;
    return q;
}
void queue_push(Queue *q, int x){
    List *l = (List *) malloc(sizeof(List));
    
    l->info = x;
    l->next = NULL;
    if(q->end != NULL) q->end->next = l;
    else q->fst = l;
    q->end = l;

}
int queue_pop(Queue *q){
    List *l;
    int x;
    if(void_queue(q)){
        printf("Fila vazia");
        return(ERRO_1);
    }
    l = q->fst;
    x = l->info;
    q->fst = l->next;
    if(q->fst == NULL) q->end = NULL;
    free(l);
    return x;

}
int void_queue(Queue *q){
    return (q->fst == NULL);
}
void free_queue(Queue *q){
    List *l = q->fst;
    while (l!=NULL)
    {
        List *t = l->next;
        free(l);
        l = t;
    }
    free(q);
}

//Implementações de funções de filas de prioridade;
Queue *queue_create_p(){
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->fst = q->end = NULL;
    return q;
}
void queue_push_p(Queue *q, int x){
    List *l = (List *) malloc(sizeof(List)), *b = q->fst;
    
    l->info = x;
    l->next = NULL;


    if(q->end != NULL) {
 
        if (l->info > b->info)
        {
            l->next = q->fst;
            q->fst = l;
        }else{
        
            while(b->next != NULL && l->info < b->next->info){
                b = b->next;
            }

            if(b->next == NULL){
                b->next = l;
                q->end = l;
            }else{
                l->next = b->next;
                b->next = l;
        }
        }

        
    }
    else {
        q->fst = l;
        q->end = l;
    }

}
int queue_pop_p(Queue *q){
    List *l;
    int x;
    if(void_queue(q)){
        printf("Fila vazia");
        return(ERRO_1);
    }
    l = q->fst;
    x = l->info;
    q->fst = l->next;
    if(q->fst == NULL) q->end = NULL;
    free(l);
    return x;

}
int void_queue_p(Queue *q){
    return (q->fst == NULL);
}
void free_queue_p(Queue *q){
    List *l = q->fst;
    while (l!=NULL)
    {
        List *t = l->next;
        free(l);
        l = t;
    }
    free(q);
}

