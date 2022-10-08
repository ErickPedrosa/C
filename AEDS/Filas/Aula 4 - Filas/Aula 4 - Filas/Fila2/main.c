#include <stdio.h>
#include <stdlib.h>
#include "fila2.h"

int main(){
	Fila2 *fila_v=fila_cria_vet();
	FilaL2 *fila_l=fila_cria_l();
	float i;

	for(i=0;i<10;i++){
		fila_insere_vet(fila_v, i);
		fila_insere_l(fila_l, "FilaL2");
	}

	fila_imprime_vet(fila_v);
	fila_imprime_l(fila_l);

	fila_insere_ini_vet(fila_v, 11.0);
	fila_retira_fim_vet(fila_v);

	fila_insere_ini_l(fila_l, "Primeiro");
	fila_retira_fim_l(fila_l);

	fila_imprime_vet(fila_v);
	fila_imprime_l(fila_l);

	fila_libera_vet(fila_v);
	fila_libera_l(fila_l);	

	return 0;
}
