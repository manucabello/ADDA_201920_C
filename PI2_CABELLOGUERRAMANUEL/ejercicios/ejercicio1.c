/*
 * ejercicio1.c
 *
 *  Created on: 6 dic. 2019
 *      Author: Manu Cabello
 */

#include "ejercicio1.h"

void ejercicio1(char* nombreFich) {
	iterator it = file_iterable_pchar(nombreFich);
	char* matrix[tam];
	int n;
	while (iterable_has_next(&it)) {
		char* linea = (char*) iterable_next(&it);
		printf("La matriz: {%s}\n",linea);
		iterator it = split_iterable_pchar(linea,"{,}");
		n = 0;
		while (iterable_has_next(&it)) {
			char* trozo = (char*) iterable_next(&it);
//			printf("%s\n",trozo);
			matrix[n] = trozo;
			n++;
		}
		printf("(%d)\n",n);
		for (int i = 0; i < n; i++) {
			printf("%s\n",matrix[i]);
		}
	}
/*
	int matrix[4][4] = {{1,4,2,0},{3,3,7,7},{6,4,2,5},{3,9,1,4}};
	int n = (int) sizeof(matrix)/sizeof(matrix[0]);
	int* p[n];
	for (int i = 0; i < n; i++) {
		p[i] = matrix[i];
	}
	int** q = p;
	imprimirMatriz(q,n);
	bool res = checkMatrix(q,n);
	printf("%s\n\n",res ? "Cumple la propiedad":"NO cumple la propiedad");
*/
}

bool checkMatrix(int** matrix, int n) {
	bool res = true;
	if (n == 2) {
		res = matrix[0][0] < matrix[n-1][n-1];
	} else if (n > 2 && res) {
		int** aux1_res = submatrix(matrix,n,n-1,n-1);
		int aux1[n-1][n-1];
		for (int i= 0; i < n-1; i++) {
			for (int j = 0; j < n-1; j++) {
				aux1[i][j] = aux1_res[i][j];
			}
		}
		int* aux1_p[n-1];
		for (int i = 0; i < n-1; i++) {
			aux1_p[i] = aux1[i];
		}
		int** aux1_q = aux1_p;

		int** aux2_res = submatrix(matrix,n,n-1,0);
		int aux2[n-1][n-1];
		for (int i = 0; i < n-1; i++) {
			for (int j = 0; j < n-1; j++) {
				aux2[i][j] = aux2_res[i][j];
			}
		}
		int* aux2_p[n-1];
		for (int i = 0; i < n-1; i++) {
			aux2_p[i] = aux2[i];
		}
		int** aux2_q = aux2_p;

		int** aux3_res = submatrix(matrix,n,0,n-1);
		int aux3[n-1][n-1];
		for (int i = 0; i < n-1; i++) {
			for (int j = 0; j < n-1; j++) {
				aux3[i][j] = aux3_res[i][j];
			}
		}
		int* aux3_p[n-1];
		for (int i = 0; i < n-1; i++) {
			aux3_p[i] = aux3[i];
		}
		int** aux3_q = aux3_p;

		int** aux4_res = submatrix(matrix,n,0,0);
		int aux4[n-1][n-1];
		for (int i = 0; i < n-1; i++) {
			for (int j = 0; j < n-1; j++) {
				aux4[i][j] = aux4_res[i][j];
			}
		}
		int* aux4_p[n-1];
		for (int i = 0; i < n-1; i++) {
			aux4_p[i] = aux4[i];
		}
		int** aux4_q = aux4_p;

		res = matrix[0][0] < matrix[n-1][n-1] && checkMatrix(aux1_q,n-1) && checkMatrix(aux2_q,n-1) && checkMatrix(aux3_q,n-1) && checkMatrix(aux4_q,n-1);
 	}
	return res;
}

int** submatrix(int** matrix, int n, int row, int col) {
	int aux[n-1][n-1];
	int x = 0;
	for (int i = 0; i < n; i++) {
		int y = 0;
		if (i != row) {
			for (int j = 0; j < n; j++) {
				if (j != col) {
					aux[x][y] = matrix[i][j];
					y++;
				}
			}
			x++;
		}
	}

	int* aux_p[n-1];
	for (int i = 0; i < n-1; i++) {
		aux_p[i] = aux[i];
	}
	int** res = aux_p;
	return res;
}

void imprimirMatriz(int** imp_matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ",imp_matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
