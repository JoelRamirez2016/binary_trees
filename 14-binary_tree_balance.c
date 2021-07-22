#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to mesures the balance factor
 * Return: balance factor of a binary tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	return (tree ?
		binary_tree_height(tree->left) - binary_tree_height(tree->right) : 0);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of a binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_l, h_r, height = 0;

	if (tree)
	{
		h_l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		h_r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		height = h_l > h_r ? h_l : h_r;
	}
	return (height);
}
