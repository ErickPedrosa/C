/*Criador: Erick Pedrosa Barreto;
*Data de criação: 05/06/21;
*Descrição: Esse algoritimo, dado um conjunto de valores inteiros e
positivos (fornecidos um a um pelo usuário), determine qual o
menor e o maior valor do conjunto.;
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define sucesso 0

int main(int argc, char** argv) {

	//Declaração das variaveis;
	int Num, Maior = 0, Menor;

	//Leitura de dados;
	printf("Digite um numero inteiro:\n");
	scanf("%i", &Num);

	//Processamento de dados;
	Menor = Num;
	while (Num != 0) {
		if (Num > Maior){
			Maior = Num;
		} else if (Num < Menor) {
			Menor = Num;
		} else {
		}
		printf("Digite outro numero inteiro:\n");
		scanf("%i", &Num);
	}
	printf("O maior numero digitado foi %i e o menor foi %i", Maior, Menor);
	return sucesso;
}