/*Criador: Erick Pedrosa Barreto
 *Data: 11/08/2021
 *Descrição:Esse programa recebe uma palavra
 *e verifica se eh um palindromo;
*/

#include <stdio.h>
#include <string.h>
#define SUCESSO 0
#define MAX_VET1 (100 + 1)

char minusculo(char);

int main(int argc, char** argv) {

	//Declaração das variáveis;
	char string[MAX_VET1], comp_string[MAX_VET1];
	int ret = 1, i, i2, size;

	//Leitura;
	printf("Entre com a palavra (Sem acentos ou pontuacoes):\n");
	scanf("%s", string);
	size = strlen(string);
	comp_string[size] = '\0';
	size--;

	//Conversão da string para uma string sem caractere espaço, nem \n e em caracteres minusculos ;
	for (i = 0; i <= size; i++) {
		comp_string[i] = string[size - i];
	}

	for (i = 0; string[i] != '\0'; i++)
	{
		while (string[i] == ' ')
		{
			for (int y = i; string[y] != '\0'; y++)
			{
				string[y] = string[y + 1];
			}
		}
	}

	for (i = 0; comp_string[i] != '\0'; i++) {
		while (comp_string[i] == ' ')
		{
			for (int y = i; comp_string[y] != '\0'; y++)
			{
				comp_string[y] = comp_string[y + 1];
			}
		}
	}

	for (i = 0; i <= size; i++)
	{
		string[i] = minusculo(string[i]);
		comp_string[i] = minusculo(comp_string[i]);
	}

	//Comparação das strings e devolução do resultado;
	size++;
	ret = strncmp(string, comp_string, size);

	if (ret == 0) {
		printf("A string eh um palindromo");
	}
	else {
		printf("A string nao eh um palindromo");
	}

	return SUCESSO;
}

char minusculo(char let) {

	if (let < 90) {
		let += 32;
	}

	return let;
}