#include <stdlib.h>
#include "binary_trees.h"

/**
 * insert_bottom - finds the first available spot in a complete binary tree
 * @root: pointer to the root node
 * @value: value to insert
 * Return: pointer to the inserted node
 */
heap_t *insert_bottom(heap_t *root, int value)
{
	/* Node pointers for line by line (BFS) check */
	heap_t *nodes[1024];
	/* Index for the current node being checked*/
	int i = 0;
	/* Number of nodes currently */
	int count = 0;
	/* Pointer to the node currently being processed */
	heap_t *current_node = NULL;

	/* Start line checking with the root: node[0] */
	nodes[count++] = root;

	/* Process nodes while there are nodes to check */
	while (i < count)
	{
		/* Get the next node to process */
		current_node = nodes[i++];

		/* If left child is empty, insert the new node here */
		if (current_node->left == NULL)
		{
			current_node->left = binary_tree_node(current_node, value);
			return (current_node->left);
		}
		/* Else: continue to the left side */
		else
			nodes[count++] = current_node->left;

		/* If right child is empty, insert the new node here */
		if (current_node->right == NULL)
		{
			current_node->right = binary_tree_node(current_node, value);
			return (current_node->right);
		}
		/* Else: continue to the right side */
		else
			nodes[count++] = current_node->right;
	}
	return (NULL);
}

/**
 * swap_node - swaps node values to maintain max-heap property
 * @node: pointer to the newly inserted node
 */
void swap_node(heap_t *node)
{
	int tmp;

	/* Swap values with parent while the node is greater than its parent */
	while (node->parent && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}
}

/**
 * heap_insert - inserts a value in a Max Binary Heap
 * @root: double pointer to the root node
 * @value: value to insert
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	/* Check if root not existing pointer */
	if (root == NULL)
		return (NULL);

	/* If nothing, create the root node */
	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	/* Insert the new node at the bottom and restore heap property */
	new_node = insert_bottom(*root, value);
	swap_node(new_node);

	/* Ensure we return the new node containing the inserted value */
	while (new_node->parent && new_node->n != value)
		new_node = new_node->parent;

	return (new_node);
}
