/*
 * ejercicio2.c
 *
 *  Created on: 20 oct. 2019
 *      Author: Manu Cabello
 */

#include "ejercicio2.h"

void ejercicio2(char* nombreFich) {
	iterator it = file_iterable_pchar(nombreFich);
	hash_table res = hash_table_empty(int_type, string_type);
	int* key = 0;
	while (iterable_has_next(&it)) {
		char* linea = (char*) iterable_next(&it);
		key =  (int*) strlen(linea);
		char* value = linea;
		hash_table_put_pointer(&res, &key, &value);
	}
	printf("%d",hash_table_size(&res));
	//printf(hash_table_tostring(&ht,mem));

	/*
	iterator iht = hash_table_items_iterable(&res);
	while(iterable_has_next(&iht)) {
		char* result = (char*) iterable_next(&iht);
		printf(&result);
	}
	*/
}
