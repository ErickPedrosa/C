/*Criador: Erick Pedrosa Barreto;
*Data de criação: 05/30/21;
*Descrição: Esse algoritimo irá ler 6 valores reais, calcular e
imprimir a média aritmética desses valores;
*/

#include <stdio.h>
#include <math.h>
#define sucesso  0

int main(int argc, char** argv) {
	
	//Declaração das variaveis;
	float nu1, nu2, nu3, nu4, nu5, nu6, media, nuTotal;

	//Leitura de dados;
	printf("Digite 6 numeros reais:\n");
	scanf("%f %f %f %f %f %f", &nu1, &nu2, &nu3, &nu4, &nu5, &nu6);

	//Processamento de dados;
	nuTotal = (nu1 + nu2 + nu3 + nu4 + nu5 + nu6);
	media = nuTotal / 6 ;

	printf("A media eh igual a %f \n", media);

		return sucesso;
}