#!/usr/bin/python3
'''
    Function that returns a list of listss of integer
    représentatuin the pascale truengle of n
'''


def pascal_triangle(n):
    '''return a Pascal Triangle in list of lists'''
    if n <= 0:
        return []

    triangle = []

    for i in range(n):
        row = [1] * (i + 1)  # Starts with a 1 and end with a 1

        for j in range(1, i):
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]

        triangle.append(row)

    return triangle
