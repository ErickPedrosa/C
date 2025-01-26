/*
* Trabalho Prático de PDS 1
* Nome: Laura Maria Clemente Avidago Occhi                                    
* Matrícula: 2024013605
*/


// Importação das Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Função que calcula o multiplicador de dano do ataque do pokemon;
float danoAtaque(char* pkmnDefensor, char* pkmnAtacante) { 

	if (strstr(pkmnAtacante, "Fogo"))
	{
		if (strstr(pkmnDefensor, "Gelo"))
		{
			return (1.0 + 0.2); //Super-efetivo;
		}
		else if (strstr(pkmnDefensor, "Agua"))
		{
			return (1.0 - 0.2); //Nao-efetivo;
		}
	}

	if (strstr(pkmnAtacante, "Agua"))
	{
		if (strstr(pkmnDefensor, "Fogo"))
		{
			return (1.0 + 0.2); //Super-efetivo;
		}
		else if (strstr(pkmnDefensor, "Eletrico"))
		{
			return (1.0 - 0.2); //Nao-efetivo;
		}
			}

	if (strstr(pkmnAtacante, "Eletrico"))
	{
		if (strstr(pkmnDefensor, "Agua"))
		{
			return (1.0 + 0.2); //Super-efetivo;
		}
		else if (strstr(pkmnDefensor, "Pedra"))
		{
			return (1.0 - 0.2); //Nao-efetivo;
		}
		
	}

	if (strstr(pkmnAtacante, "Gelo"))
	{
		if (strstr(pkmnDefensor, "Pedra"))
		{
			return (1.0 + 0.2); //Super-efetivo;
		}
		else if (strstr(pkmnDefensor, "Fogo"))
		{
			return (1.0 - 0.2); //Nao-efetivo;
		}
		
	}

	if (strstr(pkmnAtacante, "Pedra"))
	{
		if (strstr(pkmnDefensor, "Eletrico"))
		{
			return (1.0 + 0.2); //Super-efetivo;
		}
		else if (strstr(pkmnDefensor, "Gelo"))
		{
			return (1.0 - 0.2); //Nao-efetivo;
		}
		
	}

	return 1.0; //Ataque normal;
}


int main(int argc, char** argv) {

	FILE* arqv = fopen("Pokemon.txt", "r"); //Abrindo o arquivo de entrada que contém os dados dos pokémons;
	if (arqv == NULL)
	{
		exit(-1);
	}

	//Lendo o número de pokemons de cada equipe;
	int n_pokemons_equipe1, n_pokemons_equipe2;
	fscanf(arqv, "%d %d", &n_pokemons_equipe1, &n_pokemons_equipe2);
	printf("%d %d\n", n_pokemons_equipe1, n_pokemons_equipe2);


	//Declarando as variáveis que vão conter os dados dos pokemons do jogador 1;
	char **jogador1_nome_pkmn, **tipo_pkmn;
	int *jogador1_ataque_pkmn, *jogador1_defesa_pkmn, *jogador1_vida_pkmn;

	jogador1_nome_pkmn = (char**)calloc(n_pokemons_equipe1, sizeof(char*));
	tipo_pkmn = (char**)calloc(n_pokemons_equipe1, sizeof(char*));

	//Alocando o espaço para os pokemons;
	for (int i = 0; i < n_pokemons_equipe1; i++)
	{
		jogador1_nome_pkmn[i] = (char*)malloc(21 * sizeof(char)); //Tamanho maximo do nome do pokemon
		tipo_pkmn[i] = (char*)malloc(11 * sizeof(char)); //Tamanho maximo do tipo
	}

	jogador1_ataque_pkmn = (int*)calloc(n_pokemons_equipe1, sizeof(int));
	jogador1_defesa_pkmn = (int*)calloc(n_pokemons_equipe1, sizeof(int));
	jogador1_vida_pkmn = (int*)calloc(n_pokemons_equipe1, sizeof(int));

	//Lendo do arquivo e guardando os dados nas variáveis;
	for (int i = 0; i < n_pokemons_equipe1; i++)
	{
		fscanf(arqv, "%s", jogador1_nome_pkmn[i]);
		fscanf(arqv, "%d", &jogador1_ataque_pkmn[i]);
		fscanf(arqv, "%d", &jogador1_defesa_pkmn[i]);
		fscanf(arqv, "%d", &jogador1_vida_pkmn[i]);
		fscanf(arqv, "%s", tipo_pkmn[i]);

		printf("%s %d %d %d %s\n", jogador1_nome_pkmn[i], jogador1_ataque_pkmn[i], jogador1_defesa_pkmn[i], jogador1_vida_pkmn[i], tipo_pkmn[i]);
	}
	printf("\n");

	
	//Fazendo o mesmo para o jogador 2;
	char** jogador2_nome_pkmn, ** tipo_pkmn2;
	int* jogador2_ataque_pkmn, * jogador2_defesa_pkmn, * jogador2_vida_pkmn;

	jogador2_nome_pkmn = (char**)calloc(n_pokemons_equipe2, sizeof(char*));
	tipo_pkmn2 = (char**)calloc(n_pokemons_equipe2, sizeof(char*));

	for (int i = 0; i < n_pokemons_equipe2; i++)
	{
		jogador2_nome_pkmn[i] = (char*)malloc(21 * sizeof(char)); //Tamanho maximo do nome do pokemon
		tipo_pkmn2[i] = (char*)malloc(11 * sizeof(char)); //Tamanho maximo do tipo
	}

	jogador2_ataque_pkmn = (int*)calloc(n_pokemons_equipe2, sizeof(int));
	jogador2_defesa_pkmn = (int*)calloc(n_pokemons_equipe2, sizeof(int));
	jogador2_vida_pkmn = (int*)calloc(n_pokemons_equipe2, sizeof(int));


	for (int i = 0; i < n_pokemons_equipe2; i++)
	{
		fscanf(arqv, "%s", jogador2_nome_pkmn[i]);
		fscanf(arqv, "%d", &jogador2_ataque_pkmn[i]);
		fscanf(arqv, "%d", &jogador2_defesa_pkmn[i]);
		fscanf(arqv, "%d", &jogador2_vida_pkmn[i]);
		fscanf(arqv, "%s", tipo_pkmn2[i]);

		printf("%s %d %d %d %s\n", jogador2_nome_pkmn[i], jogador2_ataque_pkmn[i], jogador2_defesa_pkmn[i], jogador2_vida_pkmn[i], tipo_pkmn2[i]);
	}
	printf("\n");


	int i = 0, j = 0; //Guarda o pokemon atual;

	while (1) // Loop infinito para simular a batalha
	{
		// Jogador 1 ataca o Pokémon atual de Jogador 2
		float dano_jogador1 = danoAtaque(tipo_pkmn2[j], tipo_pkmn[i]);
		float dano_causado_jogador1 = fmax(1, (jogador1_ataque_pkmn[i] * dano_jogador1) - jogador2_defesa_pkmn[j]);


		jogador2_vida_pkmn[j] -= dano_causado_jogador1;
		printf("%s ataca %s! Causou %f de dano.\n", jogador1_nome_pkmn[i], jogador2_nome_pkmn[j], dano_causado_jogador1);

		// Verifica se o Pokémon de Jogador 2 foi derrotado
		if (jogador2_vida_pkmn[j] <= 0)
		{
			printf("\n%s foi derrotado!\n\n", jogador2_nome_pkmn[j]);
			j++;
			if (j >= n_pokemons_equipe2)
			{
				printf("Jogador 1 venceu a batalha!\n");
				break;
			}
		}

		// Jogador 2 ataca o Pokémon atual de Jogador 1
		float dano_jogador2 = danoAtaque(tipo_pkmn[i], tipo_pkmn2[j]);
		float dano_causado_jogador2 = fmax(1, jogador2_ataque_pkmn[j] * dano_jogador2) - jogador1_defesa_pkmn[i];

		
		jogador1_vida_pkmn[i] -= dano_causado_jogador2;
		printf("%s ataca %s! Causou %f de dano.\n", jogador2_nome_pkmn[j], jogador1_nome_pkmn[i], dano_causado_jogador2);

		// Verifica se o Pokémon de Jogador 1 foi derrotado
		if (jogador1_vida_pkmn[i] <= 0)
		{
			printf("\n%s foi derrotado!\n\n", jogador1_nome_pkmn[i]);
			i++;
			if (i >= n_pokemons_equipe1)
			{
				printf("Jogador 2 venceu a batalha!\n");
				break;
			}
		}
	}

	// Imprime resultados finais
	printf("\n\nResultado final:\n");
	printf("Pokémons derrotados de Jogador 1:\n");
	for (int k = 0; k < n_pokemons_equipe1; k++)
	{
		if (jogador1_vida_pkmn[k] <= 0)
		{
			printf("- %s\n", jogador1_nome_pkmn[k]);
		}
	}

	printf("Pokémons sobreviventes de Jogador 1:\n");
	for (int k = 0; k < n_pokemons_equipe1; k++)
	{
		if (jogador1_vida_pkmn[k] > 0)
		{
			printf("- %s (Vida: %d)\n", jogador1_nome_pkmn[k], jogador1_vida_pkmn[k]);
		}
	}

	printf("Pokémons derrotados de Jogador 2:\n");
	for (int k = 0; k < n_pokemons_equipe2; k++)
	{
		if (jogador2_vida_pkmn[k] <= 0)
		{
			printf("- %s\n", jogador2_nome_pkmn[k]);
		}
	}

	printf("Pokémons sobreviventes de Jogador 2:\n");
	for (int k = 0; k < n_pokemons_equipe2; k++)
	{
		if (jogador2_vida_pkmn[k] > 0)
		{
			printf("- %s (Vida: %d)\n", jogador2_nome_pkmn[k], jogador2_vida_pkmn[k]);
		}
	}

	//Fecha o arquivo;
	fclose(arqv);

	//Desaloca todos os ponteiros;
	for (int i = 0; i < n_pokemons_equipe1; i++) {
		free(jogador1_nome_pkmn[i]);
		free(tipo_pkmn[i]);
	}
	for (int i = 0; i < n_pokemons_equipe2; i++) {
		free(jogador2_nome_pkmn[i]);
		free(tipo_pkmn2[i]);
	}
	free(jogador1_ataque_pkmn);
	free(jogador1_nome_pkmn);
	free(jogador1_defesa_pkmn);
	free(tipo_pkmn);
	free(jogador1_vida_pkmn);
	free(jogador2_ataque_pkmn);
	free(jogador2_nome_pkmn);
	free(jogador2_defesa_pkmn);
	free(tipo_pkmn2);
	free(jogador2_vida_pkmn);

	return 0;
}


