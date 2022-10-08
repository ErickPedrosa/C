#include "estruturas.h"

Lista* busca_l(int** grafo, int tam, int comeco, Lista* vert_ja_vistos, FilaL* prox_a_visitar) {

	
	if (lst_busca(vert_ja_vistos, comeco) == NULL) {


		if (prox_a_visitar == NULL) {
			prox_a_visitar = fila_cria_l();
		}

		for (int i = 0; i < tam; i++) {
			if (grafo[comeco][i] == 1)
			{
				
				if (lst_busca(vert_ja_vistos, i) == NULL) {
					fila_insere_l(prox_a_visitar, i);
				}

			}
		}

		vert_ja_vistos = lst_insere(vert_ja_vistos, comeco);
		printf("O vértice %i foi visitado!\n", comeco);

		while (!fila_vazia_l(prox_a_visitar))
		{
			vert_ja_vistos = busca_l(grafo, tam, fila_retira_l(prox_a_visitar), vert_ja_vistos, prox_a_visitar);
		}
	}

	return(vert_ja_vistos);
}

Lista* busca_p(int** grafo, int tam, int comeco, Lista* vert_ja_vistos) {
	if (lst_busca(vert_ja_vistos, comeco) == NULL) {

		vert_ja_vistos = lst_insere(vert_ja_vistos, comeco);
		printf("O vértice %i foi visitado!\n", comeco);

		for (int i = 0; i < tam; i++) {
			if (grafo[comeco][i] == 1)
			{
				if (lst_busca(vert_ja_vistos, i) == NULL) {
					vert_ja_vistos = busca_p(grafo, tam, i, vert_ja_vistos);
				}

			}
		}

		return(vert_ja_vistos);

	}
}