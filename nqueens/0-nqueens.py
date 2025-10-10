#!/usr/bin/env python3
"""N Queens problem solver using backtracking."""
import sys


def print_solution(solution):
    """Print one solution as a list of [row, col] pairs."""
    print(solution)


def is_safe(row, col, solution):
    """Check if placing a queen at (row, col) is safe."""
    for r, c in solution:
        if c == col or abs(row - r) == abs(col - c):
            return False
    return True


def solve(n, row, solution, solutions):
    """Backtracking solver: place a queen on each row."""
    if row == n:
        solutions.append(list(solution))
        return
    for col in range(n):
        if is_safe(row, col, solution):
            solution.append([row, col])
            solve(n, row + 1, solution, solutions)
            solution.pop()


def main():
    """Main entry point for N Queens solver."""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    if N < 4:
        print("N must be at least 4")
        sys.exit(1)
    solutions = []
    solve(N, 0, [], solutions)
    for sol in solutions:
        print_solution(sol)


if __name__ == "__main__":
    main()
