/*
 * ejercicio1.c
 *
 *  Created on: 6 dic. 2019
 *      Author: Manu Cabello
 */

#include "ejercicio1.h"

void ejercicio1(char* nombreFich) {
/*
	iterator it1 = file_iterable_pchar(nombreFich);
	while (iterable_has_next(&it1)) {
		char* linea = (char*) iterable_next(&it1);
		iterator it2 = split_iterable_pchar(linea,"{,}");
		while (iterable_has_next(&it2)) {
			char* trozo = (char*) iterable_next(&it2);
			iterator it3 = split_iterable_pchar(trozo," ");
			while (iterable_has_next(&it3)) {
				char* num = (char*) iterable_next(&it3);
				int x = int_parse_s(num);
				printf("%d,",x);
			}
			printf("\n");
		}
		printf("\n=================================================\n\n");
	}
*/
// ##### TEST 1 #####
	int matrix1[2][3] = {{1,4},{10,20}};
	int n1 = (int) sizeof(matrix1)/sizeof(matrix1[0]);
	int* p1[n1];
	for (int i = 0; i < n1; i++) {
		p1[i] = matrix1[i];
	}
	int** q1 = p1;
	imprimirMatriz(q1,n1);
	bool res1 = checkMatrix(q1,n1);
	printf("%s\n\n",res1 ? "Cumple la propiedad":"NO cumple la propiedad");

// ##### TEST 2 #####
	int matrix2[4][4] = {{1,4,2,0},{3,3,7,7},{6,4,2,5},{3,9,1,4}};
	int n2 = (int) sizeof(matrix2)/sizeof(matrix2[0]);
	int* p2[n2];
	for (int i = 0; i < n2; i++) {
		p2[i] = matrix2[i];
	}
	int** q2 = p2;
	imprimirMatriz(q2,n2);
	bool res2 = checkMatrix(q2,n2);
	printf("%s\n\n",res2 ? "Cumple la propiedad":"NO cumple la propiedad");

// ##### TEST 3 #####
	int matrix3[4][4] = {{10,4,2,0},{3,3,7,7},{6,4,2,5},{3,9,1,4}};
	int n3 = (int) sizeof(matrix3)/sizeof(matrix3[0]);
	int* p3[n3];
	for (int i = 0; i < n3; i++) {
		p3[i] = matrix3[i];
	}
	int** q3 = p3;
	imprimirMatriz(q3,n3);
	bool res3 = checkMatrix(q3,n3);
	printf("%s\n\n",res3 ? "Cumple la propiedad":"NO cumple la propiedad");

// ##### TEST 4 #####
	int matrix4[4][4] = {{1,4,2,0},{3,3,7,7},{6,4,5,5},{3,9,1,4}};
	int n4 = (int) sizeof(matrix4)/sizeof(matrix4[0]);
	int* p4[n4];
	for (int i = 0; i < n4; i++) {
		p4[i] = matrix4[i];
	}
	int** q4 = p4;
	imprimirMatriz(q4,n4);
	bool res4 = checkMatrix(q4,n4);
	printf("%s\n\n",res4 ? "Cumple la propiedad":"NO cumple la propiedad");
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
		printf("{");
		for (int j = 0; j < n; j++) {
			printf("%d",imp_matrix[i][j]);
			if (j < n-1) {
				printf(" ");
			}
		}
		printf("}");
		if (i < n-1) {
			printf(",");
		}
	}
	printf("\n");
}
