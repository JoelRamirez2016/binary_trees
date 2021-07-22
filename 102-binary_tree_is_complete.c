#include "binary_trees.h"
#include "11-binary_tree_size.c"

int is_complete(const binary_tree_t *tree, int node_index, int size);

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if a binary tree is complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	return (tree ? is_complete(tree, 0, binary_tree_size(tree)) : 0);
}

/**
 * is_complete - using array representation tree checks if a tree is complete
 * @tree: pointer to the root node of the tree to check
 * @node_index: position of the node in a imaginary array
 * @size: number of nodes in the tree
 */
int is_complete(const binary_tree_t *tree, int node_index, int size)
{
	if (!tree)
		return (1);

	if (node_index >= size)
		return (0);

	return (is_complete(tree->left, 2 * node_index + 1 , size) &&
		is_complete(tree->right, 2 * node_index + 2, size));
}
