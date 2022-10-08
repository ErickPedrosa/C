#include <stdio.h>
#include "estruturas.h"



int main() {

	List* l;
	Grafos_mat* g = aloca_grafo_m(9);

	insere_arco_m(g, 0, 1);
	insere_arco_m(g, 0, 5);
	insere_arco_m(g, 1, 6);
	insere_arco_m(g, 1, 2);
	insere_arco_m(g, 5, 6);
	insere_arco_m(g, 2, 3);
	insere_arco_m(g, 2, 4);
	insere_arco_m(g, 4, 8);
	insere_arco_m(g, 8, 7);
	insere_arco_m(g, 6, 7);

	l = busca_largura(g, 0, NULL, NULL);
	printf("Percurso da busca em largura: ");
	lst_imprime(l);

	l = busca_profundidade(g, 0, NULL);
	printf("\nPercurso da busca em profundidade: ");
	lst_imprime(l);

	return 0;
}