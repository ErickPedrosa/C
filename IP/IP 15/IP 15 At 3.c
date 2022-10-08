/*Criador: Erick Pedrosa Barreto
 *Data: 16/11/2021
 *Descrição: ;
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SUCESSO 0
#define ERRO 1

int fibonacci(int);


int main(int argc, char** argv) {

	int num, a;
	

		printf("Digite o quantidade de numeros da sequencia de Fibonacci: ");
		scanf("%i", &num);

		for (a = 1; a <= num; a++) {
			printf("%i ", fibonacci(a));
		}


	return SUCESSO;
}

int fibonacci(int num) {

	int limite = 1, limite2 = 2;

		if (num == limite) {

			return(limite);

		}else if (num == limite2) {

			return(limite);

		}
		return fibonacci(num - 1) + fibonacci(num - 2);
	}