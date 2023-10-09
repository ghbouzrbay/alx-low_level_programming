#include "search_algos.h"

/**
 * binary_search - function that searches for array value in array sorted array
 * of integers using Binary search algorithm.
 * @array: pointer to the first element of the array to search in.
 * @size: number of elements in array.
 * @value: value to search for.
 *
 * Return: the index where value is located.
 */

int binary_search(int *array, size_t size, int value)
{
return (search_index(array, 0, size - 1, value));
}

/**
 * search_index - recursive function for helping binary_search.
 * @array: pointer to the first element of the array to search in.
 * @l: left index of array.
 * @r: right index of array.
 * @value: value to look for.
 *
 * Return: the index where value is located.
 */

int search_index(int *array, size_t l, size_t r, int value)
{
int non;

if (!array || l > r)
return (-1);
_array(array, l, r);

non = l + (r - l) / 2;

if (l == r)
return (*(array + non) == value ? (int)non : -1);

if (array[non] == value)
return (non);
else if (array[non] > value)
return (search_index(array, l, non - 1, value));
else
return (search_index(array, non + 1, r, value));
}

/**
 * _array - Prints an array of integers.
 * @array: The array to be printed.
 * @l: The left index of the array.
 * @r: The right index of the array.
 */
void _array(int *array, size_t l, size_t r)
{
size_t n;

if (array)
{
printf("Searching in array: ");
for (n = l; n < l + (r - l + 1); n++)
printf("%d%s", *(array + n), n < l + (r - l) ? ", " : "\n");
}
}
