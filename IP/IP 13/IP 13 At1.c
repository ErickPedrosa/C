/*Criador: Erick Pedrosa Barreto
 *Data:
 *Descrição: ;
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SUCESSO 0
#define TAM_MAX_NOME (100 + 1)
#define TAM_MAX_CURSO (50 + 1)

typedef unsigned int counter;
typedef struct aluno_s {
	char nome[TAM_MAX_NOME];
	char curso[TAM_MAX_CURSO];
	unsigned int idade;
} aluno;

void le_estrutura(aluno*, uint32_t);
void imprime_estrutura(aluno*, uint32_t);

int main(int argc, char** argv) {

	aluno* ficha_alunos;
	uint32_t num_alunos = 0;

	printf("Digite o numero de alunos:");
	scanf("%u", &num_alunos);

	ficha_alunos = (aluno*)malloc(num_alunos * sizeof(aluno));

	le_estrutura(ficha_alunos, num_alunos);
	imprime_estrutura(ficha_alunos, num_alunos);


	free(ficha_alunos);
	return SUCESSO;
}

void le_estrutura(aluno* ficha_a, uint32_t n_alunos) {
	counter i;

	for (i = 0; i < n_alunos; i++) {
		printf("Aluno %i", (i + 1));

		printf("\nDigite o nome do aluno %i:", (i + 1));
		fgets(ficha_a[i].nome, TAM_MAX_NOME, stdin); //Usei a mesma função duas vezes pq estava atribuindo 
		fgets(ficha_a[i].nome, TAM_MAX_NOME, stdin); //  '\0' sem eu poder digitar;

		printf("\nDigite o curso do aluno %i:", (i + 1));
		fgets(ficha_a[i].curso, TAM_MAX_CURSO, stdin);

		printf("\nDigite a idade do aluno %i:", (i + 1));
		scanf("%u", &ficha_a[i].idade);
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

	return;
}