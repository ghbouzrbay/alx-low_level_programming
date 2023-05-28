#include "main.h"

/**
 *_print_rev_recursion - function that prints a string in reverse
 *
 *@s: input
 *
 *Return: 0
 */

void _print_rev_recursion(char *s)
{
if (*s == '\0')
{
/*Base case: end of string*/
return;
}
_print_rev_recursion(s + 1);
/*Recursively call the function with the next character*/
_putchar(*s);
/*Print the current character after all the recursive calls*/
}
