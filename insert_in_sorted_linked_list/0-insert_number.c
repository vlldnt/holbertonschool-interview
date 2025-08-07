#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * insert_node - function to insert an integer
 * @head: pointer to pointer of first node of listint_t list
 * @number: number to include in a sorted linked list
 *
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	/* New node init */
	new->n = number;
	new->next = NULL;

	/* Condition if *head empty */
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	/* Condition if number less than the head->n */
	if ((*head)->n > number)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	/* Locate where to insert the new node in sorted order */
	current = *head;
	while (current->next != NULL && current->next->n < number)
	{
		current = current->next;
	}

	/* Insert the new node at the right place */
	new->next = current->next;
	current->next = new;

	return (new);
}
