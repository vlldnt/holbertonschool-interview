# 🏗️ Heap Insert - Holberton School Interview Prep

This project is part of the Holberton School Interview Preparation curriculum. It focuses on implementing basic operations for Max Binary Heaps using C.

## 📚 Content

- **0-binary_tree_node.c**: Create a binary tree node.
- **1-heap_insert.c**: Insert a value into a Max Binary Heap while maintaining heap properties.

## 📝 Requirements

- All code follows the Betty style guide.
- No global variables.
- Up to 5 functions per file.
- All prototypes in `binary_trees.h` (with include guards).
- Compiled on Ubuntu 14.04 LTS with `gcc -Wall -Werror -Wextra -pedantic`.

## 🧩 Data Structures

```c
/**
 * struct binary_tree_s - Binary tree node
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};
typedef struct binary_tree_s heap_t;