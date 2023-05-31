#include "main.h"

/**
 *flip_bits - ...
 *
 *@n: ...
 *@m: ...
 *
 *Return: ...
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{

unsigned int count = 0;
unsigned long int diff = n ^ m;

while (diff > 0)
{
count += diff & 1;
diff >>= 1;
}

return (count);
}
