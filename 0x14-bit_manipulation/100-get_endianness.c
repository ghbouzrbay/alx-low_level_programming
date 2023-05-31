#include "main.h"

/**
 *get_endianness - ...
 *
 *Return: ...
 */

int get_endianness(void)
{

int num = 1;
char *p = (char *) &num;

if (*p == 1)
{
return (1);
}

return (0);
}
