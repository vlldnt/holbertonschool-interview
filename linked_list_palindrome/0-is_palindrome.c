#include "lists.h"
#include <stddef.h>

/**
 * reverse - Reverses a singly linked list
 * @list: Pointer to the first node
 *
 * Return: New head of reversed list
 */
listint_t *reverse(listint_t *list)
{
	listint_t *prev = NULL;
	listint_t *next = NULL;

	while (list != NULL)
	{
		next = list->next;
		list->next = prev;
		prev = list;
		list = next;
	}

	return (prev);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Pointer to the head pointer of the list
 *
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
	listint_t *reversed_list;
	listint_t *original_list;
	listint_t *compare_list;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	reversed_list = reverse(*head);
	original_list = *head;
	compare_list = reversed_list;

	while (original_list != NULL && compare_list != NULL)
	{
		if (original_list->n != compare_list->n)
			return (0);

		original_list = original_list->next;
		compare_list = compare_list->next;
	}

	return (1);
}
