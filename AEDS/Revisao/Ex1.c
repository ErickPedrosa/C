#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0

struct lista{
	int info;
	struct lista *prox;
};

typedef struct lista Lista;


Lista* lst_cria();
Lista* lst_insere(Lista *l, int i);
void lst_imprime(Lista *l);
Lista *lst_retira(Lista *l, int v);
void lst_libera(Lista *l);


int main(int argc, char **argv)
{
    Lista*l=lst_cria();

    lst_insere(l, 1);
    lst_insere(l, 2);
    lst_insere(l, 3);
    lst_insere(l, 4);
    lst_insere(l, 5);

    lst_imprime(l);



    return SUCESSO;
}


Lista* lst_cria(){
	return NULL;
}

Lista* lst_insere(Lista *l, int i){
	Lista *novo=(Lista *)malloc(sizeof(Lista));
	novo->info=i;
	novo->prox=l;
	return novo;
}

void lst_imprime(Lista *l){
	
    if (l->prox != NULL)
    {
        lst_imprime(l->prox);
    }
    printf("Valor: %d\n", l->info);


    return;
}

/*
Lista *p;
	for(p=l;p!=NULL;p=p->prox){
		
	}
*/

Lista *lst_retira(Lista *l, int v){
	Lista *p=l;
	Lista *ant=NULL;
	while(p!=NULL && p->info!=v){
		ant=p;
		p=p->prox;
	}
	if(p==NULL){
		printf("Elemento não encontrado\n");
		return l;
	}
	if(ant==NULL){
		l=p->prox;
	}
	else{
		ant->prox=p->prox;
	}
	free(p);
	return l;
}

void lst_libera(Lista *l){
	Lista *p=l;
	while(p!=NULL){
		Lista *t=p->prox;
		free(p);
		p=t;
	}
}