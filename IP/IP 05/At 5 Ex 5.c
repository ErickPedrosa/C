/*Criador: Erick Pedrosa Barreto;
*Data de criação: 04/06/21;
*Descrição: Esse algoritimo indica se três comprimentos inseridos podem gerar um trângulo ;
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define sucesso  0

int main(int argc, char** argv) {

	//Declaração das variaveis;
	float c1, c2, c3;

	//Leitura de dados;
	printf("Digite os tres comprimentos:\n");
	scanf("%f %f %f", &c1, &c2, &c3);

	//Processamento de dados;
	if (c1 < c2 + c3) {
		if (c2 < c1 + c3){
			if (c3 < c2 + c1) {
				printf("Eh possivel formar um triangulo");
			}else{
				printf("Nao eh possivel formar um triangulo");
			}
		}else {
			printf("Nao eh possivel formar um triangulo");
		}

	}else{
		printf("Nao eh possivel formar um triangulo");
	}
	return sucesso;
}