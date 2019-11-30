/*
 * ejercicio3.c
 *
 *  Created on: 11 nov. 2019
 *      Author: Manu Cabello
 */

#include "ejercicio3.h"

void ejercicio3(char* nombreFich) {
	// Solución iterativa
	iterator it = file_iterable_pchar(nombreFich);
	int cont = 0;
	int total = 0;
	while (iterable_has_next(&it)) {
		char* linea = (char*) iterable_next(&it);
		bool res = ejercicio3_itera(linea);
		printf("esPalindromoIterativa(%s)=%s\n",linea, res ? "true" : "false");
		if (res) {
			cont++;
		}
		total++;
	}
	printf("%d palíndromo de %d\n\n",cont,total);

	// Solución No Final
	it = file_iterable_pchar(nombreFich);
	cont = 0;
	total = 0;
	while (iterable_has_next(&it)) {
		char* linea = (char*) iterable_next(&it);
		bool res = ejercicio3_recur_no_final(linea,0,strlen(linea)-1);
		printf("esPalindromoNoFinal(%s)=%s\n",linea, res ? "true" : "false");
		if (res) {
			cont++;
		}
		total++;
	}
	printf("%d palíndromo de %d\n\n",cont,total);

	// Solución Final
	it = file_iterable_pchar(nombreFich);
	cont = 0;
	total = 0;
	while (iterable_has_next(&it)) {
		char* linea = (char*) iterable_next(&it);
		bool res = ejercicio3_recur_final_gen(linea);
		printf("esPalindromoFinal(%s)=%s\n",linea, res ? "true" : "false");
		if (res) {
			cont++;
		}
		total++;
	}
	printf("%d palíndromo de %d\n\n",cont,total);
}

bool ejercicio3_itera(char* cadena) {
	bool res = true;
	int i = 0;
	int j = strlen(cadena)-1;
	while (i <= j) {
		if (cadena[i] != cadena[j]) {
			res = false;
			break;
		}
		i = i+1;
		j = j-1;
	}
	return res;
}

bool ejercicio3_recur_final(char* cadena, int i, int j, bool w) {
	if (i >= j) {
		return w;
	} else {
		return ejercicio3_recur_final(cadena,i+1,j-1, w && cadena[i] == cadena[j]);
	}
}

bool ejercicio3_recur_final_gen(char* cadena) {
	return ejercicio3_recur_final(cadena,0,strlen(cadena)-1,true);
}

bool ejercicio3_recur_no_final(char* cadena, int i, int j) {
	if (i >= j) {
		return cadena[i] == cadena[j];
	} else {
		return ejercicio3_recur_no_final(cadena, i+1, j-1) && cadena[i] == cadena[j];
	}
}
