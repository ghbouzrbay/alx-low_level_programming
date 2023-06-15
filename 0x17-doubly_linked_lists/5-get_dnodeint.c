#include "lists.h"


/**
 * get_dnodeint_at_index - function that returns the
 * nth node of a dlistint_t linked list.
 *
 * @head: ...
 * @index: ...
 *
 * Return: ...
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
dlistint_t *current = head;
unsigned int count = 0;

while (current != NULL)
{
if (count == index)
return (current);

current = current->next;
count++;
}

return (NULL);
}
