/*Criador: Erick Pedrosa Barreto
 *Data:16/11/2021;
 *Descrição: ;
*/

#include <stdio.h>

#define SUCESSO 0
#define ERRO 1

int intervalo(int, int);

int main(int argc, char** argv) {

	int num = 0, num2 = 0;
	
	printf("Digite os numeros para saber o intervalo fechado entre eles:\n(O primeiro numero deve ser maior que o segundo)\n");
	scanf("%i %i", &num,  &num2);

	if (intervalo(num, num2) != 0)
	{
		printf("ERRO: O 1 numero e maior que o segundo.");
		return ERRO;
	}

	return SUCESSO;
}

int intervalo(int num, int num2) {

	if (num > num2)
	{
		return ERRO;
	}
	else if (num == num2)
	{
		printf("%i ", num);
	}
	else
	{
		printf("%i ", num);
		intervalo((num + 1), num2);
	}



	return SUCESSO;
}