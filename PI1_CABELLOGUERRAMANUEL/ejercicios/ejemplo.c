/*
 * ejemplo.c
 *
 *  Created on: 20 oct. 2019
 *      Author: Manu Cabello
 */

#include "ejemplo.h"

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
		int x = int_parse(trozo);					// Convertir cadena a entero
		list_add(ls,&x);							// Añadir entero a la lista
	}
}

int sumaEnteros(const list* ls) {
	int res = 0;
	iterator it = list_iterable(ls);
	while (iterable_has_next(&it)) {
		int* x = (int*) iterable_next(&it);			// int x = *(int*) iterable_next(&it);
		res = res + *x;								// res = res + x;
	}
	return res;
}
