#include "main.h"

/**
 *_pow_recursion - function that returns the value
 *of x raised to the power of y.
 *
 *@x: input
 *@y: input
 *
 *Return: If y is lower than 0, the function should return -1
 */

int _pow_recursion(int x, int y)
{
if (y < 0)
{
return (-1);
/*base case for invalid input*/
}
else if (y == 0)
{
return (1);
/*base case for x^0 = 1*/
}
else
{
return (x * _pow_recursion(x, y - 1));
/*recursive case for x^y = x * x^(y-1)*/
}
}
