#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list
 * @head: pointer to the head of the list
 * @n: integer to add
 *
 * Return: address of the new element, or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}

/**
 * print_listint_safe - prints a listint_t list safely
 * @head: pointer to the head of the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head, *fast = head;
	size_t count = 0;

	while (head)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		count++;

		if (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				printf("-> [%p] %d\n", (void *)slow, slow->n);
				break;
			}
		}
		head = head->next;
	}
	return (count);
}

/**
 * free_listint_safe - frees a listint_t list safely
 * @h: pointer to the head of the list
 *
 * Return: number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *slow, *fast, *temp;
	size_t count = 0;

	if (!h || !*h)
		return (0);

	slow = *h;
	fast = *h;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			break;
	}

	if (fast && fast->next && slow == fast)
	{
		slow = *h;
		while (slow != fast)
		{
			temp = slow;
			slow = slow->next;
			free(temp);
			count++;
			fast = fast->next;
		}

		temp = slow;
		slow = slow->next;
		free(temp);
		count++;

		while (slow != fast)
		{
			temp = slow;
			slow = slow->next;
			free(temp);
			count++;
		}
	}
	else
	{
		while (*h)
		{
			temp = *h;
			*h = (*h)->next;
			free(temp);
			count++;
		}
	}
	*h = NULL;
	return (count);
}
