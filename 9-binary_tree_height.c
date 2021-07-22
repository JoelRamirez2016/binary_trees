#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of a binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_l, h_r;

	if (tree && (tree->left || tree->right))
	{
		h_l = binary_tree_height(tree->left);
		h_r = binary_tree_height(tree->right);

		if (h_l > h_r)
			return (h_l + 1);
		else
			return (h_r + 1);
	}
	return (0);
}
