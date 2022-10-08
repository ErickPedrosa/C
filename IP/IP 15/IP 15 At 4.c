/*Criador: Erick Pedrosa Barreto
 *Data: 16/11/2021
 *Descrição: ;
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SUCESSO 0
#define ERRO 1
#define TAM_MAX_NUM 300 + 1

int contador(char *, int);


int main(int argc, char** argv) {

	char num[TAM_MAX_NUM], n;
	

	printf("Digite o numero para determinar a quantidade de digitos: ");
	fgets(num, TAM_MAX_NUM, stdin);

	n = contador(num, 0);

	printf("O numero tem %i digitos", n);

	return SUCESSO;
}

int contador(char* string, int posicao) {
	int num = 1;

	if (string[posicao] != '\0' && string[posicao] != '\n')
	{
		num += contador(string, posicao + 1);
		
	}
	else
	{
		return 0;
	}
}