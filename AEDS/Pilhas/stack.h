#include <stdio.h>
#include <stdlib.h>

#define ERRO_1 1


typedef struct list {

    char info ;
    struct list *next ;

} List ;

typedef struct stack {
    List *first ;

} Stack;

Stack* stack_create();
void stack_push(Stack *st, char c);
char stack_pop(Stack *st);
int void_stack(Stack *st);
void free_stack(Stack *st);
void print_stack(Stack *st);

int ver_exp(char* string);
