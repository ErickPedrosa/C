#include <stdio.h>
#include <stdlib.h>

#define ERRO_1 -1
#define SUCESSO 0


//Implementações de estruturas de lista;
typedef struct list {

    int info ;
    struct list *next ;

} List ;

//Implementações de estruturas de pilha;
typedef struct stack {
    List *first ;
} Stack;

//Implementações de estruturas de fila;
typedef struct queue{
	List *fst;
	List *end;
}Queue;

//Implementações de estruturas dos arquivos;
typedef struct input{
    int n;
    int *comando;
    int *x;
} Input;

//Implementações de pilha;
Stack* stack_create();
void stack_push(Stack *st, int c);
int stack_pop(Stack *st);
int void_stack(Stack *st);
void free_stack(Stack *st);


//Implementações de fila;
Queue *queue_create();
void queue_push(Queue *q, int x);
int queue_pop(Queue *q);
int void_queue(Queue *q);
void free_queue(Queue *q);


//Implementações de fila de prioridade;
Queue *queue_create_p();
void queue_push_p(Queue *q, int x);
int queue_pop_p(Queue *q);
int void_queue_p(Queue *q);
void free_queue_p(Queue *q);


//Implementações de arquivos, entradas e saídas;
void input_file(void);
void output_file(char* s, char mode);
Input *ipt_var(int file_size);
int fsize(void);
