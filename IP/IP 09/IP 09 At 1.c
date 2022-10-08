/*Criador: Erick Pedrosa Barreto
 *Data: 11/08/2021
 *Descrição: Esse programa lê n numeros inteiros e determina qual deles é o menor
 * e em qual indice esta este inteiro.
*/
 
#include <stdio.h>
#define SUCESSO 0
#define MAX_VET1 20
#define MAIOR_NUM  2147483647 //Maior numero possivel para uma variavel tipo int;

int main(int argc, char** argv) {

	//Declaração das variáveis;
	int num[MAX_VET1],i, indice, menor = MAX_NUM;

	//Processamento de dados;
	for  (i = 0; i < MAX_VET1; i++) {

		printf("Digite o valor do indice %i:\t", i);
		scanf("%i", &num[i]);

		if (num[i] < menor)
		{
			menor = num[i];
			indice = i;
		}
	}
	printf("\nO menor numero digitado foi %i e esta no indice %i", menor, indice);

	return SUCESSO;
}