 /*Criador: Erick Pedrosa Barreto;
*Data de criação: 05/30/21;
*Descrição: Esse algoritimo calcula a nota media de um aluno em tres provas com pesos;
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define sucesso  0
#define pesoprova1  4
#define pesoprova2  3
#define pesoprova3  3

int main(int argc, char** argv) {

	//Declaração das variaveis;
	float prova1, prova2, prova3, peso1, peso2, peso3, media;

	//Leitura de dados;
	printf("Digite a nota das tres provas:\n");
	scanf("%f %f %f", &prova1, &prova2, &prova3);

	//Processamento de dados;
	peso1 = prova1 * pesoprova1;
	peso2 = prova2 * pesoprova2;
	peso3 = prova3 * pesoprova3;
	media = (peso1 + peso2 + peso3) / (pesoprova1 + pesoprova2 + pesoprova3);

	printf("A media ponderada das tres provas eh %f", media);

	return sucesso;
}