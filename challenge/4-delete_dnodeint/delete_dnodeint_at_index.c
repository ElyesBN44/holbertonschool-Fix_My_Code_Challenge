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

    /* If deleting the head node */
    if (current == *head) {
        *head = current->next;
        if (*head)
            (*head)->prev = NULL;
    } else {
        /* Update previous node's next pointer */
        current->prev->next = current->next;
        
        /* Update next node's prev pointer if it exists */
        if (current->next)
            current->next->prev = current->prev;
    }

    free(current);
    return (1);
}
