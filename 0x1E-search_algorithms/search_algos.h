#ifndef _search_algos_
#define _search_algos_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>

/******THE FUNCTIONS OF THE MONDATORY TASKS******/

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
void _array(int *array, size_t l, size_t r);
int search_index(int *array, size_t l, size_t r, int value);

/**
 * struct listint_s - singly linked list
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct listint_s
{
    int n;
    size_t index;
    struct listint_s *next;
} listint_t;

/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 */
typedef struct skiplist_s
{
    int n;
    size_t index;
    struct skiplist_s *next;
    struct skiplist_s *express;
} skiplist_t;

/********THE FUNCTION OF TH ADVANCED TASKS******/

int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);
listint_t *jump_list(listint_t *list, size_t size, int value);
skiplist_t *linear_skip(skiplist_t *list, int value);

/********assisted functions********/

int search_binary(int *array, size_t left, size_t right, int value);
#endif
