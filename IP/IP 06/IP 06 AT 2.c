/*Criador: Erick Pedrosa Barreto;
*Data de criação: 05/06/21;
*Descrição: Esse algoritimo lê um valor N inteiro e positivo e calcula e escreve o valor de E;
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define sucesso  0

int main(int argc, char** argv) {

	//Declaração das variaveis;
	int Num, Res = 1, i, D;
	float E = 0.0;

	//Leitura de dados;
	printf("Digite um numero inteiro:\n");
	scanf("%i", &Num);

	//Processamento de dados;
	for (i = 1; i <= Num; i++) {
		Res *= i;
		E += (1.0f / Res);
	}
	printf("O valor de E eh igual a %f", E);
	return sucesso;
}