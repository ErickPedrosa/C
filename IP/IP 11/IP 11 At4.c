/*Criador: Erick Pedrosa Barreto
 *Data: 19/08/2021
 *Descrição: Esse programa lê a quantidade de um total de 5
produtos que uma empresa tem em suas 7 lojas e imprime em uma
tabela:
a) o total de cada produto nestas lojas
b) a loja que tem menos produtos;
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SUCESSO 0

#define N_LOJA 7
#define N_PRODUTO 5

#define TAM_LINHA 97
#define MAX_TAM_INT 2147483647
#define TAMANHO_MAX_PRODUTO (100 + 1)

typedef unsigned int contadores;

//Protótipo das funções;
void somaTotal(int[][N_PRODUTO], int [N_LOJA]);
void linha(int);
void imprimeMenor(int[N_LOJA]);

int main(int argc, char** argv) {

	//Declaração das variáveis;
	int produtosPorLoja[N_LOJA][N_PRODUTO], resultadoSoma[N_LOJA];
	char nomeProduto[N_PRODUTO][TAMANHO_MAX_PRODUTO]{ {'a','b'}, {'c','d'}};
	contadores i, j, k, l, m, n;


	//Leitura das informações;
	for (k = 0; k < N_PRODUTO; k++) {
		printf("\nDigite o nome do produto numero %i(Mais de seis digitos desconfigura a tabela):", k+1);
		scanf("%s", &nomeProduto[k]);
	}

	for (i = 0; i < N_LOJA; i++) {
		for (j = 0; j < N_PRODUTO; j++) {
			printf("\nDigite a quantidade de %s na loja %i(Mais de cinco digitos desconfigura a tabela):", nomeProduto[j], i+1 );
			scanf("%i", &produtosPorLoja[i][j]);
		}
	}
	

	//Impressão da tabela;
	printf("\n");
	linha(TAM_LINHA);
	printf("\n RELATORIO DE PRODUTOS\n");
	linha(TAM_LINHA);

	printf("\n\n");
	linha(TAM_LINHA);
	printf("\n%cN. loja \t%c", '*', '*');

	for (n = 0; n < N_PRODUTO; n++) {
		printf("N. de %s\t%c  ", nomeProduto[n], '*');
	}
	printf("\n");
	linha(TAM_LINHA);
	printf("\n");


	for (l = 0; l < N_LOJA; l++) {
		linha(TAM_LINHA);
		printf("\n%cLoja %i  \t%c", '*', l + 1, '*');

		for (m = 0; m < N_PRODUTO; m++) {
			printf(" %i\t\t%c", produtosPorLoja[l][m], '*');
		}
		printf("\n");
		linha(TAM_LINHA);
		printf("\n");
	}

	//Chamada da função soma;
	somaTotal(produtosPorLoja, resultadoSoma);
	imprimeMenor(resultadoSoma);

	return SUCESSO;
}

//Função que imprime uma linha de asteriscos;
void linha(int N_da_linha) {
	contadores a;

	for (a = 1; a <= N_da_linha; a++)
	{
		putchar('*');
	}
}


//Função que faz a soma dos produtos e coloca o resultado em um vetor;
void somaTotal(int matriz[][N_PRODUTO], int destinoResultado[N_LOJA]) {
	contadores b, c, d;

	for (c = 0; c < N_LOJA; c++) {
		destinoResultado[c] = { 0 };
	}

	for (b = 0; b < N_LOJA; b++) {
		for (d = 0; d < N_PRODUTO; d++)
			destinoResultado[b] += matriz[b][d];
	}

	return;
}

//Função que imprime o menor numero do vetor e sua correspondente loja;
void imprimeMenor(int vetor[N_LOJA]) {
	int menor = MAX_TAM_INT, indiceLojaMenor = 0;
	contadores f;

	
	for (f = 0; f < N_LOJA; f++) {
		if (vetor[f] < menor){
			menor = vetor[f];
			indiceLojaMenor = f + 1;
		}

	}
	printf("A loja com menor quantidade de produtos eh a loja %i com %i produtos no total.\n", indiceLojaMenor, menor);
	linha(TAM_LINHA);

	return;
}