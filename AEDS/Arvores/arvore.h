#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define NUM_MAX_ASCII 128

//ARVORE BINARIA
struct arv{
	char info;
	struct arv *esq;
	struct arv *dir;
};

typedef struct arv_counter{
	int folhas;
	int nos_unicos;
	int nos_duplos;
} arv_count;

typedef struct histograma_s{
	char c[NUM_MAX_ASCII];
	int n[NUM_MAX_ASCII];
	int x;
} Hist;

typedef struct arv Arv;

Arv* arv_criavazia(void);
Arv* arv_cria(char valor,Arv* esq,Arv* dir);
Arv* arv_libera(Arv* a);
int arv_vazia(Arv* a);
int arv_pertence(Arv* a,char v);
void arv_imprime_preordem(Arv* a);
void arv_imprime_simetrica(Arv* a);
void arv_imprime_posordem(Arv* a);


static int max2(int a,int b);
int arv_altura(Arv *a);

//ARVORE COM FILHOS VARIADOS

struct arvvar{
	int info;
	struct arvvar *filho;
	struct arvvar *irmao;
};

typedef struct arvvar ArvVar;

ArvVar *arvv_cria(int v);
void arvv_insere(ArvVar *r,ArvVar *inserido);
void arvv_imprime(ArvVar *a);
int arvv_pertence(ArvVar *a,int v);
void arvv_libera(ArvVar *a);
int arvv_altura(ArvVar *a);

//Funções de impressão;
void print_arv_pre(Arv* a);
void print_arv_sim(Arv* a);
void print_arv_pos(Arv* a);

//Função de inserção;
void arv_insere(Arv* r, Arv* a, Arv* ant);

//Função para contar as folhas e os nós;
arv_count arv_leaf_counter(Arv *r, arv_count n); 

//Função para criar e imprimir o histograma;
Hist arv_hist(Arv *r, Hist h);
void print_hist(Hist h);

