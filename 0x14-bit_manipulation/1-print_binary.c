#include "main.h"

/**
 *print_binary - ...
 *
 *@n: ...
 *
 */

void print_binary(unsigned long int n)
{
int i, idx = 0;
unsigned long int mask;

for (i = 63; i >= 0; i--)
{
mask = n >> i;
if (mask & 1)
{
_putchar('1');
idx++;
}
else if (idx)
_putchar('0');
}
if (!idx)
_putchar('0');
}

