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
	listint_t *curr, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (curr = (*list)->next; curr != NULL; curr = curr->next)
	{
		for (prev = curr->prev; prev != NULL; prev = prev->prev)
		{
			if (curr->n < prev->n)
			{
				if (prev->prev == NULL)
				{
					insert_at_beginning(list, &curr, &prev);
					print_list(*list);
					break;
				}
				else
					continue;
			}
			else
			{
				if (prev->next == curr)
					break;

				insert_after_prev(&curr, &prev);
				print_list(*list);
				break;
			}
		}
	}
}

/**
 * insert_at_beginning - only insert node at first and shift
 *
 * @list: list is being sorted
 * @curr: the node to be inserted at first
 * @first: first node at list
*/
void insert_at_beginning(listint_t **list, listint_t **curr, listint_t **first)
{
	listint_t *temp = *curr;

	if (temp->next == NULL)
		temp->prev->next = NULL;
	else
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}
	*curr = temp->prev;

	(*first)->prev = temp;
	temp->next = *first;
	temp->prev = NULL;
	*list = temp;
}

/**
 * insert_after_prev - insert node at specific location in list and shift
 *
 * @curr: the node to be inserted after prev node
 * @prev: node to insert curr after
*/
void insert_after_prev(listint_t **curr, listint_t **prev)
{
	listint_t *temp = *curr;

	if (temp->next == NULL)
		temp->prev->next = NULL;
	else
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}
	*curr = temp->prev;

	(*prev)->next->prev = temp;
	temp->next = (*prev)->next;
	(*prev)->next = temp;
	temp->prev = *prev;
}
