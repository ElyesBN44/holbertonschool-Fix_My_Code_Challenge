#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int i;

    if (head == NULL || *head == NULL)
        return (-1);

    current = *head;

    /* Traverse to the node at index */
    for (i = 0; current != NULL && i < index; i++)
        current = current->next;

    /* If index is out of bounds */
    if (current == NULL)
        return (-1);

    /* If deleting the head node */
    if (current == *head)
    {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    }
    else
    {
        /* Link the previous node to the next node */
        current->prev->next = current->next;
        
        /* If there's a node after current, link it back */
        if (current->next != NULL)
            current->next->prev = current->prev;
    }

    free(current);
    return (1);
}
