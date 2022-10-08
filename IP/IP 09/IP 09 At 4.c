/*Criador: Erick Pedrosa Barreto
 *Data: 11/08/2021
 *Descrição: Esse programa recebe um vetor de numeros reais
 *e calcula a media aritmetica desses valores recebidos;
*/

#include <stdio.h>
#define SUCESSO 0
#define MAX_VET1 1000


int main(int argc, char** argv) {

	//Declaração das variáveis;
	float num[MAX_VET1], soma = 0, media;
	int i, lim_vet = 1;

	//Processamento de dados;
	printf("Digite o tamanho do vetor (limite = 1000):");
	scanf("%i", &lim_vet);

	for (i = 0; i < lim_vet; i++) {

		printf("\nDigite o valor %i do vetor:", i);
		scanf("%f", &num[i]);

	}
	for (i = 0; i < lim_vet; i++) {
		soma += num[i];
	}
	media = soma / lim_vet;
	printf("A media aritmetica do vetor eh igual a %f", media);

	return SUCESSO;
}