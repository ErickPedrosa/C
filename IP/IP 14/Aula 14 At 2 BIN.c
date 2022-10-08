/*Criador: Erick Pedrosa Barreto
 *Data: 10/10/2021 ;
 *Descrição: Esse código cria um arquivo bin e conta quantos caracteres tem no arquivo.
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

	int num_caracteres;

	FILE* arquivo_1;

	//Abre o arquivo
	arquivo_1 = fopen("Arquivo_Aula_14.bin", "ab");
	fclose(arquivo_1);
	//Digitei diretamente no arquivo txt por isso não usei a função write;


	num_caracteres = le_linha(arquivo_1);
	if (num_caracteres == ERRO) {
		return ERRO;

	}

	printf("O arquivo tem %i caracteres.", num_caracteres);

	return SUCESSO;
}

int le_linha(FILE* arquivo_1) {

	char* texto;
	char a;
	int final_arquivo = 0, b, nao_carctere = 1, c = 0, total_caracteres;


	arquivo_1 = fopen("Arquivo_Aula_14.bin", "rb");
	if (arquivo_1 == NULL) {
		printf("Não foi possivel abrir o arquivo");
		return ERRO;

	}

	//Contando a quantidade de bytes que devem ser alocados;
	while (feof(arquivo_1) == NULL)
	{
		fread(&a, sizeof(char), 1, arquivo_1);
		final_arquivo++;
	}

	texto = (char*)malloc(final_arquivo);

	fseek(arquivo_1, 0, SEEK_SET);

	while (feof(arquivo_1) == NULL) {
		fread(&texto[c], sizeof(char), 1, arquivo_1);
		c++;
	}

	for (b = 0; b < final_arquivo; b++)
	{
		if (texto[b] == NULL) {

			nao_carctere++;

		}
		else if (texto[b] == 10) {

			nao_carctere++;
		}
		else if (texto[b] == 13) {

			nao_carctere++;
		}
		else if (texto[b] == 32) {

			nao_carctere++;
		}
	}

	total_caracteres = final_arquivo - nao_carctere;

	fclose(arquivo_1);
	free(texto);
	return total_caracteres;
}