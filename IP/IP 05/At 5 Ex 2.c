/*Criador: Erick Pedrosa Barreto;
*Data de criação: 04/06/21;
*Descrição: Esse algoritimo calcula qual dos dois números digitados é maior ou se são iguais;
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define sucesso  0

int main(int argc, char** argv) {

	//Declaração das variaveis;
	int Num, Num2;

	//Leitura de dados;
	printf("Digite dois numeros inteiro:\n");
	scanf("%i %i", &Num ,&Num2);

	//Processamento de dados;
	if (Num >= Num2){
		if (Num > Num2) {
			printf("%i eh maior que %i", Num, Num2);
		}else{
			printf("%i eh igual a %i", Num, Num2);
		}
	}else{
		printf("%i eh maior que %i", Num2, Num);
	}

	return sucesso;
}