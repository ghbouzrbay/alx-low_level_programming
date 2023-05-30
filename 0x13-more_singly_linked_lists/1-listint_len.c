#include "lists.h"

/**
 *listint_len - ...
 *
 *@h: ...
 *
 *Return: ...
 */

size_t listint_len(const listint_t *h)
{
size_t len = 0;
const listint_t *p = h;
while (p != NULL)
{
len++;
p = p->next;
}

return (len);
}
