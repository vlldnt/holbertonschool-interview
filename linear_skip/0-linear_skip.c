#include "search.h"

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

	/* Use express lane to find the range where value might be */
	while (express->express != NULL)
	{
		prev = express;
		express = express->express;
		printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);

		if (express->n >= value)
			break;
	}

	/* Determine the range to search */
	if (express->express == NULL && express->n < value)
	{
		/* Value is beyond last express node, search from prev to end */
		prev = express;
		while (express->next != NULL)
			express = express->next;

		printf("Value found between indexes [%lu] and [%lu]\n",
			   prev->index, express->index);
	}
	else
	{
		/* Value is between prev and current express node */
		printf("Value found between indexes [%lu] and [%lu]\n",
			   prev->index, express->index);
	}

	/* Linear search in the identified range */
	while (prev != NULL && prev->index <= express->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}
