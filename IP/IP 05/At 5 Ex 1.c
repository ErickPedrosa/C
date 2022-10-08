/*Criador: Erick Pedrosa Barreto;
*Data de criação: 04/06/21;
*Descrição: Esse algoritimo calcula se um número é par ou ímpar;
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define sucesso  0

int main(int argc, char** argv) {

	//Declaração das variaveis;
	int Num, resto;

	//Leitura de dados;
	printf("Digite um numero inteiro:\n");
	scanf("%i", &Num);

	//Processamento de dados;
	resto = Num % 2;

	if (resto == 0){
		printf("O numero %i eh par", Num);
	}else{
		printf("O numero %i eh impar", Num);
	}

	return sucesso;
}