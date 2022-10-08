/*Criador: Erick Pedrosa Barreto
 *Data:
 *Descrição: ;
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0

typedef unsigned int counter;


int main(int argc, char** argv) {
	float* vetor;
	float media = 0, soma = 0;
	int tam_vet;
	counter i, j;

	//Leitura do tamanho da matriz;
	printf("Digite o tamanho do vetor:");
	scanf("%i", &tam_vet);

	//alocação da memoria para o vetor;
	vetor = (float*)malloc(tam_vet * sizeof(float));

	for (i = 0; i < tam_vet; i++) {

		printf("\nDigite o valor %i do vetor:", i);
		scanf("%f", &vetor[i]);

	}
	for (j = 0; j < tam_vet; j++) {
		soma += vetor[j];
	}
	media = soma / tam_vet;
	printf("A media aritmetica do vetor eh igual a %f", media);

	//Liberação da matriz;
	free(vetor);
	return EXIT_SUCCESS;
} 