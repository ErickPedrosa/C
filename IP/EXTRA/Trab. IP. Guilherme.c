#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define qnt_ing
#define limite_ing (30)
#define ing_pre_cad 25
#define limite_tam 20
#define SUCESSO 0

struct ingredientes_s
{
	char nome_ing[limite_ing];
	int codigo;
};

struct receitas_s
{
	char nome_rec[limite_ing];
	int cod_rec;
	int cod_ing_rec[limite_ing];
};

int main(int argc, char** argv)
{
	ingredientes_s* ingredientes;

	ingredientes = (ingredientes_s*)malloc(sizeof(ingredientes_s) * 30);
	memcpy(ingredientes[0].nome_ing, "Massa de tomate", 16);
	memcpy(ingredientes[1].nome_ing, "Extrato de tomate", 18 );
	memcpy(ingredientes[2].nome_ing, "Presunto", 9);
	memcpy(ingredientes[3].nome_ing, "Mucarela", 9);
	memcpy(ingredientes[4].nome_ing, "Queijo", 7);
	memcpy(ingredientes[5].nome_ing, "Sal", 4);
	memcpy(ingredientes[6].nome_ing, "Catupiry", 9);
	memcpy(ingredientes[7].nome_ing, "Requeijao", 10);
	memcpy(ingredientes[8].nome_ing, "Provolone", 10);
	memcpy(ingredientes[9].nome_ing, "Bacon", 6);
	memcpy(ingredientes[10].nome_ing, "Linguica", 9);
	memcpy(ingredientes[11].nome_ing, "Carne desfiada TEMPERADA", 25);
	memcpy(ingredientes[12].nome_ing, "Pimentão", 9);
	memcpy(ingredientes[13].nome_ing, "Cebola", 7);
	memcpy(ingredientes[14].nome_ing, "Tomate", 7);
	memcpy(ingredientes[15].nome_ing, "Oregano", 8);
	memcpy(ingredientes[16].nome_ing, "Molho da casa", 14);
	memcpy(ingredientes[17].nome_ing, "katchup", 8);
	memcpy(ingredientes[18].nome_ing, "maionese", 9);
	memcpy(ingredientes[19].nome_ing, "Sorvete chocolate", 18);
	memcpy(ingredientes[20].nome_ing, "Cobertura chocolate",20 );
	memcpy(ingredientes[21].nome_ing, "Cobertura morango", 18);
	memcpy(ingredientes[22].nome_ing, "Cobertura baunilha", 19 );
	memcpy(ingredientes[23].nome_ing, "Granulado", 10);
	memcpy(ingredientes[24].nome_ing, "Canudo de chocolate", 20);
	// ok até aqui, guardou os nome dos ingredientes


	int i;

	for (i = 0; i <= 24; i++)
	{
	ingredientes[i].codigo = i+1;
	}
	// ok até aqui, guardou os codigos dos ingredientes

	int continuar;

	printf("Deseja adicionar algum ingrediente a lista?\n(0) nao\n(1) sim\n");
	scanf("%d", &continuar);



	while (continuar == 1)
	{
		printf("Digite o ingrediente %d  ", i);
		getchar();
		fgets(ingredientes[i].nome_ing, limite_ing, stdin);
		i++;

		printf("Deseja adicionar algum ingrediente a lista?\n(0) nao\n(1) sim\n");
		scanf("%d", &continuar);
	};//até aqui cadastrou os ingredientes do usuario


	int n_ingredientes = i - 1;

	for (i = n_ingredientes; i > 24; i--)
	{
		ingredientes[i].codigo = i + 1;
	}//até aqui cadastrou o codigo dos ingredientes fornecidos pelo usuario


	for (i = 0; i <= n_ingredientes; i++)
	{
		printf("%d %s\n", ingredientes[i].codigo , ingredientes[i].nome_ing);
	}//até aqui imprimiu os ingredientes por ordem de criação
	

	receitas_s* receitas;
	continuar = 1;
	i = 0;
	int j, ing_qnt;

	printf("Deseja cadastrar alguma receita:\n(1) sim\n(0) nao    ");
	scanf("%d", &continuar);

	while (continuar == 1)
	{
		printf("Digite o nome da receita:");
		getchar();
		fgets(receitas[i].nome_rec, limite_tam, stdin);
		receitas[i].cod_rec = (i * 100);
		printf("Quantos ingredientes deseja adicionar na receita:");
		scanf("%d", &ing_qnt);
		i++;
		
		for (j = 0; j < ing_qnt; j++)
		{
			printf("Digite o codigo do %d ingrediente", j + 1);
			scanf("%d", receitas[j].cod_ing_rec[i]);
		}
		printf("Deseja cadastrar uma nova receita");
		scanf("%d", &continuar);
	}

	for (i = 0; i < 3; i++)
	{
		printf("%d %s", receitas[i].cod_rec, receitas[i].nome_rec);
		for (j = 0; j < ing_qnt; j++)
		{
			printf("%d", receitas[i].cod_ing_rec[j]);
		}
	}

	return SUCESSO;
}