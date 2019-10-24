/*
 * ejercicio1.c
 *
 *  Created on: 20 oct. 2019
 *      Author: Manu Cabello
 */

#include <math.h>
#include "ejercicio1.h"

void ejercicio1(char* nombreFich) {
	iterator it = file_iterable_pchar(nombreFich);
	while (iterable_has_next(&it)) {
		char* linea = (char*) iterable_next(&it);
		printf("Entrada: {%s}\n",linea);

		list res = list_empty(int_type);
		res = pares_al_cuadrado(linea);

		printf("Salida: %s\n",list_tostring(&res,&res));
		printf("========================================\n");
	}
}

list pares_al_cuadrado(char* linea) {
	list res = list_empty(int_type);
	iterator it = split_iterable_pchar(linea,", ");
	while (iterable_has_next(&it)) {
		char* trozo = (char*) iterable_next(&it);
		int x = int_parse_s(trozo);
		if (x%2 == 0) {
			x = pow(x,2);
			list_add(&res,&x);
		}
	}
	return res;
}
