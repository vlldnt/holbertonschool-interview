#!/usr/bin/python3
"""Calculate the perimeter of an island given in the grid"""


def island_perimeter(grid):
    """Return the perimeter of the island described in grid"""
    if not grid:
        return 0

    size = len(grid)
    perimeter = 0

    for i in range(size):
        for j in range(size):
            if grid[i][j] == 1:
                perimeter += 4
                # Check the top case
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                # Check the left case
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2

    return perimeter
