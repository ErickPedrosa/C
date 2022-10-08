/*Criador: Erick Pedrosa Barreto;
*Data de criação: 04/06/21;
*Descrição: Esse algoritimo indica qual dia da semana indicado a partir de um número de 1 a 7;
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define sucesso  0

int main(int argc, char** argv) {

	//Declaração das variaveis;
	int dia;

	//Leitura de dados;
	printf("Digite um numero inteiro (sendo 1 para domingo, 2 para segunda e assim por diante):\n");
	scanf("%i", &dia);

	//Processamento de dados;
	switch (dia){
		case 1 :
			printf("O dia da semana indicado eh domingo");
		break;
		case 2:
			printf("O dia da semana indicado eh segunda-feira");
		break;
		case 3:
			printf("O dia da semana indicado eh terca-feira");
		break;
		case 4:
			printf("O dia da semanaindicado eh quarta-feira");
		break;
		case 5:
			printf("O dia da semana indicado eh quinta-feira");
		break;
		case 6:
			printf("O dia da semana indicado eh sexta-feira");
		break;
		case 7:
			printf("O dia da semana indicado eh sabado");
		break;
		default:
			printf("Dia da semana invalido");
		break;
	}

	return sucesso;
}