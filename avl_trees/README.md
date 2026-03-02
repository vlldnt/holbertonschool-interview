# 🌳 AVL Trees - Holberton School Interview Prep

This project is part of the Holberton School Interview Preparation curriculum. It focuses on checking if a binary tree is a valid AVL Tree.

## 📚 Content

- **0-binary_tree_is_avl.c**: Function that checks if a binary tree is a valid AVL Tree.

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
typedef struct binary_tree_s binary_tree_t;
```

## 🔍 AVL Tree Properties

- An AVL Tree is a BST.
- The difference between heights of left and right subtrees cannot be more than one.
- The left and right subtrees must each also be a binary search tree.
