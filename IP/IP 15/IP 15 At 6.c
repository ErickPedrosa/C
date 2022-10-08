/*Criador: Erick Pedrosa Barreto
 *Data: 16/11/2021;
 *Descrição: O programa realiza uma função de busca binária;
 * 
 * Perguntas sobre a busca binária;
 * Por que ela é tão rápida?? 
 * Porque a cada teste que a função realisa a quantidade de possíveis
 * candidatos a resultado diminui na metade;
 * 
 * O que a difere de uma busca normal??
 * Ao contrário da busca linear que verifica linearmente os itens um por um
 * a busca binária realiza testes no meio da lista (partindo do pressuposto
 * de que a lista esteja ordenada) diminuindo assim os possiveis resultados
 * na metade, o que torna a busca bem mais rápida.
 * 
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SUCESSO 0
#define ERRO -1

int buscador(int*, int, int, int);


int main(int argc, char** argv) {

	int* vet, indice, a, tam_vet, alvo = 0;


	printf("Digite o tamanho do vetor:");
	scanf("%i", &tam_vet);

	vet = (int*)calloc(tam_vet, sizeof(int));

	printf("\nAVISO: O vetor deve ser preenchido em ordem numerica crescente para que a busca possa ocorrer corretamente.\n");

	for (a = 0; a < tam_vet; a++)
	{
		printf("Digite o %io numero do vetor: ", a + 1);
		scanf("%i", &vet[a]);
	}

	printf("Digite o elemento que voce deseja buscar: ");
	scanf("%i", &alvo);

	indice = buscador(vet, tam_vet, alvo, 0);
	if (indice == ERRO)
	{
		printf("\nERRO: Numero nao existente no vetor.\n");
		return ERRO;
	}

	printf("\nO numero buscado esta na %ia posicao do vetor.\n", indice + 1);


	free(vet);
	return SUCESSO;
}

int buscador(int* vet, int tam_vet, int alvo, int posicao) {
	
	if (posicao > tam_vet || posicao < 0)
	{
		return ERRO;
	}

	int posicao_in = posicao;

	posicao = ((tam_vet - posicao) / 2) + posicao;

	if (vet[posicao ] == alvo)
	{
		return posicao;
	}
	if (vet[posicao] > alvo)
	{
		tam_vet = posicao;
		posicao = posicao_in;
		return buscador(vet, tam_vet, alvo, posicao);
	}
	else
	{
		return buscador(vet, tam_vet, alvo, posicao);
	}


}