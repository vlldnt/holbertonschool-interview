#!/usr/bin/python3
'''rotate a 2d matrix 90 degrees clockwise in-place'''


def rotate_2d_matrix(matrix):
    '''Rotate a 3x3 2D matrix 90 degrees clockwise in-place'''
    # original values
    a, b, c = matrix[0][0], matrix[0][1], matrix[0][2]
    d, e, f = matrix[1][0], matrix[1][1], matrix[1][2]
    g, h, i = matrix[2][0], matrix[2][1], matrix[2][2]

    # rotated values
    matrix[0][0], matrix[0][1], matrix[0][2] = g, d, a
    matrix[1][0], matrix[1][1], matrix[1][2] = h, e, b
    matrix[2][0], matrix[2][1], matrix[2][2] = i, f, c
