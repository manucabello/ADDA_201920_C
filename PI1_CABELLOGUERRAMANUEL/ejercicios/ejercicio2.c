/*
 * ejercicio2.c
 *
 *  Created on: 20 oct. 2019
 *      Author: Manu Cabello
 */

#include "ejercicio2.h"

void ejercicio2(char* nombreFich) {
	iterator it = file_iterable_pchar(nombreFich);
	while (iterable_has_next(&it)) {
		char* linea = (char*) iterable_next(&it);
	}
}
