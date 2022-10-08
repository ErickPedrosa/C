/*Criador: Erick Pedrosa Barreto
 *Data: 10/10/2021 ;
 *Descrição: Esse programa que lê de um arquivo as informações sobre
 *o nome e as 2 notas de diversos alunos. E imprime a listagem de
 *alunos e suas respectivas médias. O programa cria um arquivo
 *de entrada e um arquivo de saída com o nome e a média de
 *cada aluno. O programa também calcula o desvio
 *padrão e a variância das médias dos alunos.
 */

#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

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
float variancia(reg_alunos* reg_al, int num_alunos, char type);
float desvioPadrao(reg_alunos* reg_al, int num_alunos, char type);

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
			}

		}
		else if (user_ans == 2) {

			retorno_funcao = Gen_outp_file();
			if (retorno_funcao == ERRO)
			{
				printf("ERRO: Nao foi possivel abrir o arquivo");
			}
		}
	} while (user_ans != 3);


	return SUCESSO;
}


//Função que gera o arquivo de entrada // Registro em formato bin //
int Gen_inp_file(void) {


	counter i, k, a, b, d;
	FILE* arquivo_reg_al;
	char* caminho;
	int num_alunos = 0;
	reg_alunos* reg_al;


	caminho = (char*)malloc(TAM_MAX_CAMINHO * sizeof(char));

	printf("Digite o nome ou o caminho onde o arquivo deve ser criado:\nObs: Caso o arquivo ja exista voce perdera as informacoes antigas.\n");

	getchar();
	fgets(caminho, TAM_MAX_CAMINHO, stdin);
	caminho[strlen(caminho) - 1] = '\0';

	arquivo_reg_al = fopen(caminho, "wb");
	if (arquivo_reg_al == NULL)
	{
		return ERRO;
	}

	printf("Digite o numero de alunos que deseja adicionar no registro:");
	scanf(" %i", &num_alunos);

	reg_al = (reg_alunos*)calloc(num_alunos, sizeof(reg_alunos));

	fwrite(&num_alunos, sizeof(int), 1, arquivo_reg_al);

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

	fwrite(reg_al, sizeof(reg_alunos), num_alunos, arquivo_reg_al);
	fclose(arquivo_reg_al);
	free(caminho);
	return SUCESSO;
}


//Função que gera o arquivo de saída // Relatório em formato txt //
int Gen_outp_file(void) {

	FILE* arquivo_reg_al, * relatorio_txt;
	char* caminho;
	int num_alunos = 0;
	float var = 0, desv_p = 0;
	reg_alunos* reg_al;
	counter j;

	caminho = (char*)malloc(TAM_MAX_CAMINHO * sizeof(char));

	printf("Digite o nome ou o caminho do arquivo a ser lido:");
	getchar();
	fgets(caminho, TAM_MAX_CAMINHO, stdin);
	caminho[strlen(caminho) - 1] = '\0';

	arquivo_reg_al = fopen(caminho, "rb");
	if (arquivo_reg_al == NULL)
	{
		return ERRO;
	}

	fread(&num_alunos, sizeof(int), 1, arquivo_reg_al);

	reg_al = (reg_alunos*)calloc(num_alunos, sizeof(reg_alunos));

	fread(reg_al, sizeof(reg_alunos), num_alunos, arquivo_reg_al);

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
		fprintf(relatorio_txt, "Media: %.3f\n", reg_al[j].media);
	}

	fclose(relatorio_txt);
	fclose(arquivo_reg_al);

	var = variancia(reg_al, num_alunos, 'a');
	desv_p = desvioPadrao(reg_al, num_alunos, 'a');

	relatorio_txt = fopen(caminho, "a");

	fprintf(relatorio_txt, "\nVariancia (amostra): %f\nDesvio padrao (amostra): %f", var, desv_p);

	var = variancia(reg_al, num_alunos, 'p');
	desv_p = desvioPadrao(reg_al, num_alunos, 'p');

	fprintf(relatorio_txt, "\nVariancia (populacao): %f\nDesvio padrao (populacao): %f", var, desv_p);


	fclose(relatorio_txt);
	free(caminho);
	return SUCESSO;
}


float desvioPadrao(reg_alunos* reg_al, int num_alunos, char type) {

	float var, desvio;


	var = variancia(reg_al, num_alunos, type);

	desvio = sqrt(var);

	return desvio;
}

float variancia(reg_alunos* reg_al, int num_alunos, char type) {

	counter a, b, c;
	float var = 0, media_total = 0;
	int d;

	for (a = 0; a < num_alunos; a++)
	{
		media_total += reg_al[a].media;
	}
	media_total /= num_alunos;

	for (b = 0; b < num_alunos; b++) {
		var += pow((reg_al[b].media - media_total), 2);
	}


	if (type == 'a') {

		var /= (num_alunos - 1);

	}
	else if (type == 'p') {

		var /= num_alunos;

	}


	return var;
}