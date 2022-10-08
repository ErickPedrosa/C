/*Criador: Erick Pedrosa Barreto;
*Data de criação: 04/06/21;
*Descrição: Esse algoritimo indica se você está no seu peso ideal;
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define sucesso  0

int main(int argc, char** argv) {

	//Declaração das variaveis;
	float Res, H, P;
	char S;

	//Leitura de dados;	
	printf("Digite seu sexo(digite H para homem, M para mulher):\n");
	scanf("%c", &S);
	printf("Digite a sua altura:\n");
	scanf("%f", &H);
	printf("Digite seu peso:");
	scanf("%f", &P);

	//Processamento de dados;
	switch (S){
		case 'H':
			Res = (72.7 * H) - 58;
			if (P == Res) {
				printf("Voce esta no peso ideal\a");
			} else if (P > Res) {
				printf("Voce esta acima do peso ideal que eh %f", Res);
			} else {
				printf("Voce esta abaixo do peso ideal que eh %f", Res);
			}
		break;
		case 'M':
			Res = (62.1 * H) - 44.7;
			if (P == Res) {
				printf("Voce esta no peso ideal\a");
			} else if (P > Res) {
				printf("Voce esta acima do peso ideal que eh %f", Res);
			} else {
				printf("Voce esta abaixo do peso ideal que eh %f", Res);
			}
		break;
		default:
			printf("Nao possuimos informacoes suficientes para executar o calculo.");
		break;
	}
}