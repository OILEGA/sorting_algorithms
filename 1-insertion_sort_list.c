#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a listint_t doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @node1: A pointer to the first node to swap.
 * @node2: The second node to swap.
 */
void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{
	if (*head == NULL || node1 == NULL || node2 == NULL)
		return;

	if (node1 == node2)
		return;

	if (node1->prev == NULL)
	{
		*head = node2;
	}
	else if (node2->prev == NULL)
	{
		*head = node1;
	}

	if (node1->next == node2)
	{
		node1->next = node2->next;
		node2->prev = node1->prev;
		node1->prev = node2;
		node2->next = node1;
	}
	else if (node2->next == node1)
	{
		node2->next = node1->next;
		node1->prev = node2->prev;
		node2->prev = node1;
		node1->next = node2;
	}
	else
	{
		listint_t *temp_next, *temp_prev;

		temp_next = node1->next;
		temp_prev = node1->prev;

		node1->next = node2->next;
		node1->prev = node2->prev;
		node2->next = temp_next;
		node2->prev = temp_prev;

		if (node1->next != NULL)
			node1->next->prev = node1;
		if (node1->prev != NULL)
			node1->prev->next = node1;
		if (node2->next != NULL)
			node2->next->prev = node2;
		if (node2->prev != NULL)
			node2->prev->next = node2;
	}
}


/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current->prev;

		while (temp != NULL && temp->n > current->n)
		{
			temp->next = current->next;

			if (current->next != NULL)
				current->next->prev = temp;

			current->next = temp;
			current->prev = temp->prev;
			temp->prev = current;

			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;

			print_list(*list);
			temp = current->prev;
		}

		current = current->next;
	}
}

