#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"

/*Funcoes de List encadeada*/

List* lst_cria() {
	return NULL;
}

List* lst_insere(List* l, int i) {
	List* novo = (List*)malloc(sizeof(List));
	novo->info = i;
	novo->next = l;
	return novo;
}

void lst_imprime(List* l) {
	List* p;
	for (p = l; p != NULL; p = p->next) {
		printf("- %d ", p->info);
	}
}

int lst_vazia(List* l) {
	if (l == NULL)
		return 1;

	else
		return 0;
}

List* lst_busca(List* l, int v) {
	List* p;
	for (p = l; p != NULL; p = p->next) {
		if (p->info == v) {
			return p;
		}
	}
	if (p == NULL) {

		return NULL;
	}
}

List* lst_retira(List* l, int v) {
	List* p = l;
	List* ant = NULL;
	while (p != NULL && p->info != v) {
		ant = p;
		p = p->next;
	}
	if (p == NULL) {
		printf("Elemento não encontrado\n");
		return l;
	}
	if (ant == NULL) {
		l = p->next;
	}
	else {
		ant->next = p->next;
	}
	free(p);
	return l;
}

void lst_libera(List* l) {
	List* p = l;
	while (p != NULL) {
		List* t = p->next;
		free(p);
		p = t;
	}
}

List* lst_insere_ordenado(List* l, int v) {
	List* novo;
	novo = (List*)malloc(sizeof(List));
	novo->info = v;
	List* ant = NULL;
	List* p = l;
	while (p != NULL && p->info < v) {
		ant = p;
		p = p->next;
	}
	if (ant == NULL) {
		novo->next = l;
		return novo;
	}
	else {
		ant->next = novo;
		novo->next = p;
		return l;
	}
}

int lst_igual(List* l1, List* l2) {
	List* p1;
	List* p2;
	int tam1 = 0, tam2 = 0;
	for (p1 = l1; p1 != NULL; p1 = p1->next) {
		tam1++;
	}
	for (p2 = l2; p2 != NULL; p2 = p2->next) {
		tam2++;
	}
	p1 = l1;
	p2 = l2;
	if (tam1 != tam2) {
		return 0; //diferente
	}
	else {
		while (p1 != NULL) {
			if (p1->info == p2->info) {
				p1 = p1->next;
				p2 = p2->next;
			}
			else return 0;
		}
	}
	return 1; //igual
}