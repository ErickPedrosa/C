/*Criador: Erick Pedrosa Barreto
/*Criador: Erick Pedrosa Barreto
 *Data: 11/08/2021
 *Descrição: Esse programa lê um vetor de números reais,
 *um escalar e imprime o resultado da multiplicação do vetor
 *pelo escalar;
*/

#include <stdio.h>
#define SUCESSO 0
#define MAX_VET1 1000

int main(int argc, char** argv) {

	//Declaração das variáveis;
	float num[MAX_VET1], res[MAX_VET1], escalar = 1;
	int i, lim_vet = 1;

	//Processamento de dados;
	printf("Digite o numero escalar:");
	scanf("%f", &escalar);

	printf("Digite a quantidade de numeros do vetor:");
	scanf("%i", &lim_vet);

	for (i = 0; i < lim_vet; i++) {

		printf("\nDigite o valor %i do vetor:", i);
		scanf("%f", &num[i]);

		res[i] = num[i] * escalar;
	}
	for (i = 0; i < lim_vet; i++) {
		printf("\n%f * %f = %f", num[i], escalar, res[i]);
	}

	return SUCESSO;
}