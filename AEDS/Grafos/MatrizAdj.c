#include "Grafos.h"


Grafos_mat* aloca_grafo_m (Vertice tam){
    Grafos_mat *mat;

    mat = (Grafos_mat*)malloc(sizeof(Grafos_mat));

    mat[0].adj = (Bool**)malloc(sizeof(Bool*) * tam);
    for (int i = 0; i < tam; i++){
        mat[0].adj[i] = (Bool*)malloc(sizeof(Bool) * tam);
    }

    mat[0].arcos = 0;
    mat[0].vert = tam;

    return mat;
}
void libera_grafo_m (Grafos_mat* mat){

    for (int i = 0; i < mat->vert; i++){
        free(mat[0].adj[i]);
    }
    free(mat[0].adj);
    free(mat);

}
void insere_arco_m(Grafos_mat* mat, Vertice origem, Vertice destino){

    mat[0].adj[origem][destino] = 1;
    mat[0].arcos++;

}
void retira_arco_m(Grafos_mat* mat, Vertice origem, Vertice destino){

    mat[0].adj[origem][destino] = 0;
    mat[0].arcos--;
    
}
void imprime_matriz(Grafos_mat* mat){
    printf("\nMatriz de Adjacências\n");
    printf("\t");
    for(int i = 0; i < mat->vert; i++){
        printf("%i\t", i);
    }
    printf("\n");

    for(int j = 0; j < mat->vert; j++){
        printf("%i\t", j);
        for(int k = 0; k < mat->vert; k++){
            printf("%i\t", mat[0].adj[j][k]);
        }
        printf("\n");
    }
}
int* calc_graus_m(Grafos_mat* mat){
    int* graus = (int *) malloc(sizeof(int) * mat->vert);

    for(int i = 0; i < mat->vert; i++){
        for(int j = 0; j < mat->vert; j++){
            graus[i] += mat[0].adj[j][i];
        }
    }

    return graus;
}
void imprime_graus_m(int *graus, int tam){

    printf("\nVert.\tGrau\n");
    
    for(int i = 0; i < tam; i++){
        printf("%i\t%i", i, graus[i]);
        
        printf("\n");

    }

}


