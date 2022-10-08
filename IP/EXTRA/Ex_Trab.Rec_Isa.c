/*Criador: Erick Pedrosa Barreto
 *Data: 
 *Descrição: ;
*/


//Inclusões;
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>


//Definições de constantes;
#define SUCESSO 0
#define TAM_MAX_INGREDIENTE  20
#define NUM_DE_INGREDIENTES  25
#define TAM_LINHA 100
#define TAM_MAX_NOME  (100 + 1)
#define TAM_MAX_CURSO  (50 + 1)
#define NUM_DE_PROVAS  3
#define INDICE_DE_APROVACAO  60


//Criando as estruturas;
typedef struct ingredientes_s {
	char nome_ingrediente[TAM_MAX_INGREDIENTE];
	int quantidade;
} ingredientes;

typedef struct lista_de_receitas {
	int n_de_receitas = 0;
	int codigo_ingrediente;
	int quantidade_ingrediente;
} receitas;

typedef struct aluno_s {
	char nome[TAM_MAX_NOME];
	char curso[TAM_MAX_CURSO];
	unsigned int idade;
} aluno;

typedef struct aluno_2_s {
	char nome[TAM_MAX_NOME];
	char curso[TAM_MAX_CURSO];
	unsigned int idade;
	float provas[NUM_DE_PROVAS];
} aluno_2;

typedef uint16_t counter;


//Cabeçalho das sub-rotinas;
ingredientes* inicializa_ingredientes(ingredientes*);
void imprime_ingredientes(ingredientes*);
void linha(int);
receitas** le_receitas(ingredientes*, receitas**);
void imprime_receitas(receitas**, ingredientes*, int);
void trabalho_pratico_II(void);

void Aula_13(void);

void Aula_13_Ex1(void);
void le_estrutura(aluno*, uint32_t);
void imprime_estrutura(aluno*, uint32_t);

void Aula_13_Ex2(void);
void le_estrutura_2(aluno_2*, uint32_t);
void imprime_estrutura_2(aluno_2*, uint32_t);
void imprime_media_2(aluno_2*, counter);



//Função principal
int main(int argc, char** argv) {
	int escolha = 0;

	printf("\nMENU ESCOLHA DA AULA\n\n");
	do
	{
		printf("Digite a aula que voce deseja:\n\n");
		printf("01\tTrab. Pratico\n02\tAula 13\n");
		scanf("%i", &escolha);
		switch (escolha)
		{
		case 1:
			trabalho_pratico_II();
		break;
		case 2:
			Aula_13();
			break;
		default:
			break;
		}
	} while (escolha > 0 && escolha < 3);



	return SUCESSO;
}


//Menu Aula 13 exercicios;
void Aula_13(void) {
	printf("\nMENU ESCOLHA DO EXERCICIO\n");

	int escolha = 0;

	do
	{
		printf("Digite o exercicio que voce deseja:\n\n");
		printf("01\tExercicio 1\n02\tExercicio 2\n");
		scanf("%i", &escolha);
		switch (escolha)
		{
		case 1:
			Aula_13_Ex1();
				break;
		case 2:
			Aula_13_Ex2();
			break;
		default:
			break;
		}
	} while (escolha >= 0 && escolha < 3);

	return;
}

void Aula_13_Ex1(void) {
	printf("\nEXERCICIO 1 - AULA 13\n");

	aluno* ficha_alunos;
	uint32_t num_alunos = 0;

	printf("Digite o numero de alunos:");
	scanf("%u", &num_alunos);

	ficha_alunos = (aluno*)malloc(num_alunos * sizeof(aluno));

	le_estrutura(ficha_alunos, num_alunos);
	imprime_estrutura(ficha_alunos, num_alunos);


	free(ficha_alunos);
	return;
}
void Aula_13_Ex2(void) {
	printf("\nEXERCICIO 2 - AULA 13\n");

	aluno_2* ficha_aluno_2s;
	uint32_t num_aluno_2s = 0;

	printf("Digite o numero de aluno_2s: ");
	scanf("%u", &num_aluno_2s);

	ficha_aluno_2s = (aluno_2*)malloc(num_aluno_2s * sizeof(aluno_2));

	le_estrutura_2(ficha_aluno_2s, num_aluno_2s);
	imprime_estrutura_2(ficha_aluno_2s, num_aluno_2s);


	free(ficha_aluno_2s);
	return;

}




void trabalho_pratico_II(void) {
	printf("\nTRABALHO PRATICO\n");


	//Declaração das variáveis;
	int resposta = 0, n_receitas;
	int num_de_receitas = 0, indice_da_receita = -1;
	ingredientes* ingredientes_v;
	receitas** receitas_v;
	counter a, b;



	//Aloca e inicializa os ingredientes;
	ingredientes_v = (ingredientes*)calloc(NUM_DE_INGREDIENTES, sizeof(ingredientes));
	ingredientes_v = inicializa_ingredientes(ingredientes_v);

	imprime_ingredientes(ingredientes_v);



	//Alocação e leitura das receitas;
	printf("\nDigite o numero de receitas:");
	scanf("%i", &num_de_receitas);

	receitas_v = (receitas**)malloc((num_de_receitas) * sizeof(receitas*));
	for (b = 0; b < num_de_receitas; b++) {
		receitas_v[b] = (receitas*)calloc(NUM_DE_INGREDIENTES, sizeof(receitas));

	}
	receitas_v[0][0].n_de_receitas = num_de_receitas;

	receitas_v = le_receitas(ingredientes_v, receitas_v);



	//Imprime a receita pedida pelo usuário;
	do {

		if (indice_da_receita != -1) {
			imprime_receitas(receitas_v, ingredientes_v, indice_da_receita);

		}

		indice_da_receita = -1;
		printf("Digite o numero da receita a ser imprimida: ");
		scanf("%i", &indice_da_receita);


	} while (indice_da_receita > 0 && indice_da_receita <= num_de_receitas);


	//Libera a memória alocada;
	n_receitas = receitas_v[0][0].n_de_receitas;
	for (a = 0; a < n_receitas; a++) {
		free(receitas_v[a]);
	}
	free(receitas_v);
	free(ingredientes_v);
	return;
}


/*
*  Inicio das subrotinas do Trabalho prático;
*/

//Essa função inicializará a variável com os ingredientes;
ingredientes* inicializa_ingredientes(ingredientes* ingredientes_v) {


	memcpy(ingredientes_v[0].nome_ingrediente, "Mussarela", 10);
	memcpy(ingredientes_v[1].nome_ingrediente, "Calabresa", 10);
	memcpy(ingredientes_v[2].nome_ingrediente, "Presunto", 9);
	memcpy(ingredientes_v[3].nome_ingrediente, "Parmesao", 9);
	memcpy(ingredientes_v[4].nome_ingrediente, "Bacon", 6);
	memcpy(ingredientes_v[5].nome_ingrediente, "Atum", 5);
	memcpy(ingredientes_v[6].nome_ingrediente, "Cebola", 7);
	memcpy(ingredientes_v[7].nome_ingrediente, "Tomate", 7);
	memcpy(ingredientes_v[8].nome_ingrediente, "Frango", 7);
	memcpy(ingredientes_v[9].nome_ingrediente, "Milho", 6);
	memcpy(ingredientes_v[10].nome_ingrediente, "Tomate", 7);
	memcpy(ingredientes_v[11].nome_ingrediente, "Ervilha", 8);
	memcpy(ingredientes_v[12].nome_ingrediente, "Champignon", 11);
	memcpy(ingredientes_v[13].nome_ingrediente, "Requeijao", 10);
	memcpy(ingredientes_v[14].nome_ingrediente, "Palmito", 8);
	memcpy(ingredientes_v[15].nome_ingrediente, "Cheddar", 8);
	memcpy(ingredientes_v[16].nome_ingrediente, "Lombo", 6);
	memcpy(ingredientes_v[17].nome_ingrediente, "Ovos", 5);
	memcpy(ingredientes_v[18].nome_ingrediente, "Almondegas", 11);
	memcpy(ingredientes_v[19].nome_ingrediente, "Azeitona", 9);
	memcpy(ingredientes_v[20].nome_ingrediente, "Pepperoni", 10);
	memcpy(ingredientes_v[21].nome_ingrediente, "Molho de pimenta", 17);
	memcpy(ingredientes_v[22].nome_ingrediente, "Molho barbecue", 15);
	memcpy(ingredientes_v[23].nome_ingrediente, "Molho verde", 12);
	memcpy(ingredientes_v[24].nome_ingrediente, "Pimentao", 9);


	return ingredientes_v;
}



//Essa função imprime uma tabela com todos os ingredientes
// e seus respectivos códigos;
void imprime_ingredientes(ingredientes* ingredientes_v) {
	counter a;

	printf("\n");
	linha(TAM_LINHA);
	linha(TAM_LINHA);
	printf("Lista de ingredientes\n");
	linha(TAM_LINHA);
	for (a = 0; a < NUM_DE_INGREDIENTES; a++)
	{
		printf("Ingrediente de codigo n. %i:\t ", a);
		fputs(ingredientes_v[a].nome_ingrediente, stdout);
		printf("\n");
	}
	linha(TAM_LINHA);
	linha(TAM_LINHA);


	return;
}



//Essa função imprime uma linha na tela;
void linha(int n_da_linha) {
	counter a;

	for (a = 1; a <= n_da_linha; a++)
	{
		putchar('*');
	}
	printf("\n");


	return;
}



//Essa função lê todas as receitas digitadas pelo usuário;
receitas** le_receitas(ingredientes* lista_ingrediente, receitas** receitas_v) {
	counter b, c = 0;


	printf("\nSe quiser parar de digitar os ingredientes digite um numero maior que %i ou menor que 0\n", NUM_DE_INGREDIENTES);

	for (b = 0; b < receitas_v[0][0].n_de_receitas; b++) {

		printf("\nReceita %i\n", (b + 1));


		while (receitas_v[b][c].codigo_ingrediente < 25 && receitas_v[b][c].codigo_ingrediente >= 0) {


			printf("\nDigite o codigo do ingrediente:");
			scanf("%i", &receitas_v[b][c].codigo_ingrediente);


			if (receitas_v[b][c].codigo_ingrediente < NUM_DE_INGREDIENTES && receitas_v[b][c].codigo_ingrediente >= 0) {

				c = receitas_v[b][c].codigo_ingrediente;
				printf("Digite a quantidade de ");
				fputs(lista_ingrediente[c].nome_ingrediente, stdout);
				printf(": ");
				scanf("%i", &receitas_v[b][c].quantidade_ingrediente);

			}

		}

	}
	printf("\n");


	return receitas_v;
}



//Essa função irá imprimir a receita pedida pelo usuário;
void imprime_receitas(receitas** receitas_v, ingredientes* ingredientes_v, int indice) {

	counter a, b;

	printf("\n\n");
	printf("\n");
	linha(TAM_LINHA);
	linha(TAM_LINHA);
	printf("Receita %i\n", indice);
	linha(TAM_LINHA);

	indice -= 1;

	for (b = 0; b < NUM_DE_INGREDIENTES; b++) {
		if (receitas_v[indice][b].quantidade_ingrediente != 0) {
			printf(" %i\t", receitas_v[indice][b].quantidade_ingrediente);
			fputs(ingredientes_v[b].nome_ingrediente, stdout);
			printf("\n");
		}
	}

	printf("\n");
	linha(TAM_LINHA);
	linha(TAM_LINHA);

	return;
}


/*
*  Inicio das subrotinas da Aula 13;
*/
//Exercicio 1;
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


//Exercicio 2;
void le_estrutura_2(aluno_2* ficha_a, uint32_t n_aluno_2s) {
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


void imprime_estrutura_2(aluno_2* ficha_a, uint32_t n_aluno_2s) {
	counter j;

	for (j = 0; j < n_aluno_2s; j++) {
		printf("\naluno_2 %i:\n", (j + 1));
		fputs(ficha_a[j].nome, stdout);
		fputs(ficha_a[j].curso, stdout);
		printf("%u\n", ficha_a[j].idade);
		imprime_media_2(ficha_a, j);
	}

	return;
}

void imprime_media_2(aluno_2* ficha_a, counter indice_do_vetor) {
	float resultado = 0;
	counter a;

	for (a = 0; a < NUM_DE_PROVAS; a++) {
		resultado += ficha_a[indice_do_vetor].provas[a];
	}
	resultado = resultado / NUM_DE_PROVAS;

	if (resultado >= INDICE_DE_APROVACAO) {
		printf("A media do aluno_2 %i foi %f", indice_do_vetor, resultado);
		printf("O aluno_2 %i foi aprovado", indice_do_vetor);
	}
	else {
		printf("A media do aluno_2 %i foi %f", indice_do_vetor, resultado);
		printf("O aluno_2 %i foi reprovado", indice_do_vetor);
	}

	return;
}