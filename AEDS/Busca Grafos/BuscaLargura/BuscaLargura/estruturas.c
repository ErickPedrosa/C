#include "estruturas.h"

FilaL* fila_cria_l() {
	FilaL* f = (FilaL*)malloc(sizeof(FilaL));
	f->ini = f->fim = NULL;
	return f;
}

void fila_insere_l(FilaL* f, int* x) {
	Lista* n = (Lista*)malloc(sizeof(Lista));
	n->info = x;
	n->prox = NULL;
	if (f->fim != NULL) f->fim->prox = n;
	else f->ini = n;
	f->fim = n;

}

int* fila_retira_l(FilaL* f) {
	Lista* t;
	int* v;
	if (fila_vazia_l(f)) {
		printf("Fila vazia!");
		exit(1);
	}
	t = f->ini;
	v = t->info;
	f->ini = t->prox;
	if (f->ini == NULL) f->fim = NULL;
	free(t);
	return v;
}

int fila_vazia_l(FilaL* f) {
	return (f->ini == NULL);
}

void fila_libera_l(FilaL* f) {
	Lista* q = f->ini;
	while (q != NULL) {
		Lista* t = q->prox;
		free(q);
		q = t;
	}
	free(f);
}

Lista* fila_busca_l(FilaL* fila, int informacao[]) {
	Lista* q;
	for (q = fila->ini; q != NULL; q = q->prox) {
		if (strcmp(informacao, q->info) == 0) {
			return q;
		}
	}
	return NULL;
}

// Funções de impressão

void fila_imprime_l(FilaL* f) {
	Lista* q;
	for (q = f->ini; q != NULL; q = q->prox) printf("\t%s\n", q->info);
}





















Lista* lst_cria() {
	return NULL;
}

Lista* lst_insere(Lista* l, int i) {
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	return novo;
}

void lst_imprime(Lista* l) {
	Lista* p;
	for (p = l; p != NULL; p = p->prox) {
		printf("%d  ", p->info);
	}
}

int lst_vazia(Lista* l) {
	if (l == NULL)
		return 1;

	else
		return 0;
}

Lista* lst_busca(Lista* l, int v) {
	Lista* p;
	for (p = l; p != NULL; p = p->prox) {
		if (p->info == v) {
			return p;
		}
	}
	if (p == NULL) {
		
		return NULL;
	}
}

Lista* lst_retira(Lista* l, int v) {
	Lista* p = l;
	Lista* ant = NULL;
	while (p != NULL && p->info != v) {
		ant = p;
		p = p->prox;
	}
	if (p == NULL) {
		printf("Elemento não encontrado\n");
		return l;
	}
	if (ant == NULL) {
		l = p->prox;
	}
	else {
		ant->prox = p->prox;
	}
	free(p);
	return l;
}

void lst_libera(Lista* l) {
	Lista* p = l;
	while (p != NULL) {
		Lista* t = p->prox;
		free(p);
		p = t;
	}
}



