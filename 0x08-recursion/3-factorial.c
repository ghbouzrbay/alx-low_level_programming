#include "main.h"

/**
 *factorial - function that returns the factorial
 *of a given number.
 *
 *@n: input
 *
 *Return: If n is lower than 0, the function should
 *return -1 to indicate an error
 */


int factorial(int n)
{
if (n < 0)
{
return (-1);
/*error code*/
}
else if (n == 0)
{
return (1);
/*base case*/
}
else
{
return (n * factorial(n - 1));
/*recursive case*/
}
}
