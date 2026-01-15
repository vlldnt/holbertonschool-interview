#!/usr/bin/python3
'''rotate a 2d matrix 90 degrees clockwise in-place'''

import numpy as np


def rotate_2d_matrix(matrix):
    n = len(matrix)
    rotated = np.rot90(matrix, -1)
    for i in range(n):
        for j in range(n):
            matrix[i][j] = int(rotated[i][j])
