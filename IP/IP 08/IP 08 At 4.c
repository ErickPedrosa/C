/*Criador: Erick Pedrosa Barreto
* Data: 04/08/2021
* Descrição: Esse programa recebe um numero e calcula se ele é primo ou não;
*/

#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0

void primo_v(int);

//Função principal/main;
int main(int argc, char** argv) {

	//Declaração das variavéis;
	int num;

	//Processamento de dados;
	printf("Insira o numero  a ser verificado:");
	scanf("%i", &num);

	primo_v(num);

	return SUCESSO;
}


//Função de calculo;
void primo_v(int num) {
	int i, divisores = 0, resto;

	for (i = 1; i <= num; i++) {
		resto = num % i;
		if (resto == 0) {
			divisores++;
		}
	}

	if (divisores == 2) {
		printf("O numero eh primo");
	}
	else {
		printf("O numero nao eh primo");
	}

	return;
}