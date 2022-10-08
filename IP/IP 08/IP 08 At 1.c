/*Criador: Erick Pedrosa Barreto
* Data:
* Descrição: Esse programa fornece um menu no qual a pessoa pode selecionar soma, subtração, divisão,
* multiplicação, resto e exponenciação.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SUCESSO 0

float soma(float, float);
float subtracao(float, float);
float divisao(float, float);
float multiplicacao(float, float);
long int expon(int, int);
int MOD(int, int);

//Função principal/main;
int main(int argc, char** argv) {

	//Declaração das variavéis;
	int menu = 7;
	float num1, num2, resultado;


	//Menu de escolhas;
	do{
		switch (menu)
		{
		case 1:
			printf("Digite os numeros a serem somados:\n");
			scanf("%f %f", &num1, &num2);
			resultado = soma(num1, num2);
			printf("%f + %f = %f\n\n", num1, num2, resultado);
			break;
		case 2:
			printf("Digite os numeros a serem subtraidos:\n");
			scanf("%f %f", &num1, &num2);
			resultado = subtracao(num1, num2);
			printf("%f - %f = %f\n\n", num1, num2, resultado);
			break;
		case 3:
			printf("Digite os numeros a serem divididos:\n");
			scanf("%f %f", &num1, &num2);
			resultado = divisao(num1, num2);
			printf("%f : %f = %f\n\n", num1, num2, resultado);
			break;
		case 4:
			printf("Digite os numeros a serem multiplicados:\n");
			scanf("%f %f", &num1, &num2);
			resultado = multiplicacao(num1, num2);
			printf("%f * %f = %f\n\n", num1, num2, resultado);
			break;
		case 5:
			printf("Digite os numeros para fazer a operacao de resto(modulo):\n");
			scanf("%f %f", &num1, &num2);
			resultado = MOD((int)num1, (int)num2);
			printf("%f MOD %f = %f\n\n", num1, num2, resultado);
			break;
		case 6:
			printf("Digite os numeros a serem exponenciados:\n");
			scanf("%f %f", &num1, &num2);
			resultado = expon((int)num1, (int)num2);
			printf("%f + %f = %f\n\n", num1, num2, resultado);
			break;
		default:
			break;
		}

		menu = 7;
		printf("\nMenu de escolhas digite o numero respectivo a equacao que voce quer fazer:\n");
		printf("Soma\t\t 1\nSubtracao\t 2\nDivisao\t\t 3\nMultiplicacao\t 4\nResto\t\t 5\nExponenciacao\t 6\nSair do programa 7\n\n");
		scanf("%i", &menu);
	} while (menu != 7);


		return SUCESSO;
}

//Funçao de soma;
float soma(float n1, float n2) {
	float res;

	res = n1 + n2;

	return res;
}

//Funçao de subtração;
float subtracao(float n1, float n2) {
	float res;

	res = n1 - n2;

	return res;
}

//Funçao de divisao;
float divisao(float n1, float n2) {
	float res;

	res = n1 / n2;

	return res;
}

//Funçao de multiplicação;
float multiplicacao(float n1, float n2) {
	float res;

	res = n1 * n2;

	return res;
}

//Função de exponenciação;
long int expon(int num, int expoent) {
	int i;
	long int copia_num, res;

	copia_num = num;
	for (i = 2; i <= expoent; i++) {
		copia_num *= num;
	}
	res = copia_num;

	return res;
}

//Função de modulo ou resto;
int MOD(int num1, int num2) {
	int res;

	res = num1 % num2;

	return res;
}