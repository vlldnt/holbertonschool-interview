#!/usr/bin/python3
'''Calculate the pertimeter of an insland given in the grid'''


def island_perimeter(grid):
    '''Fucntion to calculate the perimeter of an inland of 1 '''
    if not grid:
        return None

    size = len(grid)
    perimeter = 0

    for i in range(size):
        for j in range(size):
            if grid[i][j] == 1:
                # Init perimeter to 4 for on case (4 sides)
                perimeter += 4
                # check if top value == 1
                if grid[i + 1][j] == 1:
                    perimeter -= 1

                # check if bottom value == 1
                if grid[i - 1][j] == 1:
                    perimeter -= 1

                # check if right value == 1
                if grid[i][j + 1] == 1:
                    perimeter -= 1

                # check if left value == 1
                if grid[i][j - 1] == 1:
                    perimeter -= 1
    return perimeter
