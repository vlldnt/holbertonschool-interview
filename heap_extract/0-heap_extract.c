#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_size - Counts the number of nodes in a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Number of nodes, 0 if NULL
 */
size_t tree_size(const heap_t *tree)
{
    if (!tree)
        return (0);

    return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * get_last_node - Finds the last level-order node in a complete binary tree
 * @root: Pointer to the root node
 * @size: Total number of nodes in the tree
 *
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root, size_t size)
{
    size_t bit;

    for (bit = 1; bit <= size; bit <<= 1)
        ;
    bit >>= 2;

    while (bit > 0)
    {
        if (size & bit)
            root = root->right;
        else
            root = root->left;
        bit >>= 1;
    }

    return (root);
}

/**
 * heapify_down - Restores the max heap property by sifting down
 * @node: Pointer to the node to sift down
 */
void heapify_down(heap_t *node)
{
    heap_t *largest;
    int temp;

    while (node)
    {
        largest = node;

        if (node->left && node->left->n > largest->n)
            largest = node->left;
        if (node->right && node->right->n > largest->n)
            largest = node->right;

        if (largest == node)
            break;

        temp = node->n;
        node->n = largest->n;
        largest->n = temp;

        node = largest;
    }
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
    int value;
    size_t size;
    heap_t *last_node;

    if (!root || !*root)
        return (0);

    value = (*root)->n;

    if (!(*root)->left && !(*root)->right)
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    size = tree_size(*root);
    last_node = get_last_node(*root, size);

    (*root)->n = last_node->n;

    if (last_node->parent->right == last_node)
        last_node->parent->right = NULL;
    else
        last_node->parent->left = NULL;

    free(last_node);

    heapify_down(*root);

    return (value);
}
