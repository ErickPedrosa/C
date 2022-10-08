#define SUCESSO 0

#include "listas.h"
#include <stdio.h>


int lst_compara(Lista* lst1, Lista* lst2);
void lcirc_Josephus(Lista* lst);

int main(int argc, char **argv)
{


    int n;
    Lista *lst, *lst2;

    lst = lst_cria();

    for(int i = 1; i <= 41; i++){
        lst = lst_insere(lst, i);

    }
    
    lst2 = lst_cria();
    lst2 = lst_insere(lst2, 5);
    lst2 = lst_insere(lst2, 4);
    lst2 = lst_insere(lst2, 3);
    lst2 = lst_insere(lst2, 2);
    lst2 = lst_insere(lst2, 1);

    n = lst_compara(lst, lst2);

    if(n == 0){
        printf("\nAs listas são iguais\n");
    }else{
        printf("\nAs listas são diferentes\n");
    }    


    lst = lcirc_transforma(lst);

    lcirc_Josephus(lst);


    return SUCESSO;
}



int lst_compara(Lista* lst1, Lista* lst2){

	int tam1, tam2;
	Lista* comp1, *comp2;

	for(comp1 = lst1;comp1 != NULL;comp1 = comp1->prox)
	{
		
		if(comp1 == NULL && comp2 != NULL || comp1 != NULL && comp2 == NULL){
			return 1;
		}

		if(comp1->info != comp2->info){
			return 1;
		}
		
		comp2 = comp2->prox;
	}
	return 0;
	
}

void lcirc_Josephus(Lista* lst){

    int i;
    Lista *p;

    while(lst != lst->prox){

        for(i = 1; i < 3; i++){
            lst = lst->prox;
        }

        printf("%d ", lst->prox->info);
        lst->prox = lst->prox->prox;
        lst = lst->prox;
        
    }

    printf("\nJosephus estava no %dº lugar\n", lst->info);

}
