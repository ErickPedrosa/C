/*Criador: Erick Pedrosa Barreto
 *Data: 09/10/2021 ;
 *Descrição: Esse programa que lê de um arquivo as informações sobre
 *o nome e as 2 notas de diversos alunos. E imprime a listagem de
 *alunos e suas respectivas médias. O programa cria um arquivo
 *de entrada e um arquivo de saída com o nome e a média de
 *cada aluno.
*/

#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SUCESSO 0
#define ERRO -1
#define NUM_NOTAS 2
#define TAM_MAX_NOME 25
#define TAM_MAX_CAMINHO 300

typedef uint8_t counter;
typedef struct registro_alunos {
	char nome[TAM_MAX_NOME];
	float notas[NUM_NOTAS];
	float media;
} reg_alunos;

int Gen_inp_file(void);
int Gen_outp_file(void);

int main(int argc, char** argv) {

	int user_ans, retorno_funcao = 0;

	do {
		user_ans = 3;
		printf("Voce deseja criar um novo arquivo de registro ou gerar um relatorio de texto:\n\n1\tRegistro\n2\tRelatorio\n3\tSair do programa\n");
		scanf("%i", &user_ans);
		if (user_ans == 1) {

			retorno_funcao = Gen_inp_file();
			if (retorno_funcao == ERRO)
			{
				printf("ERRO: Nao foi possivel criar o arquivo");
				return ERRO;
			}

		}
		else if (user_ans == 2) {

			retorno_funcao = Gen_outp_file();
			if (retorno_funcao == ERRO)
			{
				printf("ERRO: Nao foi possivel abrir o arquivo");
				return ERRO;
			}
		}
	} while (user_ans != 3);


	return SUCESSO;
}


//Função que gera o arquivo de entrada // 
int Gen_inp_file(void) {


	counter i, k, a, b, d, j, l;
	FILE* arquivo_reg_al;
	char* caminho;
	int num_alunos = 0;
	reg_alunos* reg_al;


	caminho = (char*)malloc(TAM_MAX_CAMINHO * sizeof(char));

	printf("Digite o nome ou o caminho onde o arquivo deve ser criado:\nObs: Caso o arquivo ja exista voce perdera as informacoes antigas.\n");

	getchar();
	fgets(caminho, TAM_MAX_CAMINHO, stdin);
	caminho[strlen(caminho) - 1] = '\0';

	arquivo_reg_al = fopen(caminho, "w");
	if (arquivo_reg_al == NULL)
	{
		return ERRO;
	}

	printf("Digite o numero de alunos que deseja adicionar no registro:");
	scanf(" %i", &num_alunos);

	reg_al = (reg_alunos*)calloc(num_alunos, sizeof(reg_alunos));


	for (i = 0; i < num_alunos; i++) {
		printf("\nAluno %i", (i + 1));

		printf("\nDigite o nome do aluno %i: ", (i + 1));
		getchar();
		fgets(reg_al[i].nome, TAM_MAX_NOME, stdin);

		for (k = 0; k < NUM_NOTAS; k++) {

			printf("\nDigite a nota do aluno %i na prova %i: ", (i + 1), (k + 1));
			scanf("%f", &reg_al[i].notas[k]);
		}
	}

	for (d = 0; d < num_alunos; d++) {
		reg_al[d].media = { 0 };
	}

	for (a = 0; a < num_alunos; a++) {
		for (b = 0; b < NUM_NOTAS; b++) {
			reg_al[a].media += reg_al[a].notas[b];
		}
		reg_al[a].media = { reg_al[a].media / NUM_NOTAS };
	}

	fprintf(arquivo_reg_al, "%i", num_alunos);
	for (j = 0; j < num_alunos; j++) {
		fputs(reg_al[j].nome, arquivo_reg_al);
		for (l = 0; l < NUM_NOTAS; l++)
		{
			fprintf(arquivo_reg_al, "%f", reg_al[j].notas[l]);
		}
		fprintf(arquivo_reg_al, "%f", reg_al[j].media);
	}


	fclose(arquivo_reg_al);
	free(caminho);
	return SUCESSO;
}


//Função que gera o arquivo de saída // Relatório em formato txt //
int Gen_outp_file(void) {

	FILE* arquivo_reg_al, * relatorio_txt;
	char* caminho;
	int num_alunos = 0;
	reg_alunos* reg_al;
	counter j, k, l, m = -1;

	caminho = (char*)malloc(TAM_MAX_CAMINHO * sizeof(char));

	printf("Digite o nome ou o caminho do arquivo a ser lido:");
	getchar();
	fgets(caminho, TAM_MAX_CAMINHO, stdin);
	caminho[strlen(caminho) - 1] = '\0';

	arquivo_reg_al = fopen(caminho, "r");
	if (arquivo_reg_al == NULL)
	{
		return ERRO;
	}

	fscanf(arquivo_reg_al, "%i", &num_alunos);

	reg_al = (reg_alunos*)calloc(num_alunos, sizeof(reg_alunos));


	for (k = 0; k < num_alunos; k++)
	{

		fgets(reg_al[k].nome, TAM_MAX_NOME, arquivo_reg_al);
		getc(arquivo_reg_al);

		for (l = 0; l <= NUM_NOTAS; l++) {
			fseek(arquivo_reg_al, sizeof(float), SEEK_CUR);
		}
		fscanf(arquivo_reg_al, "%f", &reg_al[k].media);
	}

	printf("Digite o nome ou o caminho do relatorio txt a ser criado:");

	fgets(caminho, TAM_MAX_CAMINHO, stdin);
	caminho[strlen(caminho) - 1] = '\0';

	relatorio_txt = fopen(caminho, "w");
	if (relatorio_txt == NULL)
	{
		return ERRO;
	}

	for (j = 0; j < num_alunos; j++) {
		fprintf(relatorio_txt, "\nAluno %i:\n", (j + 1));
		fputs(reg_al[j].nome, relatorio_txt);
		fprintf(relatorio_txt, "Media: %f\n", reg_al[j].media);
	}

	fclose(relatorio_txt);
	fclose(arquivo_reg_al);
	free(caminho);
	return SUCESSO;
}