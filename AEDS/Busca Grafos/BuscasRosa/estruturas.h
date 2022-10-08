#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



struct Lista {
	int info;
	struct Lista* prox;
};

typedef struct Lista Lista;

struct filal {
	Lista* ini;
	Lista* fim;
};
typedef struct filal FilaL;

struct grafos_matriz_adj {

	int vert;
	int arcos;
	int** adj;

};
typedef struct grafos_matriz_adj Grafos_mat;


Lista* lst_cria();
Lista* lst_insere(Lista* l, int i);
void lst_imprime(Lista* l);
int lst_vazia(Lista* l);
Lista* lst_busca(Lista* l, int v);
Lista* lst_retira(Lista* l, int v);
void lst_libera(Lista* l);

FilaL* fila_cria_l();
void fila_insere_l(FilaL* f, int x);
int* fila_retira_l(FilaL* f);
int fila_vazia_l(FilaL* f);
void fila_libera_l(FilaL* f);

Grafos_mat* aloca_grafo_m(int tam);
void libera_grafo_m(Grafos_mat* mat);
void insere_arco_m(Grafos_mat* mat, int origem, int destino);
void retira_arco_m(Grafos_mat* mat, int origem, int destino);
void imprime_matriz(Grafos_mat* mat);


Lista* busca_l(int** grafo, int tam, int comeco, Lista* vert_ja_vistos, FilaL* prox_a_visitar);
Lista* busca_p(int** grafo, int tam, int comeco, Lista* vert_ja_vistos);