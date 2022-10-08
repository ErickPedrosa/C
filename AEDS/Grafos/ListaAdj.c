#include "Grafos.h"


Grafos_lst* aloca_grafo_l (Vertice tam){
    Grafos_lst *lst;

    lst = (Grafos_lst*)malloc(sizeof(Grafos_lst));
    lst[0].lista = (Lista*)malloc(sizeof(Lista) * tam);

    lst[0].arcos = 0;
    lst[0].vert = tam;

    return lst;
}
void libera_grafo_l (Grafos_lst* lst){
    free(lst[0].lista);
    free(lst);
}
void insere_arco_l(Grafos_lst* lst, Vertice origem, Vertice destino){
    Lista *list = &lst->lista[origem];
    Lista *l;

    while (list->prox != NULL){
        list = list->prox;

        if(list->info == destino){
            return;
        }
    }

    l = (Lista*)malloc(sizeof(Lista));
    l->info = destino;
    l->prox = NULL;

    list->prox = l;



    list = &lst->lista[destino];

    while (list->prox != NULL){
        list = list->prox;
    }

    l = (Lista*)malloc(sizeof(Lista));
    l->info = origem;
    l->prox = NULL;

    list->prox = l;

    lst->arcos++;

    return;
}
void imprime_lista(Grafos_lst* lst){
    Lista *list;
    printf("\n");
    for(int i = 0; i < lst->vert; i++){
        printf("%i:\t", i);
        list = lst->lista[i].prox;
        while (list != NULL){
            printf("%i\t", list->info);
            list = list->prox;
        }
        printf("\n");
    }
}
int* calc_graus_l(Grafos_lst* lst){
    Lista *list;
    int *graus = (int*)malloc(sizeof(int) * lst->vert);
    
    for(int i = 0; i < lst->vert; i++){
        graus[i] = 0;

        for(list = lst->lista[i].prox; list != NULL; list = list->prox){
            graus[i]++;
        }

    }
    return graus;
}
void imprime_graus_l(int *graus, int tam){

    printf("\nVert.\tGrau\n");

    for(int i = 0; i < tam; i++){
        printf("%i\t%i", i, graus[i]);
        
        printf("\n");

    }
}





