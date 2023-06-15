#include "lists.h"


/**
 * dlistint_len - function takes the head of
 * the doubly linked list
 *
 * @h: argument and iterates
 *
 * Return: ...
 */

size_t dlistint_len(const dlistint_t *h)
{
size_t node_count = 0;

while (h != NULL)
{
node_count++;
h = h->next;
}

return (node_count);
}
