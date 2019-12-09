/*
 * ejercicio4.h
 *
 *  Created on: 6 dic. 2019
 *      Author: Manu Cabello
 */

#ifndef EJERCICIO4_H_
#define EJERCICIO4_H_

#include "../types/types.h"
#include "../types/hash_table.h"
#include "../types/list.h"

void ejercicio4(char* nombreFich);
int ejercicio4_recur_sin_mem(int n, int k);
int ejercicio4_recur_con_mem(int n, int k, hash_table* mem);
int ejercicio4_recur_con_mem_gen(int n, int k);
int ejercicio4_recur_iter(int n, int k);

#endif /* EJERCICIO4_H_ */
