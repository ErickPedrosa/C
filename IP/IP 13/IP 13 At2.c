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
typedef struct aluno_2_s {
	char nome[TAM_MAX_NOME];
	char curso[TAM_MAX_CURSO];
	unsigned int idade;
	float provas[NUM_DE_PROVAS];
} aluno_2;

void le_estrutura(aluno_2*, uint32_t);
void imprime_estrutura(aluno_2*, uint32_t);
void imprime_media(aluno_2*, counter);

int main(int argc, char** argv) {

	aluno_2* ficha_aluno_2s;
	uint32_t num_aluno_2s = 0;

	printf("Digite o numero de aluno_2s: ");
	scanf("%u", &num_aluno_2s);

	ficha_aluno_2s = (aluno_2*)malloc(num_aluno_2s * sizeof(aluno_2));

	le_estrutura(ficha_aluno_2s, num_alunos);
	imprime_estrutura(ficha_aluno_2s, num_aluno_2s);


	free(ficha_aluno_2s);
	return SUCESSO;
}

void le_estrutura(aluno_2* ficha_a, uint32_t n_aluno_2s) {
	counter i, k;

	for (i = 0; i < n_aluno_2s; i++) {
		printf("\naluno_2 %i", (i + 1));

		printf("\nDigite o nome do aluno_2 %i: ", (i + 1));
		fgets(ficha_a[i].nome, TAM_MAX_NOME, stdin); //Usei a mesma função duas vezes pq estava atribuindo 
		fgets(ficha_a[i].nome, TAM_MAX_NOME, stdin); //  '\0' sem eu poder digitar;

		printf("\nDigite o curso do aluno_2 %i: ", (i + 1));
		fgets(ficha_a[i].curso, TAM_MAX_CURSO, stdin);

		printf("\nDigite a idade do aluno_2 %i: ", (i + 1));
		scanf("%u", &ficha_a[i].idade);

		for (k = 0; k < NUM_DE_PROVAS; k++) {

			printf("\nDigite a nota do aluno_2 %i na prova %i: ", i, k);
			scanf("%f", &ficha_a[i].provas[k]);
		}
	}

	return;
}


void imprime_estrutura(aluno_2* ficha_a, uint32_t n_aluno_2s) {
	counter j;

	for (j = 0; j < n_aluno_2s; j++) {
		printf("\naluno_2 %i:\n", (j + 1));
		fputs(ficha_a[j].nome, stdout);
		fputs(ficha_a[j].curso, stdout);
		printf("%u\n", ficha_a[j].idade);
		imprime_media(ficha_a, j);
	}

	return;
}

void imprime_media(aluno_2* ficha_a, counter indice_do_vetor) {
	float resultado = 0;
	counter a;

	for (a = 0; a < NUM_DE_PROVAS; a++) {
		resultado += ficha_a[indice_do_vetor].provas[a];
	}
	resultado = resultado / NUM_DE_PROVAS;

	if (resultado >= INDICE_DE_APROVACAO) {
		printf("A media do aluno_2 %i foi %f", indice_do_vetor, resultado);
		printf("O aluno_2 %i foi aprovado", indice_do_vetor);
	} else {
		printf("A media do aluno_2 %i foi %f", indice_do_vetor, resultado);
		printf("O aluno_2 %i foi reprovado", indice_do_vetor);
	}

	return;
}