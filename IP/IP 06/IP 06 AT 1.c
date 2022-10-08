/*Criador: Erick Pedrosa Barreto;
*Data de criação: 05/06/21;
*Descrição: Esse algoritimo realiza o calculo para descobrir qual o fatorial de um numero fornecido pelo usuário;
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define sucesso  0

int main(int argc, char** argv) {

	//Declaração das variaveis;
	int Num, i;
	long long int Res = 1;

	//Leitura de dados;
	printf("Digite um numero inteiro:\n");
	scanf("%d", &Num);

	//Processamento de dados;
	for (i = 1; i <= Num; i++) {
		Res *= i;
	}
	printf("O resultado do fatorial de %d eh %lld", Num, Res);
	return sucesso;
}