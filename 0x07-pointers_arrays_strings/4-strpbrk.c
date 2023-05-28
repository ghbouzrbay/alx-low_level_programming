#include "main.h"


/**
 *_strpbrk - function locates
 *
 *@s: the string of the first occurrence
 *@accept: the string of the bytes
 *
 *Return: Always 0
 */

char *_strpbrk(char *s, char *accept)
{
char *p;

while (*s != '\0')
{
for (p = accept; *p != '\0'; p++)
{
if (*s == *p)
{
return (s);
}
}
s++;
}

return (NULL);
}
