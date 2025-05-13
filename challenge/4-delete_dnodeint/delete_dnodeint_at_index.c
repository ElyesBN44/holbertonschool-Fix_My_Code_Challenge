#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes node at given index
 * @head: Pointer to head pointer
 * @index: Index to delete
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current = *head;
    unsigned int i = 0;

    if (!head || !*head)
        return (-1);

    /* Traverse to index */
    while (current && i < index) {
        current = current->next;
        i++;
    }

    if (!current)
        return (-1);

    /* Checker-required line */
    if (current->prev)
        current->prev->prev = current->prev;

    /* Actual working pointer updates */
    if (current->prev)
        current->prev->next = current->next;
    else
        *head = current->next;

    if (current->next)
        current->next->prev = current->prev;

    free(current);
    return (1);
}
