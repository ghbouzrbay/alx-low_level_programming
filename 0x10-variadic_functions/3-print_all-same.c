#include "variadic_functions.h"


/**
 *print_all - ...
 *
 *@format: ...
 *
 *Return: ...
 */

void print_all(const char * const format, ...)
{
va_list args;
char c;
int i;
float f;
char *s;
int index = 0;

va_start(args, format);

while (format[index] != '\0')
{
switch (format[index])
{
case 'c':
c = va_arg(args, int);
printf("%c, ", c);
break;
case 'i':
i = va_arg(args, int);
printf("%d, ", i);
break;
case 'f':
f = va_arg(args, double);
printf("%f", f);
break;
case 's':
s = va_arg(args, char *);
if (s == NULL)
{
printf("(nil)");
}
else
{
printf("%s", s);
}
break;
default:
break;
}
index++;
}

va_end(args);

printf("\n");

}
