#include "arvore.h"

arv_count arv_leaf_counter(Arv *r, arv_count n){
	
	int child = 0;

	if(r->esq != NULL){
		child += 1;
		n = arv_leaf_counter(r->esq, n);
	}
	if(r->dir != NULL){
		child += 1;
		n = arv_leaf_counter(r->dir, n);
	}

	if(child == 0){
		n.folhas++;
	}else if(child == 1){
		n.nos_unicos++;
	}else if(child == 2){
		n.nos_duplos++;
	}

	return n;
}