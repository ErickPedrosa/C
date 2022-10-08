/*Criador: Erick Pedrosa Barreto
 *Data:
 *Descrição: ;
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SUCESSO  0
#define TAM_MAX_NOME  (100 + 1)
#define TAM_MAX_CURSO  (50 + 1)
#define NUM_DE_PROVAS  3
#define INDICE_DE_APROVACAO  60

typedef unsigned int counter;
typedef struct aluno_s {
	char nome[TAM_MAX_NOME];
	char curso[TAM_MAX_CURSO];
	unsigned int idade;
	float provas[NUM_DE_PROVAS];
	float media;
} aluno;

void le_estrutura(aluno*, uint32_t);
void imprime_estrutura(aluno*, uint32_t);
void imprime_media(aluno*, uint32_t);

int main(int argc, char** argv) {

	aluno* ficha_alunos;
	uint32_t num_alunos = 0;

	printf("Digite o numero de alunos: ");
	scanf("%u", &num_alunos);

	ficha_alunos = (aluno*)malloc(num_alunos * sizeof(aluno));

	le_estrutura(ficha_alunos, num_alunos);
	imprime_estrutura(ficha_alunos, num_alunos);


	free(ficha_alunos);
	return SUCESSO;
}

void le_estrutura(aluno* ficha_a, uint32_t n_alunos) {
	counter i, k;

	for (i = 0; i < n_alunos; i++) {
		printf("\nAluno %i", (i + 1));

		printf("\nDigite o nome do aluno %i: ", (i + 1));
		fgets(ficha_a[i].nome, TAM_MAX_NOME, stdin); //Usei a mesma função duas vezes pq estava atribuindo 
		fgets(ficha_a[i].nome, TAM_MAX_NOME, stdin); //  '\0' sem eu poder digitar;

		printf("\nDigite o curso do aluno %i: ", (i + 1));
		fgets(ficha_a[i].curso, TAM_MAX_CURSO, stdin);

		printf("\nDigite a idade do aluno %i: ", (i + 1));
		scanf("%u", &ficha_a[i].idade);

		for (k = 0; k < NUM_DE_PROVAS; k++) {

			printf("\nDigite a nota do aluno %i na prova %i: ", (i + 1), (k + 1));
			scanf("%f", &ficha_a[i].provas[k]);
		}
	}

	return;
}


void imprime_estrutura(aluno* ficha_a, uint32_t n_alunos) {
	counter j;

	for (j = 0; j < n_alunos; j++) {
		printf("\nAluno %i:\n", (j + 1));
		fputs(ficha_a[j].nome, stdout);
		fputs(ficha_a[j].curso, stdout);
		printf("%u\n", ficha_a[j].idade);

	}
	imprime_media(ficha_a, n_alunos);

	return;
}

void imprime_media(aluno* ficha_a, uint32_t n_alunos) {
	float media_geral = 0;
	counter a, b, c, d, e;

	for (d = 0; d < n_alunos; d++) {
		ficha_a[d].media = { 0 };
	}

	for (a = 0; a < n_alunos; a++) {
		for (b = 0; b < NUM_DE_PROVAS; b++) {
			ficha_a[a].media += ficha_a[a].provas[b];
		}
		ficha_a[a].media = { ficha_a[a].media / NUM_DE_PROVAS };
	}

	

	for (c = 0; c < n_alunos; c++) {
		printf("\nAluno(a):");
		fputs(ficha_a[c].nome, stdout);
		
		if (ficha_a[c].media >= INDICE_DE_APROVACAO) {
			printf("A media do aluno %i foi %f\n", (c + 1), ficha_a[c].media);
			printf("O aluno %i foi aprovado\n", (c + 1));
		}
		else {
			printf("A media do aluno %i foi %f\n", (c + 1), ficha_a[c].media);
			printf("O aluno %i foi reprovado\n", (c + 1));
		}
	}

	for (e = 0; e < n_alunos; e++) {
		media_geral += ficha_a[e].media;
	}
	media_geral = media_geral / n_alunos;

	printf("\nA media geral da turma foi de %f", media_geral);

	return;
}