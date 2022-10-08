/*
Crie um programa que implemente o jogo “Bingo de Prog II”. Nesse jogo, o jogador deve
selecionar a quantidade de números que ele gostaria de apostar (entre 1 e 20), e em
seguida, informar os números escolhidos (valores entre 0 e 100). Após receber a aposta, o
computador sorteia 20 números (entre 0 e 100) e compara os números sorteados com os
números apostados, informando ao apostador a quantidade de acertos e os números que
ele acertou.
O seu programa deverá implementar as funções ler_aposta, sorteia_valores e
compara_aposta.
MAIS INFORMACOES EM: https://edirlei.com/aulas/prog2_2014_2/ListaExercicios02.pdf
*/

#include <stdlib.h> 
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define SUCESSO 0
#define NUMEROS_SORTEADOS 20
#define VALOR_MAXIMO_APOSTA 100
#define VALOR_MINIMO_APOSTA 0

void ler_aposta(int qtdeApostada, int* aposta) //Procedimento responsavel por ler os numeros que o jogador quer apostar
{
    int i;

    for (i = 0; i < qtdeApostada; i++)
    {
        do
        {
            printf("Digite o %io valor entre 1 e 100 a ser apostado: ", i + 1);
            scanf("%i", &aposta[i]);
        } while (aposta[i]<VALOR_MINIMO_APOSTA || aposta[i]>VALOR_MAXIMO_APOSTA);
    }
}
void sorteia_valores(int* sorteio) //Procedimento responsavel por sortear os 20 valores aleatoriamente
{
    int valorSorteado, i;

    srand(time(NULL));
    for (i = 0; i < NUMEROS_SORTEADOS; i++)
    {
        valorSorteado = rand() % 100; //valorSorteado vai receber um numero de 0 a 100
        sorteio[i] = valorSorteado;
        //printf("%i ", sorteio[i]);
    }

}
int* compara_aposta(int* aposta, int* sorteio, int qtdeApostada) //Procedimento responsável por comparar os numeros apostados com os sorteados e definir a quantidade de acertos e quais foram eles
{
    int i, j, k = 0, acertos = 0, * vetorAcertos;

    vetorAcertos = (int*)malloc((NUMEROS_SORTEADOS + 1) * sizeof(int));

    for (i = 0; i < NUMEROS_SORTEADOS; i++)
    {
        for (j = 0; j < qtdeApostada; j++)
        {
            if (aposta[j] == sorteio[i])
            {
                acertos++;
            }
        }
    }

    vetorAcertos[k] = acertos;
    k++;

    //printf("*teste acertos*: %i ", *qtdAcertos);

    for (i = 0; i < NUMEROS_SORTEADOS; i++)
    {
        for (j = 0; j < qtdeApostada; j++)
        {
            if (aposta[j] == sorteio[i])
            {
                vetorAcertos[k] = aposta[j];
                //printf("*teste vetor acertos*: %i ", vetorAcertos[k]);
                k++;
            }
        }
    }

    return(vetorAcertos);
}
void imprimeResultado(int* totalAcertos) //Procedimento responsável imprimir quantos e quais foram os numeros acertados, caso haja
{
    int i, k = 0;

    //printf("*teste total acertos*: %i ", totalAcertos[0]);

    if (totalAcertos[k] != 0)
    {
        printf("Parabens! Houve %i acertos e os numeros acertados foram: ", totalAcertos[k]);
        for (i = 0; i < totalAcertos[k]; i++)
        {
            printf("%i  ", totalAcertos[i + 1]);
        }
    }
    else if (totalAcertos[k] == 0)
    {
        printf("Que pena! Nao houve acertos desta vez. Quem sabe na proxima? ;)");
    }

}

int main(int argc, char** argv)
{
    int qtdeApostada = 0, * aposta, * sorteio, * totalAcertos, i;
    do
    {
        printf("Ola, jogador! Voce deseja apostar quantos numeros entre 1 e 20?: ");
        scanf("%i", &qtdeApostada);
    } while (qtdeApostada <= 0 || qtdeApostada >= 21);

    aposta = (int*)malloc(qtdeApostada * sizeof(int));
    sorteio = (int*)malloc(NUMEROS_SORTEADOS * sizeof(int));

    sorteia_valores(sorteio);
    ler_aposta(qtdeApostada, aposta);
    
    totalAcertos = compara_aposta(aposta, sorteio, qtdeApostada);

    imprimeResultado(totalAcertos);

    printf("\n");

    free(aposta);
    free(sorteio);
    free(totalAcertos);
    return SUCESSO;
}