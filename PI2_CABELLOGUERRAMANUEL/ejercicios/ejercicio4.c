/*
 * ejercicio4.c
 *
 *  Created on: 6 dic. 2019
 *      Author: Manu Cabello
 */

#include "ejercicio4.h"

void ejercicio4(char* nombreFich) {
	printf("==================================== TEST RECURSIVO SIN MEMORIA ====================================\n");
	iterator it = file_iterable_pchar(nombreFich);
	while (iterable_has_next(&it)) {
		char* linea = (char*) iterable_next(&it);
		list res = list_empty(int_type);
		iterator it = split_iterable_pchar(linea,"(,)");
		while (iterable_has_next(&it)) {
			char* trozo = (char*) iterable_next(&it);
			int x = int_parse_s(trozo);
			list_add(&res,&x);
		}
		int n = *(int*) list_get(&res,0);
		int k = *(int*) list_get(&res,1);
		printf("Entrada = %s; Salida = %d\n",linea,ejercicio4_recur_sin_mem(n,k));
	}
	printf("\n==================================== TEST RECURSIVO CON MEMORIA ====================================\n");
	it = file_iterable_pchar(nombreFich);
	while (iterable_has_next(&it)) {
		char* linea = (char*) iterable_next(&it);
		list res = list_empty(int_type);
		iterator it = split_iterable_pchar(linea,"(,)");
		while (iterable_has_next(&it)) {
			char* trozo = (char*) iterable_next(&it);
			int x = int_parse_s(trozo);
			list_add(&res,&x);
		}
		int n = *(int*) list_get(&res,0);
		int k = *(int*) list_get(&res,1);
		printf("Entrada = %s; Salida = %d\n",linea,ejercicio4_recur_con_mem_gen(n,k));
	}
	printf("\n==================================== TEST ITERATIVO ====================================\n");
	it = file_iterable_pchar(nombreFich);
	while (iterable_has_next(&it)) {
		char* linea = (char*) iterable_next(&it);
		list res = list_empty(int_type);
		iterator it = split_iterable_pchar(linea,"(,)");
		while (iterable_has_next(&it)) {
			char* trozo = (char*) iterable_next(&it);
			int x = int_parse_s(trozo);
			list_add(&res,&x);
		}
		int n = *(int*) list_get(&res,0);
		int k = *(int*) list_get(&res,1);
		printf("Entrada = %s; Salida = %d\n",linea,ejercicio4_recur_iter(n,k));
	}
}

int ejercicio4_recur_sin_mem(int n, int k) {
	if (k == 0 || k == n) {
		return 1;
	} else if (k == 1 || k == n-1) {
		return n;
	} else {
		return ejercicio4_recur_sin_mem(n-1,k-1) + ejercicio4_recur_sin_mem(n-1,k);
	}
}

int ejercicio4_recur_con_mem(int n, int k, hash_table* mem) {
	int_pair x; x.a = n; x.b = k;
	if (hash_table_contains(mem, &x)) {
		return *(int*) hash_table_get(mem, &x);
	} else if (k == 0 || k == n) {
		int res = 1;
		hash_table_put(mem, &x, &res);
		return res;
	} else if (k == 1 || k == n-1) {
		int res = n;
		hash_table_put(mem, &x, &res);
		return res;
	} else {
		return ejercicio4_recur_con_mem(n-1,k-1,mem) + ejercicio4_recur_con_mem(n-1,k,mem);
	}
}

int ejercicio4_recur_con_mem_gen(int n, int k) {
	hash_table mem = hash_table_empty(int_pair_type, int_type);
	return ejercicio4_recur_con_mem(n,k,&mem);
}

int ejercicio4_recur_iter(int n, int k) {
	list lsa = list_empty(int_type);
	int one = 1;
	list_add(&lsa,&one);
	int i = 1;
	while (i <= n) {
		list ls = list_empty(int_type);
		for (int s = 0; s <= i; s++) {
			if (s == 0 || s == i) {
				list_add(&ls,&one);
			} else if (s == 1 || s == i-1) {
				list_add(&ls,&i);
			} else {
				int lsa_res = *(int*) list_get(&lsa,s-1) + *(int*) list_get(&lsa,s);
				list_add(&ls,&lsa_res);
			}
		}
		lsa = ls;
		i++;
	}
	return *(int*) list_get(&lsa,k);
}
