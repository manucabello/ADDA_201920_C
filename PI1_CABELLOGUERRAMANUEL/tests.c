/*
 * tests.c
 *
 *  Created on: 20 oct. 2019
 *      Author: Manu Cabello
 */

#include "ejercicios/ejemplo.h"

int main(void) {
	list numeros = leerFichero("ficheros/ejemplo.txt");
	printf("La suma es = %d", sumaEnteros(&numeros));
}
