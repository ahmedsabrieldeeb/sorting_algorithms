#include "sort.h"
#include <stdio.h>
#include <stdlib.h>



/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order
 *
 * Description: You are not allowed to modify the integer n of a node.
 * You have to swap the nodes themselves.
 *
 * @list: list to be sorted
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev, *curr_cp, *prev_cp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		prev = curr->prev;
		curr_cp = curr;
		prev_cp = prev;
		while (prev_cp != NULL && curr_cp->n < prev_cp->n)
		{
			/*swap two elements*/
			curr_cp->prev = prev_cp->prev;
			prev_cp->next = curr_cp->next;

			if (curr_cp->next != NULL)
				curr_cp->next->prev = prev_cp;
			if (prev_cp->prev != NULL)
				prev_cp->prev->next = curr_cp;

			curr_cp->next = prev_cp;
			prev_cp->prev = curr_cp;

			prev_cp = curr_cp->prev;
			if (prev_cp == NULL)
				*list = curr_cp;
			print_list(*list);
		}
		curr = curr->next;
	}
}
