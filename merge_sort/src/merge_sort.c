#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "merge_sort.h"

void merge_sort(dado_t ** dados, int esquerda, int direita){
	if(esquerda < direita){
		int meio = (esquerda + direita) / 2;

		merge_sort(dados, esquerda, meio);
		merge_sort(dados, meio + 1, direita);

		funde(dados, esquerda, meio, direita);
	}
}

void funde(dado_t ** dados, int esquerda, int meio, int direita){

	dado_t *temp[direita];

	int i = esquerda;
	int j = esquerda;
	int k = meio + 1;

	while(j <= meio && k <= direita){
		if(retornar_temperatura(dados[j]) < retornar_temperatura(dados[k])){
			temp[i++] = dados[j++];
		}else{
			temp[i++] = dados[k++];
		}
	}

	while(j <= meio){
		temp[i++] = dados[j++];

	}

	for(i = esquerda; i < k; i++){
		dados[i] = temp[i];
	}
}
