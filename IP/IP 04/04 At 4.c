 /*Criador: Erick Pedrosa Barreto;
*Data de criação: 05/30/21;
*Descrição: Esse algoritimo irá Calcular o aumento que será dado a um funcionário, obtendo
do usuário as seguintes informações, salário atual e a porcentagem de aumento.
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define sucesso  0

int main(int argc, char** argv) {

	//Declaração das variaveis;
	float salarioAtual, salarioNovo, porcentagem, aumento, aumento2;

	//Leitura de dados;
	printf("Qual eh o slario atual do funcionario ?\n");
	scanf("%f", &salarioAtual);
	printf("Qual eh a porcentagem de aumento ?\n");
	scanf("%f", &porcentagem);

	//Processamento de dados;
	aumento = salarioAtual / 100 * porcentagem;
	salarioNovo = salarioAtual + aumento;

	printf("O salario do funcionario sera %.2f apos o aumento", salarioNovo);
	
	return sucesso;
}
