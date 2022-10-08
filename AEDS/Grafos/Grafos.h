#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef int Vertice;
typedef uint32_t Bool;


typedef struct grafos_matriz_adj{

    Vertice vert;
    int arcos;
    Bool **adj;

}Grafos_mat;


typedef struct lista{
	Vertice info;
	struct lista *prox;
} Lista;


typedef struct grafos_lista_adj{

    Vertice vert;
    int arcos;
    Lista *lista;

}Grafos_lst;


//Exercicio 1 - Matriz de Adjacências Orientada.
Grafos_mat* aloca_grafo_m (Vertice tam);
void libera_grafo_m (Grafos_mat* mat);
void insere_arco_m(Grafos_mat* mat, Vertice origem, Vertice destino);
void retira_arco_m(Grafos_mat* mat, Vertice origem, Vertice destino);
void imprime_matriz(Grafos_mat* mat);
int* calc_graus_m(Grafos_mat* mat);
void imprime_graus_m(int *graus, int tam);


//Exercicio 2 - Lista de Adjacências Não-Orientada.
Grafos_lst* aloca_grafo_l (Vertice tam);
void libera_grafo_l (Grafos_lst* lst);
void insere_arco_l(Grafos_lst* lst, Vertice origem, Vertice destino);
void retira_arco_l(Grafos_lst* lst, Vertice origem, Vertice destino);
void imprime_lista(Grafos_lst* lst);
int* calc_graus_l(Grafos_lst* lst);
void imprime_graus_l(int *graus, int tam);

//Exercicio 3 - O Fabrício cansou e fugiu.
Grafos_mat* aloca_grafo_f (Vertice tam);
void libera_grafo_f (Grafos_mat* mat);
void insere_arco_f(Grafos_mat* mat, Vertice origem, Vertice destino);
void retira_arco_f(Grafos_mat* mat, Vertice origem, Vertice destino);
Grafos_mat* inicializa_servidores (void);
int verifica_erro(Grafos_mat* servidores);
void msg_erro(int erro);


