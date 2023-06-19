#include "main.h"

/**
 *_abs - Computes the abdolute value of an integer.
 *@c: The number to be checked
 *Return: Absolute value od number or zero
 */

int _abs(int c)
{
if (c < 0)
{
int abs_val;
abs_val = c * -1;
return (abs_val);
}
return (c);
}

