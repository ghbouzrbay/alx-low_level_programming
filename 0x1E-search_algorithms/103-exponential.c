#include "search_algos.h"

/**
 * search_binary - Searches for a value in a sorted array
 *                  of integers using binary search.
 * @array: A pointer to the first element of the array to search.
 * @left: The starting index of the [sub]array to search.
 * @right: The ending index of the [sub]array to search.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the index where the value is located.
 */
int search_binary(int *array, size_t left, size_t right, int value)
{
size_t n;

if (array == NULL)
return (-1);

while (right >= left)
{
printf("Searching in array: ");
for (n = left; n < right; n++)
printf("%d, ", array[n]);
printf("%d\n", array[n]);
n = left + (right - left) / 2;
if (array[n] == value)
return (n);

if (array[n] > value)
right = n - 1;

else
left = n + 1;
}
return (-1);
}

/**
 * exponential_search - Searches for a value in a sorted array
 *                      of integers using exponential search.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the index where the value is located.
 *
 * Description: Prints a value every time it is compared in the array.
 */
int exponential_search(int *array, size_t size, int value)
{
size_t n = 0;
size_t done;

if (array == NULL)
return (-1);

if (array[0] != value)
{
for (n = 1; n < size && array[n] <= value; n = n * 2)
printf("Value checked array[%ld] = [%d]\n", n, array[n]);
}

done = n < size ? n : size - 1;
printf("Value found between indexes [%ld] and [%ld]\n", n / 2, done);

return (search_binary(array, n / 2, done, value));
}
