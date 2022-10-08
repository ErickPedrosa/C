/*Criador: Erick Pedrosa Barreto;
*Data de criação: 04/06/21;
*Descrição: Esse algoritimo realiza uma equação básica(+ - * /) entre dois numeros;
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define sucesso  0

int main(int argc, char** argv) {

	//Declaração das variaveis;
	float Num, Num2, Res;
	char Simb;

	//Leitura de dados;
	printf("Digite uma equacao (com espaco entre o primeiro numero e o simbolo):\n");
	scanf("%f %c %f", &Num, &Simb, &Num2);

	//Processamento de dados;
	switch (Simb) {
		case '+':
			Res = Num + Num2;
			printf("%f %c %f = %f", Num, Simb, Num2, Res);
		break;
		case '-':
			Res = Num - Num2;
			printf("%f %c %f = %f", Num, Simb, Num2, Res);
		break;
		case '*':
			Res = Num * Num2;
			printf("%f %c %f = %f", Num, Simb, Num2, Res);
		break;
		case '/':
			Res = Num / Num2;
			printf("%f %c %f = %f", Num, Simb, Num2, Res);
		break;
		default:
			printf("A operacao indicada eh invalida");
		break;
	}

	return sucesso;
}