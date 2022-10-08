/*Criador: Erick Pedrosa Barreto;
*Data de criação: 06/06/21;
*Descrição: Esse algoritimo mostra um numero i primeiros numeros da sequência de Fibonacci;
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define sucesso 0

int main(int argc, char** argv) {

	//Declaração das variaveis;
	int Novo = 1, Ant = 1, qnt, res, i = 3;

	//Leitura de dados;
	printf("Quantos numeros da sequencia de fibonacci devem ser impressos:");
	scanf("%i", &qnt);

	//Processamento de dados;
	printf("%i \n", Novo);
	printf("%i \n", Ant);
	while (i <= qnt) {
		res = Novo + Ant;
		Ant = Novo;
		Novo = res;
		printf("%i \n", res);
		i++;
	}

	return sucesso;
}