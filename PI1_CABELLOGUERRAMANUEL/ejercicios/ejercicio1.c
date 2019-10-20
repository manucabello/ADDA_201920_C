/*
 * ejercicio1.c
 *
 *  Created on: 20 oct. 2019
 *      Author: Manu Cabello
 */

#include <math.h>
#include "ejercicio1.h"

list leerFichero(const char* nombreFich) {
	list res = list_empty(int_type);				// Crear una lista vacia
	iterator it = file_iterable_pchar(nombreFich); 	// Ponerme al principio del fichero
	while (iterable_has_next(&it)) {				// Mientras queden líneas por leer
		char* linea = (char*) iterable_next(&it);	// Procesar la línea
		actualizaLista(&res, linea);				// Actualizar la lista
	}
	return res;										// Devolver la lista
}

void actualizaLista(list* ls, char* cad) {
	iterator it = split_iterable_pchar(cad,", ");
	while (iterable_has_next(&it)) {
		char* trozo = (char*) iterable_next(&it);
		int x = int_parse_s(trozo);					// Convertir cadena a entero
		list_add(ls,&x);							// Añadir entero a la lista
	}
}

list seleccionaPares(list* ls) {
	list res = list_empty(int_type);
	iterator it = list_iterable(ls);
	while (iterable_has_next(&it)) {
		int* valor = iterable_next(&it);
		if (*valor%2 == 0) {
			list_add(&res,&valor);
		}
	}
	return res;
}

/*
list elevaListaCuadrado(list* ls) {
	list res = list_empty(int_type);
	iterator it = list_iterable(ls);
	while (iterable_has_next(&it)) {
		int* valor = iterable_next(&it);
		valor = pow(valor,2);
		list_add(&res,&valor);
	}
	return res;
}
*/
