#!/usr/bin/python3
'''Return: Integer indicating total amount of rainwater retained.'''


def rain(walls):
    '''Return: Integer indicating total amount of rainwater retained.'''
    if not walls or len(walls) < 3:
        return 0

    n = len(walls)
    left_max = [0] * n
    right_max = [0] * n

    # left_max[i] = highest wall from 0..i
    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    # right_max[i] = highest wall from i..n-1
    right_max[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    water = 0
    for i in range(n):
        trapped = min(left_max[i], right_max[i]) - walls[i]
        if trapped > 0:
            water += trapped

    return water
