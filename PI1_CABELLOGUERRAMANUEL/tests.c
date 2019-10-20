/*
 * tests.c
 *
 *  Created on: 20 oct. 2019
 *      Author: Manu Cabello
 */

//#include "ejercicios/ejemplo.h"
#include "ejercicios/ejercicio1.h"
//#include "ejercicios/ejercicio2.h"

int main(void) {
	list numeros = leerFichero("ficheros/PI1Ej1DatosEntrada.txt");
	list pares = seleccionaPares(&numeros);
	printf(list_tostring(&pares,0));
}
