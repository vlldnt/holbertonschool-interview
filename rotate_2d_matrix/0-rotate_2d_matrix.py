#!/usr/bin/python3
'''rotate a 2d matrix 90 degrees clockwise in-place'''


def rotate_2d_matrix(matrix):
    reversed_matrix = matrix[::-1]
    rotated = zip(*reversed_matrix)
    matrix[:] = [list(row) for row in rotated]
