#include "lists.h"

/**
 * reverse - Reverses a singly linked list
 * @list: Pointer to the first node
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
 * copy_list - Creates a copy of a singly linked list
 * @head: Pointer to the first node
 * Return: Head of the copied list
 */
listint_t *copy_list(listint_t *head)
{
	listint_t *copy = NULL;
	listint_t *tail = NULL;
	listint_t *new_node;

	while (head != NULL)
	{
		new_node = malloc(sizeof(listint_t));
		if (!new_node)
			return (NULL);
		new_node->n = head->n;
		new_node->next = NULL;
		if (!copy)
			copy = new_node;
		else
			tail->next = new_node;
		tail = new_node;
		head = head->next;
	}

	return (copy);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Pointer to the head pointer of the list
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
	listint_t *reversed_list;
	listint_t *original_list;
	listint_t *compare_list;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	reversed_list = reverse(copy_list(*head));
	if (!reversed_list)
		return (0);

	original_list = *head;
	compare_list = reversed_list;

	while (original_list != NULL && compare_list != NULL)
	{
		if (original_list->n != compare_list->n)
		{
			free_listint(reversed_list);
			return (0);
		}
		original_list = original_list->next;
		compare_list = compare_list->next;
	}

	free_listint(reversed_list);
	return (1);
}
