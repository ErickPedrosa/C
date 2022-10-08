/*Criador: Erick Pedrosa Barreto
 *Data: 01/09/21
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

typedef uint16_t counter;


//Cabeçalho das sub-rotinas;
ingredientes* inicializa_ingredientes(ingredientes*);
void imprime_ingredientes(ingredientes*);
void linha(int);
receitas** le_receitas(ingredientes*, receitas**);
void imprime_receitas(receitas**, ingredientes*, int);



//Função principal
int main(int argc, char** argv) {

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
	return SUCESSO;
}



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