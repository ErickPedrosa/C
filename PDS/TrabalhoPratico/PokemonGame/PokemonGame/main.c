#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>


#define SUCESSO 0
#define ERRO -1
#define TRUE 1

#define TIPO_FOGO 1
#define TIPO_AGUA 2
#define TIPO_ELETRICO 3
#define TIPO_GELO 4
#define TIPO_PEDRA 5
#define TIPO_NAO_ENCONTRADO -2

#define NORMAL 1
#define SUPEREFETIVO 1.2
#define NAOEFETIVO 0.8

#define TAM_MAX_NOME (40 + 1)
#define TAM_MAX_TIPO (10 + 1)
#define TAM_MAX_PRIMEIRA_LINHA (4 + 1)


typedef struct pokemonCompleto {
	char nome[TAM_MAX_NOME];
	int ataque;
	int defesa;
	int vida;
	char tipo[TAM_MAX_TIPO];

} pokemon;



float verificaDano(int tipoAtaque, int tipoDefesa);
int verificaTipo(char* tipo);


int main(int argc, char** argv) {

	//Variáveis do programa;
	FILE* arquivoPkmn = fopen("Pokemons.txt", "r");
	char n_pokemons_equipe1[TAM_MAX_PRIMEIRA_LINHA], n_pokemons_equipe2[TAM_MAX_PRIMEIRA_LINHA];
	pokemon *equipe1, *equipe2;

	//Erro em encontrar e abrir o arquivo;
	if (arquivoPkmn == NULL)
	{
		printf("ERRO: ARQUIVO NAO ENCONTRADO!!!");
		return ERRO;
	}

	//Leitura da primeira linha (quantidade de pokemons de cada equipe);
	fscanf(arquivoPkmn, "%s", n_pokemons_equipe1);
	fscanf(arquivoPkmn, "%s", n_pokemons_equipe2);
	printf("%s %s\n", n_pokemons_equipe1, n_pokemons_equipe2);

	//Alocação da equipe 1;
	equipe1 = (pokemon*)calloc(atoi(n_pokemons_equipe1), sizeof(pokemon));

	printf("\nEquipe 1: \n");
	for (int i = 0; i < atoi(n_pokemons_equipe1); i++)
	{
		fscanf(arquivoPkmn, "%s", equipe1[i].nome);
		fscanf(arquivoPkmn, "%d", &equipe1[i].ataque);
		fscanf(arquivoPkmn, "%d", &equipe1[i].defesa);
		fscanf(arquivoPkmn, "%d", &equipe1[i].vida);
		fscanf(arquivoPkmn, "%s", equipe1[i].tipo);

		printf("%s %d %d %d %s\n", equipe1[i].nome, equipe1[i].ataque, equipe1[i].defesa, equipe1[i].vida, equipe1[i].tipo);
	}

	//Alocação da equipe 2;
	equipe2 = (pokemon*)calloc(atoi(n_pokemons_equipe2), sizeof(pokemon));

	printf("\nEquipe 2: \n");
	for (int i = 0; i < atoi(n_pokemons_equipe2); i++)
	{
		fscanf(arquivoPkmn, "%s", equipe2[i].nome);
		fscanf(arquivoPkmn, "%d", &equipe2[i].ataque);
		fscanf(arquivoPkmn, "%d", &equipe2[i].defesa);
		fscanf(arquivoPkmn, "%d", &equipe2[i].vida);
		fscanf(arquivoPkmn, "%s", equipe2[i].tipo);

		printf("%s %d %d %d %s\n", equipe2[i].nome, equipe2[i].ataque, equipe2[i].defesa, equipe2[i].vida, equipe2[i].tipo);
	}


	//Inicio da batalha;
	int i = 0, j = 0;
	float dano = 1;
	printf("\n\nInicio da batalha:\n");

	do
	{

		//Primeiro jogador ataca;

		//Verifica o superefetivo;
		dano = verificaDano(verificaTipo(equipe1[i].tipo), verificaTipo(equipe2[j].tipo));

		//Verifica o dano causado;
		if ((equipe1[i].ataque * dano) <= equipe2[j].defesa)
		{
			equipe2[j].vida = equipe2[j].vida - 1;
		}
		else
		{ 
			equipe2[j].vida = equipe2[j].vida - ((equipe1[i].ataque * dano) - equipe2[j].defesa);
		}

		//Verifica se o pokemon ainda esta vivo;
		if (equipe2[j].vida <= 0)
		{
			printf("%s venceu %s\n", equipe1[i], equipe2[j]);

			j++;

			//Verifica se o jogador 2 possui mais pokemons;
			if (j >= atoi(n_pokemons_equipe2))
			{
				printf("\n\nJogador 1 Venceu\n");
				printf("\nPokemons Sobreviventes:\n");

				for (int k = i; k < atoi(n_pokemons_equipe1); k++)
				{
					printf("%s\n", equipe1[k].nome);
				}

				printf("\nPokemons Derrotados:\n");
				for (int k = 0; k < i; k++)
				{
					printf("%s\n", equipe1[k].nome);
				}
				for (int k = 0; k < atoi(n_pokemons_equipe2); k++)
				{
					printf("%s\n", equipe2[k].nome);
				}
				

				break;
			}
		}



		//Segundo jogador ataca;

		//Verifica o superefetivo;
		dano = verificaDano(verificaTipo(equipe2[j].tipo), verificaTipo(equipe1[i].tipo));

		//Verifica o dano causado;
		if ((equipe2[j].ataque * dano) <= equipe1[i].defesa)
		{
			equipe1[i].vida = equipe1[i].vida - 1;
		}
		else
		{
			equipe1[i].vida = equipe1[i].vida - ((equipe2[j].ataque * dano) - equipe1[i].defesa);
		}

		//Verifica se o pokemon ainda esta vivo;
		if (equipe1[i].vida <= 0)
		{
			printf("%s venceu %s\n", equipe2[j],equipe1[i]);


			i++;

			//Verifica se o jogador 1 possui mais pokemons;
			if (i >= atoi(n_pokemons_equipe1))
			{
				printf("\n\nJogador 2 Venceu\n");
				printf("\nPokemons Sobreviventes:\n");

				for (int k = j; k < atoi(n_pokemons_equipe2); k++)
				{
					printf("%s\n", equipe2[k].nome);
				}

				printf("\nPokemons Derrotados:\n");
				for (int k = 0; k < j; k++)
				{
					printf("%s\n", equipe2[k].nome);
				}
				for (int k = 0; k < atoi(n_pokemons_equipe1); k++)
				{
					printf("%s\n", equipe1[k].nome);
				}
				

				break;
			}
		}



	} while (TRUE);





	//Fechamento do arquivo e desalocação;
	fclose(arquivoPkmn);
	free(equipe1);
	free(equipe2);

	return SUCESSO;
}



float verificaDano(int tipoAtaque, int tipoDefesa) {

	if (tipoAtaque == TIPO_FOGO)
	{
		if (tipoDefesa == TIPO_GELO)
		{
			return SUPEREFETIVO;
		}
		else if(tipoDefesa == TIPO_AGUA)
		{
			return NAOEFETIVO;
		}
		else
		{
			return NORMAL;
		}

	}

	if (tipoAtaque == TIPO_AGUA)
	{
		if (tipoDefesa == TIPO_FOGO)
		{
			return SUPEREFETIVO;
		}
		else if (tipoDefesa == TIPO_ELETRICO)
		{
			return NAOEFETIVO;
		}
		else
		{
			return NORMAL;
		}

	}

	if (tipoAtaque == TIPO_ELETRICO)
	{
		if (tipoDefesa == TIPO_AGUA)
		{
			return SUPEREFETIVO;
		}
		else if (tipoDefesa == TIPO_PEDRA)
		{
			return NAOEFETIVO;
		}
		else
		{
			return NORMAL;
		}

	}

	if (tipoAtaque == TIPO_GELO)
	{
		if (tipoDefesa == TIPO_PEDRA)
		{
			return SUPEREFETIVO;
		}
		else if (tipoDefesa == TIPO_FOGO)
		{
			return NAOEFETIVO;
		}
		else
		{
			return NORMAL;
		}

	}

	if (tipoAtaque == TIPO_PEDRA)
	{
		if (tipoDefesa == TIPO_ELETRICO)
		{
			return SUPEREFETIVO;
		}
		else if (tipoDefesa == TIPO_GELO)
		{
			return NAOEFETIVO;
		}
		else
		{
			return NORMAL;
		}

	}


}

int verificaTipo(char* tipo) {

	if (strstr(tipo, "fogo") != NULL)
	{
		return TIPO_FOGO;
	}
	if (strstr(tipo, "agua") != NULL)
	{
		return TIPO_AGUA;
	}
	if (strstr(tipo, "eletrico") != NULL)
	{
		return TIPO_ELETRICO;
	}
	if (strstr(tipo, "gelo") != NULL)
	{
		return TIPO_GELO;

	}
	if (strstr(tipo, "pedra") != NULL )
	{
		return TIPO_PEDRA;
	}

	return TIPO_NAO_ENCONTRADO;
}