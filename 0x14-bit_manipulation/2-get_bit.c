#include "main.h"
/**
 *get_bit - ...
 *
 *@n: ...
 *@index: ...
 *
 *Return: ...
 */

int get_bit(unsigned long int n, unsigned int index)
{

unsigned long int mask = 1UL << index;

/* Check if index is out of bounds*/
if (index >= sizeof(unsigned long int) * 8)
{
return (-1);
}

return ((n & mask) != 0);
}
