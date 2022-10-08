#include "Grafos.h"

int main(int argc, char **argv)
{
    Grafos_mat *grafo_m;
    Grafos_mat *grafo_f;
    Grafos_lst *grafo_l;
    Vertice tam = 5;
    int erro;



    //Teste Matriz Adj
    grafo_m = aloca_grafo_m(tam);
    insere_arco_m(grafo_m, 0, 2);
    insere_arco_m(grafo_m, 0, 3);
    insere_arco_m(grafo_m, 2, 3);
    insere_arco_m(grafo_m, 1, 0);
    insere_arco_m(grafo_m, 3, 0);

    imprime_matriz(grafo_m);

    int *graus = calc_graus_m(grafo_m);

    imprime_graus_m(graus, tam);


    //Teste Lista Adj
    grafo_l = aloca_grafo_l(tam);
    insere_arco_l(grafo_l, 0, 2);
    insere_arco_l(grafo_l, 0, 3);
    insere_arco_l(grafo_l, 2, 3);
    insere_arco_l(grafo_l, 1, 0);
    insere_arco_l(grafo_l, 3, 0);

    imprime_lista(grafo_l);

    graus = calc_graus_l(grafo_l);

    imprime_graus_l(graus, tam);

    


    //Teste "O Fabricio cansou e fugiu!"
    grafo_f = inicializa_servidores();



    //ERRO 3
    retira_arco_f(grafo_f, 7, 69);

    erro = verifica_erro(grafo_f);
    msg_erro(erro);



    //ERRO 2
    retira_arco_f(grafo_f, 7, 0);

    erro = verifica_erro(grafo_f);
    msg_erro(erro);



    //ERRO 1
    retira_arco_f(grafo_f, 7, 1);
    retira_arco_f(grafo_f, 7, 2);
    retira_arco_f(grafo_f, 7, 3);
    retira_arco_f(grafo_f, 7, 4);
    retira_arco_f(grafo_f, 7, 5);
    retira_arco_f(grafo_f, 7, 6);
    retira_arco_f(grafo_f, 7, 7);
    retira_arco_f(grafo_f, 7, 8);
    retira_arco_f(grafo_f, 7, 9);

    erro = verifica_erro(grafo_f);
    msg_erro(erro);


    libera_grafo_f(grafo_f);
    libera_grafo_l(grafo_l);
    libera_grafo_m(grafo_m);
    return 0;
}
