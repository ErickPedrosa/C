#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define SUCESSO 0
#define TAM_MAX_NOME (100 + 1)

typedef uint16_t counter;

typedef struct modulo_ingredientes {

	int codigo;
	char* nome;


} mod_ingredientes;

typedef struct modulo_receitas {

	int codigo;
	char* nome;
	tm data_de_criação;
	float preco;
	mod_ingredientes * ingredientes_receita;

} mod_receitas;


int main(int argc, char** argv) {

	char buffer_nome[TAM_MAX_NOME];
	mod_receitas rec;

	fgets(buffer_nome, TAM_MAX_NOME , stdin);
	rec.nome = buffer_nome;




	return SUCESSO;
}