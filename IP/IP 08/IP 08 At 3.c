/*Criador: Erick Pedrosa Barreto
* Data: 04/08/2021
* Descrição: Esse programa recebe por parâmetro o tempo de
duração de um experimento expresso em segundos e imprime
na tela esse mesmo tempo em horas, minutos e segundos.;
*/

#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 0

void duracao_experimento(unsigned int);

//Função principal/main;
int main(int argc, char** argv) {

	//Declaração das variavéis;
	unsigned int duracao;

	//Processamento de dados;
	printf("Insira a duracao do experimento em segundos:");
	scanf("%d", &duracao);

	duracao_experimento(duracao);

	return SUCESSO;
}


//Função de conversão;
void duracao_experimento(unsigned int seg) {
	unsigned int hora, minutos, resto_hr, resto_min;

	hora = seg / 3600;
	resto_hr = seg % 3600;
	minutos = resto_hr / 60;
	resto_min = resto_hr % 60;

	printf("A duracao do experimento foi de %d horas, %d minutos e %d segundos", hora, minutos, resto_min);

	return;
}