#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define SUCESSO 0
#define TAM_MAX_EXP 50

int main(){

	Stack *s = stack_create();
	int r;
    char string[TAM_MAX_EXP];

    printf("\n\n\n\n");

    printf("Digite a expressão a ser avaliada: ");
    fgets(string, TAM_MAX_EXP, stdin);

    r = ver_exp(string);
    if(r == 0){
        printf("\nSua expressão está bem formada.");
    }else{
        printf("\nSua expressão está mal formada.");

    }

    printf("\n\n\n\n");

	free_stack(s);
	
	return SUCESSO;
}

