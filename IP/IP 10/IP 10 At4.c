/*Criador: Erick Pedrosa Barreto
 *Data: 11/08/2021
 *Descrição:Esse programa recebe uma string e transforma a
 *primeira letra de todas as palavras em maiusculas;
*/

#include <stdio.h>
#include <string.h>
#define SUCESSO 0
#define MAX_VET1 100

int main(int argc, char** argv) {

	//Declaração das variáveis;
	char string[MAX_VET1];
	int counter = 0, i;

	//Processamento de dados;
	printf("Entre com a string:\n");
	fgets(string, MAX_VET1, stdin);

	for (i = 0; string[i] != '\0'; i++) {
		if (string[i] == ' ') {
			if (string[i + 1] != ' ') {
				string[i + 1] -= 32;
			}
		}
	}

	fputs(string, stdout);

	return SUCESSO;
}