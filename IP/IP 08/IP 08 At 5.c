/*Criador: Erick Pedrosa Barreto
* Data: 04/08/2021
* Descrição: Esse programa recebe um numero e calcula o fatorial desse número;
*/

#include <stdio.h>
#define SUCESSO 0

unsigned int fatorial(unsigned int);

//Função principal/main;
int main(int argc, char** argv) {

	//Declaração das variavéis;
	unsigned int num, fat;

	//Processamento de dados;
	printf("Insira o numero  a ser verificado:");
	scanf("%d", &num);

	fat = fatorial(num);
	
	printf("O resultado do fatorial de %d eh %d", num, fat);
	
	return SUCESSO;
}


//Função de calculo;
unsigned int fatorial(unsigned int num) {
	int i;
	unsigned int fat = 1;

	for (i = 1; i <= num; i++) {
		Res *= i;
	}

	return;
}