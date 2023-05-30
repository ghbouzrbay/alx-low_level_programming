#include "lists.h"

/**
 * sum_listint - Returns the sum of all the data
 *(n) in a listint_t linked list.
 *
 * @head: A pointer to the head of the list.
 *
 * Return: The sum of all the data, or 0 if the list is empty.
 */

int sum_listint(listint_t *head)
{
int sum = 0;
listint_t *temp;

if (head == NULL)
return (0);

temp = head;
while (temp != NULL)
{
sum += temp->n;
temp = temp->next;
}

return (sum);
}

