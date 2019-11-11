/*
 * ejercicio3.h
 *
 *  Created on: 11 nov. 2019
 *      Author: Manu Cabello
 */

#ifndef EJERCICIO3_H_
#define EJERCICIO3_H_

#include "../types/list.h"
#include "../types/types.h"

void ejercicio3(char* nombreFich);
bool ejercicio3_itera(char* cadena);
bool ejercicio3_recur_final(char* cadena, int i, int j, bool w);
bool ejercicio3_recur_final_gen(char* cadena);
bool ejercicio3_recur_no_final(char* cadena, int i, int j);

#endif /* EJERCICIO3_H_ */
