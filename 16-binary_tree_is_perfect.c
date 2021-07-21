#include "binary_trees.h"
#include "10-binary_tree_depth.c"
#include "9-binary_tree_height.c"

int is_perfect(const binary_tree_t *tree, int d, int lvl);

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if binary tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	return (tree ? is_perfect(tree, binary_tree_height(tree) + 1, 0) : 0);
}

/**
 * is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * @d: depth of the tree
 * @lvl: current depth (level)
 * Return: 1 if binary tree is perfect, otherwise 0
 */
int is_perfect(const binary_tree_t *tree, int d, int lvl)
{
	if (!tree->left && !tree->right)
		return (d == lvl + 1);

	if (!tree->left || !tree->right)
		return (0);

	return (is_perfect(tree->left, d, lvl + 1) &&
		is_perfect(tree->right, d, lvl + 1));
}
