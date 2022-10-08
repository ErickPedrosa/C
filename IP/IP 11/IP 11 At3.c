/*Criador: Erick Pedrosa Barreto
 *Data: 18/08/2021
 *Descrição: Esse programa lê um vetor de dimensão 5 e uma
matriz quadrada de dimensão 5. E tem um procedimento que
multiplica o vetor pela matriz e imprime o resultado;
*/

#include <stdio.h>
#define SUCESSO 0
#define N_LINHAS 5
#define N_COLUNAS 5

void imprimeMultiplicacao(float [N_LINHAS], float[][N_COLUNAS]);

typedef int contadores;

int main(int argc, char** argv) {

	float matriz[N_LINHAS][N_COLUNAS], vetor[N_LINHAS];
	contadores i, j, k;

	for (i = 0; i < N_LINHAS; i++) {
		for (j = 0; j < N_COLUNAS; j++) {
			printf("Digite o numero da posicao %i da coluna %i da matriz:", i, j);
			scanf("%f", &matriz[i][j]);
		}
	}
	for (k = 0; k < N_LINHAS; k++) {
		printf("Digite o numero da posicao %i do vetor:", k);
		scanf("%f", &vetor[k]);
	}

	imprimeMultiplicacao(vetor, matriz);

	

return SUCESSO;
}

void imprimeMultiplicacao(float vetor[N_LINHAS], float matriz[][N_COLUNAS]) {
	contadores a, b, c, d, e;
	float totalSoma[N_LINHAS] = { 0, 0, 0, 0, 0 }, totalMultiplicacao = 0;

	for (a = 0; a < N_LINHAS; a++) {
		for (b = 0; b < N_COLUNAS; b++) {
			matriz[a][b] = vetor[b] * matriz[a][b];
		}
	}
	for ( c = 0; c < N_LINHAS; c++)
	{
		for (d = 0; d < N_COLUNAS; d++) {
			totalSoma[c] += matriz[c][d];
		}
	}

for (e = 0; e < N_LINHAS; e++)
	{
		printf("O resultado da multiplicacao da matriz pelo vetor eh: %.4f", totalSoma[e]);
	}

	return;
}