#include "slide_line.h"

/**
 * validate_input - Validates input parameters
 * @line: Pointer to array of integers
 * @size: Number of elements in the array
 * @direction: Direction to slide
 * Return: 1 if valid, 0 otherwise
 */
int validate_input(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (size == 0 || line == NULL)
		return (0);
	return (1);
}

/**
 * slide_line - Slides and merges an array (2048 style)
 * @line: Pointer to array of integers
 * @size: Number of elements in the array
 * @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT)
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	int temp[1024];
	size_t i, j = 0, k = 0;

	if (!validate_input(line, size, direction))
		return (0);
	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < size; i++)
			if (line[i] != 0)
				temp[j++] = line[i];
	}
	else
	{
		for (i = size; i > 0; i--)
			if (line[i - 1] != 0)
				temp[j++] = line[i - 1];
	}
	for (i = 0; i < j; i++)
	{
		if (i + 1 < j && temp[i] == temp[i + 1])
			line[k++] = temp[i] * 2, i++;
		else
			line[k++] = temp[i];
	}
	while (k < size)
		line[k++] = 0;
	if (direction == SLIDE_RIGHT)
		for (i = 0; i < size / 2; i++)
		{
			temp[0] = line[i];
			line[i] = line[size - 1 - i];
			line[size - 1 - i] = temp[0];
		}
	return (1);
}
