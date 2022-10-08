#include "arvore.h"

void arv_insere(Arv* r, Arv* a, Arv *ant){
	if(!arv_vazia(r)){
		if(a->info <= r->info){
			arv_insere(r->esq, a, r);
		}else {
			arv_insere(r->dir, a, r);
		}
	}else{
		if(a->info <= ant->info){
			ant->esq=a;
		}else{ 
			ant->dir=a;
		}
	}
}