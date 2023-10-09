#ifndef _search_algos_
#define _search_algos_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
void _array(int *array, size_t l, size_t r);
int search_index(int *array, size_t l, size_t r, int value);

#endif
