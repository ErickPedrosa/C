/*Criador: Erick Pedrosa Barreto
 *Data: 11/08/2021
 *Descrição: Esse programa lê dois vetores de números reais
 *e calcula o produto escalar;
*/

#include <stdio.h>
#define SUCESSO 0
#define MAX_VET1 10
#define MAX_VET2 10

int main(int argc, char** argv) {

	//Declaração das variáveis;
	float num[MAX_VET1], res[MAX_VET1], total = 0, num2[MAX_VET2];
	int i;

	//Entrada de dados
	for (i = 0; i < MAX_VET1; i++) {

		printf("Digite o valor %i do vetor 1:  ", i);
		scanf("%f", &num[i]);
	}

	for (i = 0; i < MAX_VET2; i++) {
		printf("Digite o valor %i do vetor 2:  ", i);
		scanf("%f", &num2[i]);
	}

	//Calculo do produto escalar
	for (i = 0; i < MAX_VET1; i++) {
		res[i] = num[i] * num2[i];
		total += res[i];
	}
	printf("\nO produto escalar dos vetores 1 e 2 eh %f", total);

	return SUCESSO;
}