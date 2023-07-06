#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to a hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
    hash_table_t *hash_table_head = ht;
    hash_node_t *current_node, *next_node;
    unsigned long int index;

    for (index = 0; index < ht->size; index++)
 ²   {
        if (ht->array[index] != NULL)
        {
            current_node = ht->array[index];
            while (current_node != NULL)
            {
                next_node = current_node->next;
                free(current_node->key);
                free(current_node->value);
                free(current_node);
                current_node = next_node;
            }
        }
    }
    free(hash_table_head->array);
    free(hash_table_head);
}
