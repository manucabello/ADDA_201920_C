/*
 * ejercicio1.h
 *
 *  Created on: 20 oct. 2019
 *      Author: Manu Cabello
 */

#ifndef EJERCICIO1_H_
#define EJERCICIO1_H_

#include "../types/list.h"

list leerFichero(const char* nombreFich);
void actualizaLista(list* ls, char* cad);
list seleccionaPares(list* ls);
//list elevaListaCuadrado(list* ls);

#endif /* EJERCICIO1_H_ */
