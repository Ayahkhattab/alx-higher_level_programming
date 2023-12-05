#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to the first node in the list
 *
 * Return: pointer to the first node in the new list
 */
listint_t *reverse_listint(listint_t *head)
{
    listint_t *prev = NULL;
    listint_t *current = head;
    listint_t *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

/**
 * is_palindrome - checks if a linked list is a palindrome
 * @head: double pointer to the linked list
 *
 * Return: 1 if it is, 0 if not
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head, *temp = *head, *dup = NULL;

    if (*head == NULL || (*head)->next == NULL)
        return (1);

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    dup = reverse_listint(slow);

    while (dup != NULL && temp != NULL)
    {
        if (temp->n == dup->n)
        {
            dup = dup->next;
            temp = temp->next;
        }
        else
            return (0);
    }

    return (1);
}
