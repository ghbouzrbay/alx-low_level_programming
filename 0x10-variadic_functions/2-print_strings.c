#include "main.h"

/**
 *print_strings - ...
 *
 *@separator: ...
 *@n: ...
 *
 *Return: ...
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
va_list arg_list;
unsigned int i;
const char *str;

va_start(arg_list, n);

for (i = 0; i < n; i++)
{
str = va_arg(arg_list, const char *);

if (str == NULL)
{
printf("(nil)");
}
else
{
printf("%s", str);
}

if (i != n - 1 && separator != NULL)
{
printf("%s", separator);
}
}

printf("\n");
va_end(arg_list);
}
