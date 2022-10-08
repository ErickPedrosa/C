/*Criador: Erick Pedrosa Barreto
 *Data: 18/08/2021
 *Descrição: Esse programa lê uma matriz 5x5 e um procedimento
que imprima sua transposta;
*/

#include <stdio.h>
#define SUCESSO 0
#define N_LINHAS 5
#define N_COLUNAS 5

void copiaTransposta(int[][N_COLUNAS], int[][N_COLUNAS]);
void imprimeMatrizes(int[][N_COLUNAS], int[][N_COLUNAS]);
typedef int contadores;

int main(int argc, char** argv) {

	int matriz[N_LINHAS][N_COLUNAS], matrizCopia[N_LINHAS][N_COLUNAS];
	contadores i, j;

	for (i = 0; i < N_LINHAS; i++) {
		for (j = 0; j < N_COLUNAS; j++) {
			printf("Digite o numero da posicao %i da coluna %i:", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}

	copiaTransposta(matriz, matrizCopia);

	imprimeMatrizes(matriz, matrizCopia);

return SUCESSO;
}

void copiaTransposta(int matOrigem[][N_COLUNAS], int matDestino[][N_COLUNAS]) {
	contadores a, b;

	for (a = 0; a < N_LINHAS; a++) {
		for (b = 0; b < N_COLUNAS; b++) {
			matDestino[a][b] = matOrigem[b][a];
		}
	}
	return;
}
void imprimeMatrizes(int mat[][N_COLUNAS], int matrizTransposta[][N_COLUNAS]) {
	contadores c, d;


	printf("\nA matriz dada era assim:\n");
	for (c = 0; c < N_LINHAS; c++) {
		for (d = 0; d < N_COLUNAS; d++) {
			printf("%i\t", mat[c][d]);
		}
		printf("\n");
	}
	printf("\nA matriz transposta ficara assim:\n");
	for (c = 0; c < N_LINHAS; c++) {
		for (d = 0; d < N_COLUNAS; d++) {
			printf("%i\t", matrizTransposta[c][d]);
		}
		printf("\n");
	}

	return;
}