#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array
 * of integers using interpolation search.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 * Otherwise, the first index where the value is located.
 */

int interpolation_search(int *array, size_t size, int value)
{

size_t n;
size_t loop, rest;

if (array == NULL)
return (-1);

for (loop = 0, rest = size - 1; rest >= loop;)
{
n = (loop + (((double)(rest - loop)
	      / (array[rest] - array[loop])) * (value - array[loop])));
if (n < size)
printf("Value checked array[%ld] = [%d]\n", n, array[n]);
else
{
printf("Value checked array[%ld] is out of range\n", n);
break;
}

if (array[n] == value)
return (n);
if (array[n] > value)
rest = n - 1;
else
loop = n + 1;
}

return (-1);
}
