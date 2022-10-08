/*
Jogo 21
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SUCESSO  0


int main(int argc, char** argv) {

	//Declaração das variaveis;
	int total = 0, total2 = 0, compra = 1, total3 = 1, total4 = 1, compra2 = 1;


	//Processamento de resultado;
	srand(time(NULL));
	printf("Vamos jogar 21\n \n");
	total2 = (1 + rand() % 3);

	while (compra != 0){
		total2 = 1 + rand() % 10 ;
		total += total2;
		printf("Seu total eh de %i. Deseja comprar mais (Digite \"0\" para nao comprar):\n", total);
		scanf("%i", &compra);
		continue;
	} 

	printf("\n \n Jogador 2\n");
	while (compra2 != 0) {
		total4 = 1 + rand() % 10;
		total3 += total4;
		printf("Seu total eh de %i. Deseja comprar mais (Digite \"0\" para nao comprar):\n", total3);
		scanf("%i", &compra2);
		continue;
	}

	//Resultado;
	if (total & total3 == 21){
		printf("\n\nVoces ganharam!!! \n Parabens!");
	} else if (total == 21) {
		printf("\n\nParabens jogador 1 voce ganhou!!\n\n Jogador 2 voce perdeu! \n L \t O \t S \t E \t R");
	} else if (total3 == 21) {
		printf("\n\nParabens jogador 2 voce ganhou!!\n\n Jogador 1 voce perdeu! \n L \t O \t S \t E \t R");
	} else if (total || total3 > 21) {
		if (total == total){
		printf("\n\nVoces perderam hahahahah \n T \t R \t O \t U \t X \t A \t S");
		} else if (total < total3) {
			printf("\n\nVoce perdeu jogador 2 hahahahah \n L \t O \t S \t E \t R \n Voce ganhou jogador 1 parabens");
		} else {
			printf("\n\nVoce perdeu jogador 1 hahahahah \n L \t O \t S \t E \t R \n Voce ganhou jogador 2 parabens");
		}
	} else if (total < total3) {
		printf("\n\nVoce perdeu jogador 1 hahahahah \n L \t O \t S \t E \t R \n Voce ganhou jogador 2 parabens");
	} else if (total > total3) {
		printf("\n\nVoce perdeu jogador 2 hahahahah \n L \t O \t S \t E \t R \n Voce ganhou jogador 1 parabens");
	} else {
		printf( "\n\nVoces empataram!");
	}

	return SUCESSO;
}