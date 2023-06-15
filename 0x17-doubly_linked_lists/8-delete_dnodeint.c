#include "lists.h"

/**
 * delete_dnodeint_at_index - function that deletes the node
 * at index index of a dlistint_t linked list.
 *
 * @head: ...
 * @index: ...
 *
 * Return: ...
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
unsigned int count = 0;
if (*head == NULL)
return (-1);

dlistint_t *current = *head;

if (index == 0)
{
*head = current->next;

if (*head != NULL)
(*head)->prev = NULL;

free(current);
return (1);
}

while (current != NULL && count < index)
{
current = current->next;
count++;
}

if (current == NULL)
return (-1);

if (current->next != NULL)
current->next->prev = current->prev;

if (current->prev != NULL)
current->prev->next = current->next;

free(current);
return (1);
}
