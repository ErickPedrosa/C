/*Criador: Erick Pedrosa Barreto
 *Data: 16/11/2021;
 *Descrição: ;
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SUCESSO 0
#define ERRO 1

int max_vet(int*, int);
int soma_vet(int*, int);
int media_vet(int*, int, int);

int main(int argc, char** argv) {

	int *vet, max, soma, media, a, tam_vet;
	

	printf("Digite o tamanho do vetor:");
	scanf("%i", &tam_vet);

	vet = (int*)calloc(tam_vet, sizeof(int));

	for (a = 0; a < tam_vet; a++)
	{
		printf("Digite o %io numero do vetor: ", a + 1);
		scanf("%i", &vet[a]);
	}

	max = max_vet(vet, tam_vet);
	soma = soma_vet(vet, tam_vet);
	media = media_vet(vet, tam_vet, tam_vet);

	printf("\nO elemento maximo do vetor e: %i\n", max);
	printf("A soma do vetor e: %i\n", soma);
	printf("A media do vetor e: %i\n", media);


	free(vet);
	return SUCESSO;
}

int max_vet(int* vet, int tam_vet) {


	if (tam_vet == 0)
	{
		return vet[tam_vet];

	}else if (vet[tam_vet - 1] < max_vet(vet, tam_vet - 1)) {
		return max_vet(vet, tam_vet - 1);
	}
	else
	{
		return vet[tam_vet - 1];
	}

	return vet[tam_vet - 1];
}


int soma_vet(int* vet, int tam_vet) {

	int soma = 0;

	if (tam_vet == 1)
	{
		return vet[tam_vet - 1];
	}
	else
	{
	soma = vet[tam_vet - 1] + soma_vet(vet, (tam_vet - 1));
	return soma;
	}
}

int media_vet(int* vet, int tam_vet, int indice) {

	if (indice == 0) {
		return indice;
	}
	else if (indice == tam_vet) {
		return (vet[indice - 1] + media_vet(vet, tam_vet, indice - 1)) / tam_vet;
	}
	else {
		return vet[indice - 1] + media_vet(vet, tam_vet, indice - 1);
	}
}