/*
 * ejercicio2.c
 *
 *  Created on: 20 oct. 2019
 *      Author: Manu Cabello
 */

#include "ejercicio2.h"

void ejercicio2(char* nombreFich) {
	iterator it = file_iterable_pchar(nombreFich);
	list lineas = list_empty(string_type);
	while (iterable_has_next(&it)) {
		char* linea = (char*) iterable_next(&it);
		list_add(&lineas,linea);
	}
	hash_table res = ejercicio2_itera(lineas);
	printf("Resultado: %d\n",hash_table_size(&res));
	char mem[256];
	printf("%s\n",hash_table_tostring(&res,mem));

/*
	list * r;
	char * s;
	for(int i=0;i<4;i++){
		r = hash_table_get(&res,&i);
		if (r!=NULL) {
			s = list_tostring(r,mem);
			printf("%d == %s\n",i, s);
		}
	}
*/
}

hash_table ejercicio2_itera(list lineas) {
	hash_table res = hash_table_empty(int_type, list_type);
	int index = 0;
	while (index < list_size(&lineas)) {
		int* key = (int*) strlen(list_get(&lineas,index));
		list valor = list_empty(string_type);
		if (hash_table_contains(&res,&key)) {
			valor = list_of(hash_table_get(&res,&key), (int) list_size(hash_table_get(&res,&key)), list_type);
		}
		list_add(&valor,list_get(&lineas,index));
		hash_table_put(&res,&key,&valor);
		index = index + 1;
	}
	return res;
}
