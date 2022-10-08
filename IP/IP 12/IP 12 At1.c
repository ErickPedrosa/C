/*Criador: Erick Pedrosa Barreto
 *Data:
 *Descrição: ;
*/


#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0

int* alocaVetor(int tam_vetor);

int main(int argc, char** argv) {
	int* vetor;
	int tamanhoVetor = 0;


	printf("Digite o tamanho do vetor a ser alocado:");
	scanf("%i", &tamanhoVetor);

	vetor = alocaVetor(tamanhoVetor);

	free(vetor);
	return SUCESSO;
}

int* alocaVetor(int tam_vetor) {
	int* vetor;

	vetor = (int*)calloc(tam_vetor, sizeof(int));

	return vetor;
} 
