#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_MAX_PLC (20)

struct lista{
	char info[20];
	struct lista *prox;
};
typedef struct lista Lista;

struct filal{
	Lista *ini;
	Lista *fim;
};
typedef struct filal FilaL;


FilaL *fila_cria_l();
void fila_insere_l(FilaL *f,char *v);
char *fila_retira_l(FilaL *f);
void fila_libera_l(FilaL *f);
int fila_vazia_l(FilaL *f);



int main(){
	FilaL *fila_l=fila_cria_l(), *fila_l_aux=fila_cria_l() ;
	char placa[TAM_MAX_PLC], buf_placa[TAM_MAX_PLC];
	int r = 0, n, t = 0, m = 0;
	Lista *q, *l;

	printf("Bem vindo ao estacionamento!!!\n");

	do
	{
		printf("\nDigite o número correspondente a ação que você deseja realizar:\n\n0-Sair do programa\n1-Entrar com um carro\n2-Retirar um carro\n3-Imprimir a ordem de saída do estacionamento\n");
		scanf("%i", &r);
		switch (r)
		{
		case 0:
		break;

		case 1:
			getchar();
			printf("\nDigite a placa do veículo (max. 20 char): ");
			fgets(placa, TAM_MAX_PLC, stdin);

			fila_insere_l(fila_l, placa);

		break;

		case 2:
			getchar();
			printf("\nDigite a placa do veículo (max. 20 char): ");
			fgets(placa, TAM_MAX_PLC, stdin);

            while(strcmp(placa, fila_l->ini->info)){
                if (fila_vazia_l(fila_l)){
                printf("Fila vazia");
                exit(1);
                }
                
                l = fila_l->ini;
                strcpy(buf_placa, l->info);
                fila_l->ini = l->prox;
                if (fila_l->ini == NULL) fila_l->fim = NULL;
                free(l);
                fila_insere_l(fila_l, buf_placa);

            }
            l = fila_l->ini;
            fila_l->ini = l->prox;
            if (fila_l->ini == NULL) fila_l->fim = NULL;
			
		break;

		case 3:

			n = 1;
			printf("\nOrdem de saída do estacionamento:\n");
			for(q=fila_l->ini; q!= NULL; q=q->prox){
				printf("%iº - Placa nº ",n);
				fputs(q->info, stdout);
		
				n++;

			} 
		break;
		
		default:
			printf("Operação inválida!!!\n");
		break;
		}

	} while (r != 0);
	

	fila_libera_l(fila_l);
}






FilaL *fila_cria_l(){
	FilaL *f = (FilaL *) malloc(sizeof(FilaL));
	f->ini = f->fim = NULL;
	return f;
}

void fila_insere_l(FilaL *f,char *v){
	Lista *n = (Lista *) malloc(sizeof(Lista));
	int i;
	for(i=0;i<20;i++) n->info[i]=v[i];
	n->prox = NULL;
	if(f->fim != NULL) f->fim->prox = n;
	else f->ini = n;
	f->fim = n;
}

char *fila_retira_l(FilaL *f){
	Lista *t;
	char *v;
	if(fila_vazia_l(f)){
		printf("Fila vazia!");
		exit(1);
	}
	t = f->ini;
	v = t->info;
	f->ini = t->prox;
	if(f->ini==NULL) f->fim = NULL;
	
	return v;
}

void fila_libera_l(FilaL *f){
	Lista *q = f->ini;
	while(q!=NULL){
		Lista *t = q->prox;
		free(q);
		q = t;
	}
	free(f);
}

int fila_vazia_l(FilaL *f){
	return (f->ini == NULL);
}