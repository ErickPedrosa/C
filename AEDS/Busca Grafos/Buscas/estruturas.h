#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#define ERRO_1 -1
#define SUCESSO 0


typedef int Vertice;
typedef int Bool;


//Implementações de estruturas de List;
struct list {

    int info;
    struct list* next;

};
typedef struct list List;


//Implementações de estruturas de fila;
struct queue {
    List* fst;
    List* end;
};

//Implementações de estruturas de grafo;
struct grafos_matriz_adj {

    Vertice vert;
    int arcos;
    Bool** adj;

};

typedef struct queue Queue;
typedef struct grafos_matriz_adj Grafos_mat;

/*Funcoes de List encadeada*/
List* lst_cria();
List* lst_insere(List* l, int i);
void lst_imprime(List* l);
int lst_vazia(List* l);
List* lst_busca(List* l, int v);
List* lst_retira(List* l, int v);
void lst_libera(List* l);
List* lst_insere_ordenado(List* l, int v);
int lst_igual(List* l1, List* l2);



//Implementações de fila;
Queue* queue_create();
void queue_push(Queue* q, int x);
int queue_pop(Queue* q);
int void_queue(Queue* q);
void free_queue(Queue* q);



//Grafos de Matriz de Adjacências Não-Orientada.
Grafos_mat* aloca_grafo_m(Vertice tam);
void libera_grafo_m(Grafos_mat* mat);
void insere_arco_m(Grafos_mat* mat, Vertice origem, Vertice destino);
void retira_arco_m(Grafos_mat* mat, Vertice origem, Vertice destino);
void imprime_matriz(Grafos_mat* mat);


//Função de Busca em Largura;
List* busca_largura(Grafos_mat* grafo, int inicio, List* visitados, Queue* proximos);

//Função de Busca em Profundidade;
List* busca_profundidade(Grafos_mat* grafo, int inicio, List* visitados);

