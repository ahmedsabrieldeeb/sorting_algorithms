#include <stdio.h>
#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list
 * @list: Double pointer
 */
void cocktail_sort_list(listint_t **list)
{
    int swap;
    listint_t *node;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    do {
        swap = 0;
        for (nn = *list; nn->next != NULL; nn = nn->next)
        {
            if (nn->n > nn->next->n)
            {
                swap_nodes(list, nn, nn->next);
                print_list(*list);
                swap = 1;
            }
        }

        if (!swap)
            break;

        swap = 0;
        for (nn = nn->prev; nn->prev != NULL; nn = nn->prev)
        {
            if (nn->n < nn->prev->n)
            {
                swap_nodes(list, nn->prev, nn);
                print_list(*list);
                swap = 1;
            }
        }
    } while (swap);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @n1: First node to swap
 * @n2: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t *n1, listint_t *n2)
{
    if (n1->prev != NULL)
        n1->prev->next = n2;
    else
        *list = n2;

    if (n2->next != NULL)
        n2->next->prev = n1;

    n1->next = n2->next;
    n2->prev = n1->prev;
    n1->prev = n2;
    n2->next = n1;
}
