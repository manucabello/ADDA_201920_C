/*
 * ejercicio1.h
 *
 *  Created on: 6 dic. 2019
 *      Author: Manu Cabello
 */

#ifndef EJERCICIO1_H_
#define EJERCICIO1_H_

#include "../types/types.h"
#include "../types/iterables.h"
#include "../types/memory_heap.h"

#define TAM 100

void ejercicio1(char* nombreFich);
bool checkMatrix(int** matrix, int n);
int** submatrix(int** matrix, int n, int row, int col);
void imprimirMatriz(int** matrix, int n);

#endif /* EJERCICIO1_H_ */
