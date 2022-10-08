/*Criador: Erick Pedrosa Barreto
 *Data: 16/11/2021;
 *Descrição: ;
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SUCESSO 0
#define ERRO -1

int buscador(int*, int, int);


int main(int argc, char** argv) {

	int* vet, indice, a, tam_vet, alvo = 0;


	printf("Digite o tamanho do vetor:");
	scanf("%i", &tam_vet);

	vet = (int*)calloc(tam_vet, sizeof(int));

	for (a = 0; a < tam_vet; a++)
	{
		printf("Digite o %io numero do vetor: ", a + 1);
		scanf("%i", &vet[a]);
	}

	printf("Digite o elemento que voce deseja buscar: ");
	scanf("%i", &alvo);

	indice = buscador(vet, tam_vet, alvo);
	if (indice == ERRO)
	{
		printf("\nERRO: Numero nao existente no vetor.\n");
		return ERRO;
	}

	printf("\nO numero buscado esta na %ia posicao do vetor.\n", indice);


	free(vet);
	return SUCESSO;
}

int buscador(int* vet, int tam_vet, int alvo) {

	if (tam_vet < 0)
	{
		return ERRO;
	}	
	
	
	if (vet[tam_vet - 1] == alvo)
	{
		return tam_vet;
	}
	else
	{
		return buscador(vet, (tam_vet - 1), alvo);
	}


}