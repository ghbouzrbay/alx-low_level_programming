#include "hash_tables.h"


/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the new sorted hash table.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *sorted_ht;
    unsigned long int i;

    sorted_ht = malloc(sizeof(shash_table_t));
    if (sorted_ht == NULL)
        return NULL;

    sorted_ht->size = size;
    sorted_ht->array = malloc(sizeof(shash_node_t *) * size);
    if (sorted_ht->array == NULL)
        return NULL;

    for (i = 0; i < size; i++)
        sorted_ht->array[i] = NULL;

    sorted_ht->shead = NULL;
    sorted_ht->stail = NULL;

    return sorted_ht;
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with the key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    shash_node_t *new_node, *current_node;
    char *value_copy;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
        return 0;

    value_copy = strdup(value);
    if (value_copy == NULL)
        return 0;

    index = key_index((const unsigned char *)key, ht->size);
    current_node = ht->shead;

    while (current_node)
    {
        if (strcmp(current_node->key, key) == 0)
        {
            free(current_node->value);
            current_node->value = value_copy;
            return 1;
        }
        current_node = current_node->snext;
    }

    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
    {
        free(value_copy);
        return 0;
    }

    new_node->key = strdup(key);
    if (new_node->key == NULL)
    {
        free(value_copy);
        free(new_node);
        return 0;
    }

    new_node->value = value_copy;
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    if (ht->shead == NULL)
    {
        new_node->sprev = NULL;
        new_node->snext = NULL;
        ht->shead = new_node;
        ht->stail = new_node;
    }
    else if (strcmp(ht->shead->key, key) > 0)
    {
        new_node->sprev = NULL;
        new_node->snext = ht->shead;
        ht->shead->sprev = new_node;
        ht->shead = new_node;
    }
    else
    {
        current_node = ht->shead;
        while (current_node->snext != NULL && strcmp(current_node->snext->key, key) < 0)
            current_node = current_node->snext;

        new_node->sprev = current_node;
        new_node->snext = current_node->snext;

        if (current_node->snext == NULL)
            ht->stail = new_node;
else
        {
            current_node->snext->sprev = new_node;
        }
        current_node->snext = new_node;
    }

    return 1;
}

/**
 * shash_table_get - Retrieve the value associated with a key in a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with the key in ht.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    shash_node_t *node;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0')
        return NULL;

    index = key_index((const unsigned char *)key, ht->size);
    if (index >= ht->size)
        return NULL;

    node = ht->shead;

    while (node != NULL && strcmp(node->key, key) != 0)
        node = node->snext;

    return (node == NULL) ? NULL : node->value;
}

/**
 * shash_table_print - Prints a sorted hash table in order.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *node;

    if (ht == NULL)
        return;

    node = ht->shead;
    printf("{");

    while (node != NULL)
    {
        printf("'%s': '%s'", node->key, node->value);
        node = node->snext;
        if (node != NULL)
            printf(", ");
    }

    printf("}\n");
}

B
/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: A pointer to the sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *node;

    if (ht == NULL)
        return;

    node = ht->stail;
    printf("{");

    while (node != NULL)
    {
        printf("'%s': '%s'", node->key, node->value);
        node = node->sprev;
        if (node != NULL)
            printf(", ");
    }

    printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
    shash_table_t *hash_table_head = ht;
    shash_node_t *node, *tmp;

    if (ht == NULL)
        return;

    node = ht->shead;

    while (node)
    {
        tmp = node->snext;
        free(node->key);
        free(node->value);
        free(node);
        node = tmp;
    }

    free(hash_table_head->array);
    free(hash_table_head);
}

