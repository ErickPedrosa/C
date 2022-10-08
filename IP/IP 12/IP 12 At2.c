/*Criador: Erick Pedrosa Barreto
 *Data:
 *Descrição: ;
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0

typedef unsigned int counter;

float** alocaMatriz(int , int);

int main(int argc, char** argv) {
	float** matrix;
	int size_x, size_y;
	counter a, b;

	//Leitura do tamanho da matriz;
	printf("Digite o tamanho da matriz a ser alocada:");
	scanf("%i", &size_x);
	scanf("%i", &size_y);

	//Alocação da matriz;
	matrix = alocaMatriz(size_x, size_y);

	//Liberação da matriz;
	for (b = 0; b < size_x; b++){
		free(matrix[b]);
	}
	free(matrix);
	return EXIT_SUCCESS;
}

//Função que alocará a matriz;
float** alocaMatriz(int size_x, int size_y) {
	float** matrix2;
	counter i;

	matrix2 = (float**) malloc(size_x * sizeof(float));
	if (matrix2 == NULL) {
		return (float**)EXIT_FAILURE;
	}
	for (i = 0; i < size_x; i++) {
		matrix2[i] = (float*) malloc(size_y * sizeof(float));
		if (matrix2[i] == NULL) {
			return (float**)EXIT_FAILURE;
		}
	}

	return matrix2;
} 