/*Criador: Erick Pedrosa Barreto;
*Data de criação: 05/30/21;
*Descrição: O algoritimo irá ler 5 números inteiros e imprimirá a soma desses números;
*/

#include <math.h>
#include <stdio.h>
#define sucesso  0

int main(int argc, char** argv) {

	//Declaração das variavéis;
	int num1, num2, num3, num4, num5, soma;

	//Leitura de dados;
	printf("Digite 5 numeros inteiros: \n");
	scanf("%i %i %i %i %i", &num1, &num2, &num3, &num4, &num5);
	
	//Processamento de dados;
	soma = (num1 + num2 + num3 + num4 + num5);
	printf("A soma dos numero digitados eh %i \n ", soma);

	return sucesso;
}

	