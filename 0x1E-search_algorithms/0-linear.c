#include "search_algos.h"

/**
 * linear_search - function that searches for a value in an array of
 * integers using the Linear search algorithm.
 * @array: pointer to the first element of the array to search in.
 * @size: number of elements in array.
 * @value: value to search for.
 *
 * Return: first index where value is located.
 **/

int linear_search(int *array, size_t size, int value)
{
size_t n;

if (!array || size <= 0)
return (-1);

for (n = 0; n < size; n++)
{
printf("Value checked array[%ld] = [%d]\n", n, array[n]);
if (array[n] == value)
return (n);
}
return (-1);
}
