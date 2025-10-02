#include "menger.h"
#include <stdio.h>
#include <math.h>

/**
 * is_hole - Check if position (i, j) is a hole in the Menger sponge
 * @i: Row position
 * @j: Column position
 * Return: 1 if hole, 0 otherwise
 */
int is_hole(int i, int j)
{
	while (i > 0 || j > 0)
	{
		if (i % 3 == 1 && j % 3 == 1)
			return (1);
		i /= 3;
		j /= 3;
	}
	return (0);
}

/**
 * menger - Draws a 2D Menger Sponge
 * @level: Level of the Menger Sponge to draw
 */
void menger(int level)
{
	int size, i, j;

	if (level < 0)
		return;

	size = pow(3, level);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (is_hole(i, j))
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}
