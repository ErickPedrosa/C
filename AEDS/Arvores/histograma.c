#include "arvore.h"

Hist arv_hist(Arv *r, Hist h){
	int oc = 0;

	if(!arv_vazia(r)){
		for(int i = 0; i < h.x; i++){
			if(r->info == h.c[i]){
				h.n[i] += 1;
				oc++;
			}
		}
		if(oc == 0){
			h.c[h.x] = r->info;
			h.n[h.x] = 1;
			h.x += 1;
		}

		h = arv_hist(r->esq, h);
		h = arv_hist(r->dir, h);
	}

	return h;
}
void print_hist(Hist h){
	printf("\n\nHistograma\n");
	for(int i = 0; i < h.x; i++){
		printf("%c\t", h.c[i]);
		printf("%i\n", h.n[i]);
	}
}