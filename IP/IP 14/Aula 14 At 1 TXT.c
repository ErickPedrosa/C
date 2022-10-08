/*Criador: Erick Pedrosa Barreto
 *Data: 09/10/2021 ;
 *Descrição: Esse código cria um arquivo txt e conta quantas linhas tem no arquivo.
 * Obs: o arquivo deve ser preechido pelo usuário no bloco de notas;
 * Obs 2: o arquivo estará na solução do projeto atual;
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SUCESSO 0
#define ERRO 1
#define TAM_MAX_LIN 80

int le_linha(FILE*);

int main(int argc, char** argv) {

	int num_linhas;

	FILE* arquivo_1;

	//Abre o arquivo
	arquivo_1 = fopen("Arquivo_Aula_14.txt", "a");
	fclose(arquivo_1);
	//Digitei diretamente no arquivo txt por isso não usei a função write;


	num_linhas = le_linha(arquivo_1);

	printf("O arquivo tem %i linhas", num_linhas);

	return SUCESSO;
}

int le_linha(FILE* arquivo_1) {

	char* texto;
	char a;
	int final_arquivo = 0, b, linhas = 1, c = 0;


	arquivo_1 = fopen("Arquivo_Aula_14.txt", "r");


	while (feof(arquivo_1) == NULL)
	{
		fscanf(arquivo_1, "%c", &a);
		final_arquivo++;
	}

	texto = (char*)malloc(final_arquivo);

	fseek(arquivo_1, 0, SEEK_SET);

	while (feof(arquivo_1) == NULL){

		fscanf(arquivo_1, "%c", &texto[c]);
		c++;
	}

	for (b = 0; b < final_arquivo; b++)
	{
		if (texto[b] == '\n') {
			
			linhas++;
		
		} else if (texto[b] == '\0') {

			linhas++;
		}
	}

	fclose(arquivo_1);
	free(texto);
	return linhas;
}