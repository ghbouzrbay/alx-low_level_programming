#include "lists.h"

/**
 * free_listint_safe - Frees a singly linked list
 *in a safe manner to prevent loops.
 * @h: A pointer to a pointer to the head of the list.
 *
 * Return: The size of the list that was free'd.
 */

size_t free_listint_safe(listint_t **h)
{

listint_t *current;
int tmp;
size_t count = 0;

if (!h || !*h)
return (0);

current = *h;
while (*h)
{
tmp = *h - (*h)->next;

if (tmp > 0)
{
current = (*h)->next;
free(*h);
*h = current;
count++;
}

else
{
free(*h);
*h = NULL;
count++;
break;
}
}

*h = NULL;
return (count);
}
