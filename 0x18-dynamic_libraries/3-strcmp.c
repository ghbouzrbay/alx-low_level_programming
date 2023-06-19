#include "main.h"

/**
 * _strcmp - Compares pointers to two strings
 *
 *@s1: A pointer to the first string to be compared
 *@s2: A pointer to the second string to be compared
 *
 *Return: If str1 < str2, the negartive difference
 *of the first unmatched character
 *If str1 == str2, 0.
 *If str1 > str2, the possitive difference of the
 *first unmatched character
 *
 */

int _strcmp(char *s1, char *s2)
{

while (*s1 && *s2 && *s1 == *s2)
{
s1++;
s2++;
}

return (*s1 - *s2);
}
