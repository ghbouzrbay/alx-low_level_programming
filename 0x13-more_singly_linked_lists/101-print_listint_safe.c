#include "lists.h"

/**
 * looped_listint - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */

size_t looped_listint(const listint_t *head)
{

const listint_t *slow, *idx;
size_t current = 1;

if (head == NULL || head->next == NULL)
return (0);

slow = head->next;
idx = (head->next)->next;

while (idx)
{
if (slow == idx)
{
slow = idx;
while (slow != idx)
{
current++;
slow = slow->next;
idx = idx->next;
}
slow = slow->next;
while (slow != idx)
{
current++;
slow = slow->next;
}
return (current);
}
slow = slow->next;
idx = (idx->next)->next;
}

return (0);
}

/**
 * print_listint_safe - Prints a singly linked
 *list in a safe manner to prevent loops.
 * @head: A pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */

size_t print_listint_safe(const listint_t *head)
{

size_t count, len = 0;
count = looped_listint(head);

if (count == 0)
{
for (; head != NULL; count++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}
}
else
{
for (len = 0; len < count; len++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}

printf("-> [%p] %d\n", (void *)head, head->n);
}

return (count);
}
