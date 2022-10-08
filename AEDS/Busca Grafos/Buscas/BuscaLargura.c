#include "estruturas.h"

List* busca_largura(Grafos_mat* grafo, int inicio, List* visitados, Queue* proximos) {

	// Verifica se o vertice já foi visitado;
	if (lst_busca(visitados, inicio) == NULL) {

		if (visitados == NULL) {
			visitados = lst_cria();
		}
		if (proximos == NULL) {
			proximos = queue_create();
		}

		for (int i = 0; i < grafo->vert; i++) {
			if (grafo->adj[inicio][i] == 1)
			{
				// Verifica se o vertice já foi visitado;
				if (lst_busca(visitados, i) == NULL) {
					queue_push(proximos, i);
				}

			}
		}

		visitados = lst_insere(visitados, inicio);

		while (!void_queue(proximos))
		{
			visitados = busca_largura(grafo, queue_pop(proximos), visitados, proximos);
		}
	}

	return(visitados);
}

