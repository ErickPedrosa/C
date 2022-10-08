 /*Criador: Erick Pedrosa Barreto;
*Data de criação: 05/30/21;
*Descrição: Esse algoritimo irá gerar e imprimir o resultado do
número H, sendo H = 1 + 1/2 + 1/3 + 1/4 + 1/5;
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define sucesso  0

int main(int argc, char** argv) {

	//Declaração das variaveis;
	double H;

	//Processamento de dados;
	
	H = 1 + 1.0 / 2 + 1.0 / 3 + 1.0 / 4 + 1.0 / 5;

	printf("O valor de H eh %f ", H );

	return sucesso;
}