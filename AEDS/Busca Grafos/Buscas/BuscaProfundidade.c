#include "estruturas.h"

List* busca_profundidade(Grafos_mat* grafo, int inicio, List* visitados) {
	if (lst_busca(visitados, inicio) == NULL) {

		if (visitados == NULL) {
			visitados = lst_cria();
		}


		visitados = lst_insere(visitados, inicio);

		for (int i = 0; i < grafo->vert; i++) {
			if (grafo->adj[inicio][i] == 1)
			{
				// Verifica se o vertice já foi visitado;
				if (lst_busca(visitados, i) == NULL) {
					visitados = busca_profundidade(grafo, i, visitados);
				}

			}
		}

		return(visitados);

	}
}