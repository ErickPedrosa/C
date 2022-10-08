#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
	FilaL *fila_l=fila_cria_l();
	Fila *fila_v=fila_cria_vet();
	float i;

	for(i=0;i<10;i++){
		fila_insere_l(fila_l, "Lista");
		fila_insere_vet(fila_v, i);
	}

	fila_imprime_l(fila_l);
	fila_imprime_vet(fila_v);

	fila_retira_l(fila_l);
	fila_retira_vet(fila_v);

	fila_imprime_l(fila_l);
	fila_imprime_vet(fila_v);

	while((fila_vazia_l(fila_l))==0){
		fila_retira_l(fila_l);
	}

	fila_imprime_l(fila_l);

	fila_libera_l(fila_l);
	fila_libera_vet(fila_v);
}
