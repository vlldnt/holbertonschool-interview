#include <stdlib.h>

/**
 * sandpiles_sum - adds two 3x3 sandpile grids
 * @grid1: first 3x3 grid
 * @grid2: second 3x3 grid
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}
