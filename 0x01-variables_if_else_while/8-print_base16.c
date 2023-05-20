#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 *main -  prints all the numbers of base 16 in lowercase,
 * followed by a new line.
 *Return: Always 0.
 */
int main(void)
{
  int d;
  char alpha;
  for (d = '0'; d <= '9'; d++)
    putchar(d);
  for (alpha = 'a'; alpha <= 'f'; alpha++)
    putchar(alpha);
  putchar('\n');
  return (0);
}
