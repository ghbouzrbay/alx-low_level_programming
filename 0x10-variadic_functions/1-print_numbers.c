#include "variadic_functions.h"

/**
 *print_numbers - ...
 *
 *@separator: ...
 *@n: ...
 *
 *Return: ...
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
unsigned int i = 0;
va_list args;
va_start(args, n); /*initialize the va_list with the last named argument*/
for (; i < n; i++)
{
printf("%d", va_arg(args, int)); /*get the next argument as an int*/
if (separator != NULL && i < n - 1)
{
printf("%s", separator); /*print the separator if it's not
			  *NULL and not the last number
			  */
}
}
va_end(args); /*clean up the va_list*/
printf("\n"); /*print a new line at the end*/
}
