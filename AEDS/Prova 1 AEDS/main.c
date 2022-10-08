/*
* Integrantes da dupla: Erick Pedrosa e Gabriele Maia;
* Turma: 203;
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define SUCESSO 0
#define NUM_MAX_VAG (24 + 1)

int main(int argc, char **argv)
{
    int n, i, j = 0, x = 0, y = 0;
    char c, str[NUM_MAX_VAG], buf[NUM_MAX_VAG];
    Stack *s = stack_create(), *s2 = stack_create();

    printf("\nDigite o número de vagões: ");
    scanf("%i", &n);
    

    printf("\nDigite a sequência de vagões de entrada: \nObs: A sequência deverá ser digitada um caractere por vez ou todos separados por espaço.\n");
    for(i = 0; i < n; i++){
        getchar();
        scanf("%c", &c);
        buf[i] = c;
    }

    for(i = n - 1; i >= 0; i--){
        stack_push(s, buf[i]);
    }

    
    printf("\nDigite a sequência de vagões da saída: \nObs: A sequência deverá ser digitada um caractere por vez ou todos separados por espaço.\n");
    for(i = 0; i < n; i++){
        getchar();
        scanf("%c", &c);
        str[i] = c;
    }

    printf("\n\n");

    while( x <= (NUM_MAX_VAG * 2) ){

        if(void_stack(s) && y == 0){
            if(!void_stack(s2)){
                if(s2->vet[s2->n - 1] != str[j]){
                    printf(" Impossible ");
                    y = 1;
                }
            }
        }

        if (!void_stack(s))
        {
            stack_push(s2, stack_pop(s));
            printf("I");
        }

        if (!void_stack(s2)) {

            if(s2->vet[s2->n - 1] == str[j]){
            stack_pop(s2);
            printf("R");
            j++;
            }
        }

        x++;
    }
    
    printf("\n\n");

    free_stack(s);
    free_stack(s2);

    return SUCESSO;
}
