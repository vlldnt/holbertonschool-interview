# Sandpiles

This project implements the sandpile model and its stabilization algorithm, inspired by the Numberphile video on sandpiles. The goal is to compute the sum of two 3x3 sandpiles and stabilize the result according to the rules of the Abelian sandpile model.

## 📚 Problem Description

- You are given two stable 3x3 grids (`grid1` and `grid2`), where each cell contains grains of sand.
- A sandpile is **stable** if no cell contains more than 3 grains.
- The sum of two sandpiles is the cell-by-cell sum of their grids.
- If any cell exceeds 3 grains, it "topples": 4 grains are removed from that cell, and 1 grain is added to each of its 4 neighbors (up, down, left, right).
- The process repeats until all cells are stable.

## 🚀 Usage

- **Prototype:** `void sandpiles_sum(int grid1[3][3], int grid2[3][3]);`
- Both input grids are assumed stable.
- After calling, `grid1` will contain the stable sum.

## 📝 Example

Initial grids:

```
grid1:           grid2:
3 3 3            1 3 1
3 3 3      +     3 3 3
3 3 3            1 3 1
```

After sum and stabilization:

```
4 6 4
6 6 6
4 6 4
=
2 5 2
5 6 5
2 5 2
=
4 2 4
2 6 2
4 2 4
=
0 5 0
5 2 5
0 5 0
=
2 1 2
1 6 1
2 1 2
=
2 2 2
2 2 2
2 2 2
```
