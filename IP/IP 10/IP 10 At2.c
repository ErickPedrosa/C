/*Criador: Erick Pedrosa Barreto
 *Data: 11/08/2021
 *Descrição:Esse programa recebe uma string e devolve a string sem caracteres "espaço";
*/

#include <stdio.h>
#include <string.h>
#define SUCESSO 0
#define MAX_VET1 100

int main(int argc, char** argv) {

	//Declaração das variáveis;
	char string[MAX_VET1];
	int i;

	//Processamento de dados;
	printf("Entre com a string:\n");
	fgets(string, MAX_VET1, stdin);

	for (i = 0; string[i] != '\0'; i++) {
		if (string[i] != ' ') {
			printf("%c", string[i]);
		}

	}

	return SUCESSO;
}