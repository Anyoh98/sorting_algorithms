#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the insertion sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous, *next_node, *temp;

	if (!list || !(*list) || !((*list)->next))
		return;	
	current = *list;
	next_node = current->next;
	while (next_node)
	{
		temp = next_node->next;
		while (current && next_node->n < current->n)
		{
			if (current->prev)
				current->prev->next = next_node;
			else
				*list = next_node;
			if (next_node->next)
				next_node->next->prev = current;
			next_node->next = current;
			next_node->prev = current->prev;
			current->next = temp;
			current->prev = next_node;
			print_list(*list);
			current = next_node->prev;
		}
		next_node = temp;
		if (next_node)
			current = next_node->prev;
	}
}
