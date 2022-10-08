#include "arvore.h"


int main(int argc, char **argv)
{
    Arv *a = arv_cria('a', NULL, NULL), *b = arv_cria('b', NULL, NULL), *c = arv_cria('c', NULL, NULL), *d = arv_cria('d', NULL, NULL), *e = arv_cria('e', NULL, NULL), *f = arv_cria('f', NULL, NULL), *g = arv_cria('g', NULL, NULL);

    d->esq = b;
    d->dir = f;
    /*
       d
      b f
    */
   

    arv_insere(d, a, NULL);
    arv_insere(d, c, NULL);
    arv_insere(d, e, NULL);
    arv_insere(d, g, NULL);
    /*
        d
      b   f
     a c e g
    */
    print_arv_pre(d);


    Arv *h = arv_cria('a', NULL, NULL);
    Arv *i = arv_cria('a', NULL, NULL);
    Arv *j = arv_cria('a', NULL, NULL);
    Arv *k = arv_cria('a', NULL, NULL);
    arv_insere(d, h, NULL);
    arv_insere(d, i, NULL);
    arv_insere(d, j, NULL);
    arv_insere(d, k, NULL);
    /*
        d
      b   f
     a c e g
    a
   a
  a
 a
    4 folhas, 3 nós duplos, 4 nós simples;
    */
    printf("\n");
    print_arv_pre(d);

    arv_count n;
    n.folhas = 0;
    n.nos_duplos = 0;
    n.nos_unicos = 0;

    n = arv_leaf_counter(d, n);

    printf("\n%i\t", n.folhas);
    printf("%i\t", n.nos_duplos);
    printf("%i\n", n.nos_unicos);



    Hist hist;
    hist.x = 0;

    hist = arv_hist(d, hist);
    print_hist(hist);


    return 0;
}
