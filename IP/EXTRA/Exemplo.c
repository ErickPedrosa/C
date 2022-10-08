/*Criador: Erick Pedrosa Barreto
* Data: 10/08/2021
* Descrição: ;
*/

#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0

void aprovacao(int);

//Função principal/main;
int main(int argc, char** argv) {

	//Declaração das variavéis;
	int nota;

	//Processamento de dados;

	printf("Insira a nota do aluno:");
	scanf("%d", &nota);

	aprovacao(nota);

	return SUCESSO;
}


//Função de conversão;
void aprovacao(int nota) {

	if (nota >= 60)
	{
		printf("Aluno aprovado");
	}else {
		printf("Aluno reprovado");
	}

		return;
}