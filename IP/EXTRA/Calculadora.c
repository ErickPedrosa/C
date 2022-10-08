/*Criador: Erick Pedrosa Barreto;
*Data de criação: 08/06/21;
*Descrição: Esse algoritimo realiza cálculos como uma calculadora básica
(+, -, *, /, %(MOD), #(exponenciação) ) entre dois numeros;
*/
#include <stdio.h>
#include <math.h>
#define SUCESSO  0

int main(int argc, char** argv) {

	//Declaração das variaveis;
	float Num , Num2 , Res, Comp;
	char Simb = '+';
	int i;


	//Processamento de dados;
	while (Simb == '+' | '-' | '*' | '/' | '#' | '%') {

		Num = 0;
		Num2 = 0;

		printf("Digite uma equacao com espaco entre o primeiro numero e o simbolo :\n");
		scanf("%f %c %f", &Num, &Simb, &Num2);

		if (Num && Num2 != 0) {

		
			switch (Simb) {
			case '+':
				Res = Num + Num2;
				printf("%f %c %f = %f \n", Num, Simb, Num2, Res);
				continue;
			break;
			case '-':
				Res = Num - Num2;
				printf("%f %c %f = %f \n", Num, Simb, Num2, Res);
				continue;
			break;
			case '*':
				Res = Num * Num2;
				printf("%f %c %f = %f \n", Num, Simb, Num2, Res);
				continue;
			break;
			case '/':
				Res = Num / Num2;
				printf("%f %c %f = %f \n", Num, Simb, Num2, Res);
				continue;
			break;
			case '%':
				Res = (int)Num % (int)Num2;
				printf("%f %c %f = %f \n", Num, Simb, Num2, Res);
				continue;
			break;
			case '#':
				Res = Num;
				Comp = Num;
				for (i = 2; i <= Num2; i++) {
					Num = Num * Res;
				}
				Res = Num;
				printf("%f %c %f = %f \n", Comp, Simb, Num2, Res);
				continue;
			break;

			default:
			break;
			}
		}
		printf("Operacao invalida!");
		break;
	}

	return SUCESSO;
}