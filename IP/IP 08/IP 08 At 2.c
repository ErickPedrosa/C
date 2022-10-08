/*Criador: Erick Pedrosa Barreto
* Data: 04/08/2021
* Descrição: Esse programa recebe a idade da pessoa em anos, dias e meses e retorna a idade em dias;
*/

#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0;

//Cabeçalho da sub-rotina;
long int idade_em_dias(int, int, int);

//Função principal/main;
int main(int argc, char** argv) {

	//Declaração das variavéis;
	int anos, meses, dias;
	long int total_dias;


	//Processamento de dados;
	printf("Insira a sua idade em anos, meses e dias:");
	scanf("%i : %i : %i", &anos, &meses, &dias);

	total_dias = idade_em_dias(anos, meses, dias);

	printf("Sua idade em dias eh de aproximadamente %li dias", total_dias);


	return SUCESSO;
}


//Função de conversão;
long int idade_em_dias(int anos, int meses, int dias) {
	long int idadeDias;
	int ano_bissexto;

	ano_bissexto = anos / 4;

	anos *= 365;
	meses *= 30.417;
	
	idadeDias = anos + meses + dias + ano_bissexto;

	return idadeDias;
}