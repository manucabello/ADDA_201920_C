/*
 * ejercicio5.c
 *
 *  Created on: 29 nov. 2019
 *      Author: Manu Cabello
 */

#include "ejercicio5.h"

void ejercicio5(char* nombreFich) {
	iterator it = file_iterable_pchar(nombreFich);
	printf("-------------------- TEST DEL MÉTODO ITERATIVO --------------------\n");
	while (iterable_has_next(&it)) {
		char* linea = (char*) iterable_next(&it);
		char* linea_aux = (char *) malloc(strlen(linea)+2);
		strcpy(linea_aux, "(");
		strcat(linea_aux,linea);
		strcat(linea_aux,")");
		int_pair aux = int_pair_parse_s(linea_aux);
		int_pair res = ejercicio5_itera(aux.a,aux.b);
		printf("Entrada: (%d,%d)\n",aux.a,aux.b);
		printf("Salida: (%d,%d)\n",res.a,res.b);
		printf("========================================\n");
	}
	printf("\n");
	printf("-------------------- TEST DEL MÉTODO RECURSIVO FINAL --------------------\n");
	it = file_iterable_pchar(nombreFich);
	while (iterable_has_next(&it)) {
		char* linea = (char*) iterable_next(&it);
		char* linea_aux = (char *) malloc(strlen(linea)+2);
		strcpy(linea_aux, "(");
		strcat(linea_aux,linea);
		strcat(linea_aux,")");
		int_pair aux = int_pair_parse_s(linea_aux);
		int_pair res = ejercicio5_recur_final_gen(aux.a,aux.b);
		printf("Entrada: (%d,%d)\n",aux.a,aux.b);
		printf("Salida: (%d,%d)\n",res.a,res.b);
		printf("========================================\n");
	}
	printf("\n");
	printf("-------------------- TEST DEL MÉTODO RECURSIVO NO FINAL --------------------\n");
	it = file_iterable_pchar(nombreFich);
	while (iterable_has_next(&it)) {
		char* linea = (char*) iterable_next(&it);
		char* linea_aux = (char *) malloc(strlen(linea)+2);
		strcpy(linea_aux, "(");
		strcat(linea_aux,linea);
		strcat(linea_aux,")");
		int_pair aux = int_pair_parse_s(linea_aux);
		int_pair res = ejercicio5_recur_no_final(aux.a,aux.b);
		printf("Entrada: (%d,%d)\n",aux.a,aux.b);
		printf("Salida: (%d,%d)\n",res.a,res.b);
		printf("========================================\n");
	}
}

int_pair ejercicio5_itera(int a, int b) {
	int_pair res;
	res.a = 0;
	res.b = a;
	while (a >= b) {
		a = a-b;
		res.a = res.a+1;
		res.b = a;
	}
	return res;
}

int_pair ejercicio5_recur_final(int a, int b, int_pair w) {
	if (a < b) {
		return w;
	} else {
		w.a = w.a+1;
		w.b = a-b;
		return ejercicio5_recur_final(w.b,b,w);
	}
}

int_pair ejercicio5_recur_final_gen(int a, int b) {
	int_pair w;
	w.a = 0;
	w.b = a;
	return ejercicio5_recur_final(a,b,w);
}

int_pair ejercicio5_recur_no_final(int a, int b) {
	int_pair res;
	res.a = 0;
	res.b = a;
	if (a < b) {
		return res;
	} else {
		int_pair aux = ejercicio5_recur_no_final(a-b,b);
		res.a = aux.a+1;
		res.b = aux.b;
	}
	return res;
}
