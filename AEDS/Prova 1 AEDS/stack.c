/*
* Integrantes da dupla: Erick Pedrosa e Gabriele Maia;
* Turma: 203;
*/

#include "stack.h"

#define ERRO_1 1

Stack* stack_create(){

    Stack *s = (Stack*) malloc (sizeof(Stack));
    s->n = 0;
    return  s;

}


void stack_push(Stack *st, char c){


    if(st->n == NUM_MAX_VAG){
        printf("Capacidade da pilha estorou");
        exit(ERRO_1);

    }
    
    st->vet[st->n] = c;
    st->n++;

}


char stack_pop(Stack *st){

    char c;

    if (void_stack(st))
    {
        printf("\nPilha vazia\n");
        exit(ERRO_1);
    }
    
    c = st->vet[st->n - 1];
    st->n--;

    return(c);
}


int void_stack(Stack *st){

    return(st->n == 0);
}


void free_stack(Stack *st){
    free(st);
}


void print_stack(Stack *st){

    int i;

    for(i = st->n - 1; i >= 0; i--){
        printf("%c", st->vet[i]);

    }
}