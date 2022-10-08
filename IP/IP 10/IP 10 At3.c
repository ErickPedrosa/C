/*Criador: Erick Pedrosa Barreto
 *Data: 11/08/2021
 *Descrição:Esse programa recebe uma string e conta a quantidade de vogais nela;
*/

#include <stdio.h>
#include <string.h>
#define SUCESSO 0
#define MAX_VET1 (100 + 1)

int main(int argc, char** argv) {

	//Declaração das variáveis;
	char string[MAX_VET1];
	int counter = 0, i;

	//Processamento de dados;
	printf("Entre com a string:\n");
	fgets(string, MAX_VET1, stdin);

	for (i = 0; string[i] != '\0'; i++) {
		switch (string[i]) {
		case 'a':
			counter++;
			break;
		case 'A':
			counter++;
			break;
		case 'e':
			counter++;
			break;
		case 'E':
			counter++;
			break;
		case 'i':
			counter++;
			break;
		case 'I':
			counter++;
			break;
		case 'o':
			counter++;
			break;
		case 'O':
			counter++;
			break;
		case 'u':
			counter++;
			break;
		case 'U':
			counter++;
			break;

		}

	}

	printf("A string digitada possui %i vogais", counter);

	return SUCESSO;
}