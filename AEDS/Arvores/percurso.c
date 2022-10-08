#include "arvore.h"


void print_arv_pre(Arv* a){
	if(!arv_vazia(a)){
		printf("%c\t",a->info);
		print_arv_pre(a->esq);
		print_arv_pre(a->dir);
	}
}
void print_arv_sim(Arv* a){
    if(!arv_vazia(a)){
        print_arv_sim(a->esq);
        printf("%c\t",a->info);
        print_arv_sim(a->dir);
    }
}
void print_arv_pos(Arv* a){
    if(!arv_vazia(a)){
        print_arv_pos(a->esq);
        print_arv_pos(a->dir);
        printf("%c\t",a->info);
    }
}