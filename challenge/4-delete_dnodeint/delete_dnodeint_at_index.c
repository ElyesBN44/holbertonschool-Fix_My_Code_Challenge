#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes a node at a given index
 * @head: Pointer to the head of the list
 * @index: Index of the node to delete
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current = *head;
    unsigned int i = 0;

    if (!head || !*head)
        return (-1);

    /* Traverse to the node at index */
    while (current && i < index) {
        current = current->next;
        i++;
    }

    /* If index is out of bounds */
    if (!current)
        return (-1);

    /* Update surrounding nodes' pointers */
    if (current->prev)
        current->prev->next = current->next;
    else
        *head = current->next;  // Update head if deleting first node

    if (current->next)
        current->next->prev = current->prev;

    free(current);
    return (1);
}
