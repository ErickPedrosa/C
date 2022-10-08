/*Criador: Erick Pedrosa Barreto
 *Data:
 *Descrição: ;
*/

#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0

typedef unsigned int counter;

float** alocaMatriz(int, int);
float soma(float**, int, int);

int main(int argc, char** argv) {
	float** matrix;
	float total;
	int size_x, size_y;
	counter i, j, k;

	//Leitura do tamanho da matriz;
	printf("Digite o tamanho da matriz a ser alocada:");
	scanf("%i", &size_x);
	scanf("%i", &size_y);

	//Alocação da matriz;
	matrix = alocaMatriz(size_x, size_y);

	for (i = 0; i < size_x; i++) {
		for (j = 0; j < size_y; j++) {
			printf("\nDigite o valor da posicao %i, %i da matriz::", i, j);
			scanf("%f", &matrix[i][j]);
		}
		
	}
	total = soma(matrix, size_x, size_y);

	printf("\nO total da soma de todos os elementos da matriz eh %f", total);
		
	//Liberação da matriz;
	for (k = 0; k < size_x; k++){
		free(matrix[k]);
	}
	free(matrix);
	return EXIT_SUCCESS;
}

float soma(float** matriz, int size_x, int size_y) {
	counter a, b;
	float totalSoma = 0;

	for (a = 0; a < size_x; a++) {
		for (b = 0; b < size_y; b++) {
			totalSoma += matriz[a][b];
		}
	}
	return totalSoma;
}

//Função que alocará a matriz;
float** alocaMatriz(int size_x, int size_y) {
	float** matrix2;
	counter i;

	matrix2 = (float**)malloc(size_x * sizeof(float));
	if (matrix2 == NULL) {
		return (float**)EXIT_FAILURE;
	}
	for (i = 0; i < size_x; i++) {
		matrix2[i] = (float*)malloc(size_y * sizeof(float));
		if (matrix2[i] == NULL) {
			return (float**)EXIT_FAILURE;
		}
	}

	return matrix2;
} 