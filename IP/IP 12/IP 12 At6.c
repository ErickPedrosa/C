/*Criador: Erick Pedrosa Barreto
 *Data: 23/08/2021
 *Descrição: Esse programa lê a quantidade de um total de 5
produtos que uma empresa tem em suas 7 lojas e imprime em uma
tabela:
a) o total de cada produto nestas lojas
b) a loja que tem menos produtos;
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SUCESSO 0

#define TAM_LINHA 97
#define TAMANHO_MAX_PRODUTO (30 + 1)

typedef int counter;

//Protótipo das funções;
void somaTotal(int**, int*, int, int);
void linha(int);
void imprimeMenor(int*, int);

int main(int argc, char** argv) {

	//Declaração das variáveis;
	int** produtosPorLoja;
	int* resultadoSoma;
	int n_loja, n_produto, tam_max_produto;
	char** nomeProduto;
	counter i, j, k, l, m, n, p, q, r;


	printf("Digite o numero de lojas:");
	scanf("%i", &n_loja);

	printf("Digite o numero de produtos:");
	scanf("%i", &n_produto);

	printf("Digite o numero de letras que o maior produto tera:");
	scanf("%i", &tam_max_produto);

	//Alocando os ponteiros;
	resultadoSoma = (int*)malloc(n_loja * sizeof(int));
	if (resultadoSoma == NULL) {
		return EXIT_FAILURE;
	}

	produtosPorLoja = (int**)malloc(n_loja * sizeof(int));
	if (produtosPorLoja == NULL) {
		return EXIT_FAILURE;
	}
	for (n = 0; n < n_loja; n++) {
		produtosPorLoja[n] = (int*)malloc(n_produto * sizeof(int));
		if (produtosPorLoja[n] == NULL) {
			return EXIT_FAILURE;
		}
	}

	nomeProduto = (char**)malloc(n_produto * sizeof(char*));
	if (nomeProduto == NULL) {
		return EXIT_FAILURE;
	}
	for (p = 0; p < n_produto; p++) {
		nomeProduto[p] = (char*) malloc ((tam_max_produto + 1) * sizeof(char));
		if (nomeProduto[p] == NULL) {
			return EXIT_FAILURE;
		}
	}


	//Lendo as informações
	for (k = 0; k < n_produto; k++) {
		printf("\nDigite o nome do produto numero %i:", (k + 1));
		scanf("%s", nomeProduto[k]);
	}

	for (i = 0; i < n_loja; i++) {
		for (j = 0; j < n_produto; j++) {
			printf("\nDigite a quantidade de %s na loja %i:", nomeProduto[j], (i + 1));
			scanf("%i", &produtosPorLoja[i][j]);
		}
	}


	//Impressão da tabela;
	printf("\n");
	linha(TAM_LINHA);
	printf(" RELATORIO DE PRODUTOS\n");
	linha(TAM_LINHA);
	linha(TAM_LINHA);



	for (l = 0; l < n_loja; l++) {

		printf("\nLoja %i  \n", l + 1);
		linha(TAM_LINHA);
		for (m = 0; m < n_produto; m++) {
			printf("N. de %s : %i\n", nomeProduto[m], produtosPorLoja[l][m]);
			linha(TAM_LINHA);
		}
		linha(TAM_LINHA);
	}

	//Chamada da função soma;
	somaTotal(produtosPorLoja, resultadoSoma, n_loja, n_produto);
	imprimeMenor(resultadoSoma, n_loja);


	for (r = 0; r < n_produto; r++) free(nomeProduto[r]);
	free(nomeProduto);

	for (q = 0; q < n_loja; q++) free(produtosPorLoja[q]);
	free(produtosPorLoja);

	free(resultadoSoma);

	
	return SUCESSO;
}

//Função que imprime uma linha de asteriscos;
void linha(int N_da_linha) {
	counter a;

	for (a = 1; a <= N_da_linha; a++)
	{
		putchar('*');
	}
	printf("\n");
}


//Função que faz a soma dos produtos e coloca o resultado em um vetor;
void somaTotal(int** matriz, int* destinoResultado, int n_lojas, int n_produtos) {
	counter b, c, d;

	for (c = 0; c < n_lojas; c++) {
		destinoResultado[c] = { 0 };
	}

	for (b = 0; b < n_lojas; b++) {
		for (d = 0; d < n_produtos; d++)
			destinoResultado[b] += matriz[b][d];
	}

	return;
}

//Função que imprime o menor numero do vetor e sua correspondente loja;
void imprimeMenor(int* vetor, int tam_vetor) {
	int menor = vetor[0];
	int indiceMenor = 0;
	counter f;

	for (f = 0; f < tam_vetor; f++) {
		if (vetor[f] < menor) {
			menor = vetor[f];
			indiceMenor = f;
		}

	}

	printf("A loja com menor quantidade de produtos eh a loja %i com %i produtos no total.\n", indiceMenor + 1, menor);
	linha(TAM_LINHA);

	return;
}