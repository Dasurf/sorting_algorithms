#include "sort.h"
#include <stdio.h>
/**
 *swap_node - swaps a node for his previous one
 *@node: A node
 *@list: A node list
 *Return: returns a pointer to a node which was entered
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;
	/*NULL, 29, 48, 19, 71, 13, NULL*/

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}
/**
 *cocktail_sort_list - this is a cocktail sort implementation
 *working on a double linked lists
 *@list: A list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swap_nums = 1;

	if ((*list) == '\0' || list == '\0' || (*list)->next == '\0')
		return;
	node = *list;
	while (swap_nums == 1)
	{
		swap_nums = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swap_node(node->next, list);
				swap_nums = 1;
				print_list(*list);
			}
			node = node->next;
		}
		if (swap_nums == 0)
			break;
		swap_nums = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swap_node(node, list);
				swap_nums = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}
