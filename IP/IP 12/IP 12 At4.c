/*Criador: Erick Pedrosa Barreto
 *Data:
 *Descrição: ;
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0

typedef unsigned int counter;

void imprimeMenor_e_Maior(float*, int);

int main(int argc, char** argv) {
	float* vetor;
	int tam_vet;
	counter i;

	//Leitura do tamanho da matriz;
	printf("Digite o tamanho do vetor:");
	scanf("%i", &tam_vet);

	//alocação da memoria para o vetor;
	vetor = (float*)malloc(tam_vet * sizeof(float));

	for (i = 0; i < tam_vet; i++) {

		printf("\nDigite o valor %i do vetor:", i);
		scanf("%f", &vetor[i]);

	}
	imprimeMenor_e_Maior(vetor, tam_vet);

	//Liberação da matriz;
	free(vetor);
	return EXIT_SUCCESS;
}

void imprimeMenor_e_Maior(float* vetor, int tam_vetor) {
	float menor = vetor[0], maior = vetor[0];
	int  indiceMenor = 0, indiceMaior = 0;
	counter f, g;


	for (f = 0; f < tam_vetor; f++) {
		if (vetor[f] < menor) {
			menor = vetor[f];
			indiceMenor = f;
		}

	}
	for (g = 0; g < tam_vetor; g++) {
		if (vetor[g] > maior) {
			maior = vetor[g];
			indiceMaior = g;
		}

	}
	printf("\nO menor numero foi: %f\nE esta no indice %i\nO maior numero foi: %f\nE esta no indice %i\n", menor, indiceMenor, maior, indiceMaior);

	return;
} 