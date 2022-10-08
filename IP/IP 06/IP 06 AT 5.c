/*Criador: Erick Pedrosa Barreto;
*Data de criação: 06/06/21;
*Descrição: Esse algoritimo faz uma tabela de conversão de Fahrenheit para Celsius;
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define sucesso 0
#define Max 150

int main(int argc, char** argv) {

	//Declaração das variaveis;
	int C, F, Min;

	//Processamento de dados;
	printf("Fahrenheit \t Celsius \n");
	for (Min = 50; Min <= Max; Min++){
		F = Min;
		C = 9 * (F - 32) / 5;
		printf("%i \t \t %i \n", F, C);
	}

	return sucesso;
}