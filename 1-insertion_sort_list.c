#include "sort.h"

/**
 * insertion_sort_list - Function that sorts a doubly linked list of
 * integers in ascending order using an insertion sort algorithm
 * @list: double poitner to the head o fthe list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next_node, *new_node, *temp;

	if (!list || !(*list) || !((*list)->next))
		return;

	next_node = (*list);
	current = (*list)->next;
	while (current != NULL)
	{
		new_node = current->next;
		while (next_node && current->n < next_node->n)
		{
			/* lead and follow swap positions */
			if (next_node->prev)
				next_node->prev->next = current;
			else
				*list = current;
			if (current->next)
				current->next->prev = next_node;
			temp = current->next;
			current->next = next_node;
			current->prev = next_node->prev;
			next_node->next = temp;
			next_node->prev = current;
			print_list(*list);
			next_node = current->prev;
		}
		/* lead sorted to left, new cycle starts @ right leading edge */
		current = new_node;
		if (current)
			next_node = current->prev;
	}
}
