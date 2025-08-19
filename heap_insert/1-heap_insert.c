#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - insert in binary tree node
 * @root: pointer to the root node
 * @value: value to store in the new node
 *
 * Return: pointer to the created node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		(*root)->left = new;
		return (*root);
	}
}
