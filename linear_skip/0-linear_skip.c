#include "search.h"

/**
 * search_range - Performs linear search within a range
 * @start: Starting node of the range
 * @end: Ending node of the range
 * @value: Value to search for
 *
 * Return: Pointer to the node where value is located, or NULL
 */
skiplist_t *search_range(skiplist_t *start, skiplist_t *end, int value)
{
	while (start != NULL && start->index <= end->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", start->index, start->n);
		if (start->n == value)
			return (start);
		start = start->next;
	}
	return (NULL);
}

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express, *prev;

	if (list == NULL)
		return (NULL);

	express = list;
	prev = list;

	while (express->express != NULL)
	{
		prev = express;
		express = express->express;
		printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
		if (express->n >= value)
			break;
	}

	if (express->express == NULL && express->n < value)
	{
		prev = express;
		while (express->next != NULL)
			express = express->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		   prev->index, express->index);

	return (search_range(prev, express, value));
}
