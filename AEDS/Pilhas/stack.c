#include "stack.h"

#define ERRO_1 1

Stack* stack_create(){

    Stack *s = (Stack*) malloc (sizeof(Stack));
    s->first = NULL;
    return  s;

}


void stack_push(Stack *st, char c){

    List *l = (List*)malloc(sizeof(Stack));
    l->info = c;
    l->next = st->first;
    st->first = l;

}


char stack_pop(Stack *st){

    List *l;
    char c;

    if (void_stack(st))
    {
        printf("Pilha vazia");
        exit(ERRO_1);
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


void print_stack(Stack *st){

    List *l;

    for(l = st->first; l != NULL; l = l->next){
        printf("%c", l->info);

    }
}

/*
*Função implementada para definir se uma expressão está bem formada.
*Verifica se todos os () [] e {} abertos foram fechados e se nenhum foi aberto antes de ser fechado.
*/
int ver_exp(char* string){
    int n, i, op_par = 0, op_col = 0, op_chv = 0;
    Stack *st = stack_create();

    for ( n = 0; string[n] != '\0' ; n++)
    {
        stack_push(st, string[n]);
    }
    
    for ( i = 0; i < n; i++)
    {
        char c = stack_pop(st);
        
        switch (c)
        {
        case '(':
            op_par--;
            break;

        case ')':
            op_par++;
            break;

        case '[':
            op_col--;
            break;

        case ']':
            op_col++;
            break;

        case '{':
            op_chv--;
            break;

        case '}':
            op_chv++;
            break;

        default:
            break;
        }
        
        if(op_par < 0 || op_col < 0 || op_chv < 0){
            return 1;
        }

    }
            
    
    if(op_par != 0 || op_col != 0 || op_chv != 0){
        return 1;
    }

    return 0;
}
