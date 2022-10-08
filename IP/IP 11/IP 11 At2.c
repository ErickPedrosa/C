/*Criador: Erick Pedrosa Barreto
 *Data: 18/08/2021
 *Descrição: Esse programa recebe uma matriz de números reais e
retorna a soma dos elementos desta matriz;
*/

#include <stdio.h>
#define SUCESSO 0
#define N_LINHAS 100
#define N_COLUNAS 100

float soma(float[][N_COLUNAS]);

typedef int contadores;

int main(int argc, char** argv) {

	float matriz[N_LINHAS][N_COLUNAS], somaTotal;
	contadores i, j;

	for (i = 0; i < N_LINHAS; i++) {
		for (j = 0; j < N_COLUNAS; j++) {
			printf("Digite o numero da posicao %i da coluna %i da matriz:", i, j);
			scanf("%f", &matriz[i][j]);
		}
	}

	somaTotal = soma(matriz);

	printf("O resultado da soma de todos os valores da matriz eh: %.4f", somaTotal);

return SUCESSO;
}

float soma(float matriz[][N_COLUNAS]) {
	contadores a, b;
	float totalSoma = 0;

	for (a = 0; a < N_LINHAS; a++) {
		for (b = 0; b < N_COLUNAS; b++) {
			totalSoma += matriz[a][b];
		}
	}
	return totalSoma;
}