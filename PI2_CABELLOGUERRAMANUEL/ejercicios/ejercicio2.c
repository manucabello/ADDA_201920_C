/*
 * ejercicio2.c
 *
 *  Created on: 6 dic. 2019
 *      Author: Manu Cabello
 */

#include "ejercicio2.h"

void ejercicio2(char* nombreFich) {
	iterator it = file_iterable_pchar(nombreFich);
	while (iterable_has_next(&it)) {
		char* linea = (char*) iterable_next(&it);
		iterator it = split_iterable_pchar(linea,",");
		int i = 0;
		int lista[TAM];
		while (iterable_has_next(&it)) {
			char* trozo = (char*) iterable_next(&it);
			int x = int_parse_s(trozo);
			lista[i] = x;
			i++;
		}
		printf("Entrada: %s\n",linea);
		int n = (int) sizeof(lista)/sizeof(lista[0]);
		printf("Salida: %d\n",ejercicio2_recur_gen(lista,n));
		printf("=====================================================================\n");
	}
}

int ejercicio2_recur(int* lista, int n, int i, int j) {
	if (lista[i] > lista[j]) {
		return lista[i];
	} else if (j == n-1 && lista[i] < lista[j]) {
		return lista[j];
	} else {
		return ejercicio2_recur(lista, n, i+1, j+1);
	}
}

int ejercicio2_recur_gen(int* lista, int n) {
	return ejercicio2_recur(lista, n, 0, 1);
}
