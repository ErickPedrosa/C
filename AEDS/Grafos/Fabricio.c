#include "Grafos.h"

#define NUM_SERVIDORES 10
#define NUM_PC_P_SERVIDOR 8

#define ERRO_1 -1 //Há falha de comunicação entre um servidor e todos os outros servidores.
#define ERRO_2 -2 //Há falha de comunicação entre um servidor e um outro servidor.
#define ERRO_3 -3 //Há falha de comunicação entre um servidor e uma máquina.
#define TUDO_OK 0


Grafos_mat* aloca_grafo_f (Vertice tam){
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
void libera_grafo_f (Grafos_mat* mat){

    for (int i = 0; i < mat->vert; i++){
        free(mat[0].adj[i]);
    }
    free(mat[0].adj);
    free(mat);

}
void insere_arco_f(Grafos_mat* mat, Vertice origem, Vertice destino){

    if(mat[0].adj[origem][destino] == 0 && (origem != destino)){
        mat[0].adj[origem][destino] = 1;
        mat[0].adj[destino][origem] = 1;
        mat[0].arcos++;
    }

}
void retira_arco_f(Grafos_mat* mat, Vertice origem, Vertice destino){

    if(mat[0].adj[origem][destino] == 1 && (origem != destino)){
        mat[0].adj[origem][destino] = 0;
        mat[0].adj[destino][origem] = 0;
        mat[0].arcos--;
    }
    
}
Grafos_mat* inicializa_servidores (void){
    int tamanho_grafo = (NUM_SERVIDORES + (NUM_PC_P_SERVIDOR * NUM_SERVIDORES)), x = 0;
    Grafos_mat *servidores;

    servidores = aloca_grafo_f(tamanho_grafo);

    for(int i = 0; i < NUM_SERVIDORES;i++){
        for(int j = 0; j < NUM_SERVIDORES; j++){
            insere_arco_f(servidores, i, j);
        }
    }

    for(int k = 10; k < tamanho_grafo; k++){
        
        insere_arco_f(servidores, x, k);

        if((k % 8) == (17 % 8)){
            x++;
        }
    }

    return servidores;
}
int verifica_erro(Grafos_mat* servidores){
    int x = 0, er_serv = 0;
    int erro1 = 0, erro2 = 0, erro3 = 0, peso_erro1 = 20, peso_erro2 = 2, peso_erro3 = 1; //Erros e seus determinados pesos;


    for(int i = 0; i < NUM_SERVIDORES;i++){
        er_serv = 0;
        for(int j = 0; j < NUM_SERVIDORES; j++){
            if(i != j){
                if(servidores->adj[i][j] == 0){
                    er_serv++;
                }
            }
        }
        if(er_serv == 9){
            erro1++;
        }else if(er_serv != 0){
            erro2 += er_serv;
        }
    }


    for(int k = 10; k < servidores->vert; k++){
        
        if(servidores[0].adj[x][k] == 0){
            erro3++;
        }

        if((k % 8) == (17 % 8)){
            x++;
        }
    }

    erro1 = erro1 * peso_erro1;
    erro2 = erro2 * peso_erro2;
    erro3 = erro3 * peso_erro3;
    
    if(erro1 > erro2 && erro1 > erro3){
        return ERRO_1;
    }else if(erro2 > erro1 && erro2 > erro3){
        return ERRO_2;
    }else if(erro3 > erro1 && erro3 > erro2){
        return ERRO_3;
    }else{
        return TUDO_OK;
    }

}
void msg_erro(int erro){
    if(erro == ERRO_1){
        printf("\nERRO_1: Há falha de comunicação entre um servidor e todos os outros servidores.\n");
    }else if(erro == ERRO_2){
        printf("\nERRO_2: Há falha de comunicação entre um servidor e um outro servidor.\n");
    }else if(erro == ERRO_3){
        printf("\nERRO_3: Há falha de comunicação entre um servidor e uma máquina.\n");
    }else{
        printf("\nNão há nenhum erro nos servidores!!! \n");
    }
}
