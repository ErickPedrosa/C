#include <stdio.h>
#include <stdlib.h>

#define NUM_MAX_VAG (24 + 1)

typedef struct stack {
    int n;
    char vet[NUM_MAX_VAG];

} Stack;

Stack* stack_create();
void stack_push(Stack *st, char c);
char stack_pop(Stack *st);
int void_stack(Stack *st);
void free_stack(Stack *st);
void print_stack(Stack *st);
