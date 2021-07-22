#include "binary_trees.h"
#include "limits.h"

int isBST(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (tree ? isBST(tree, INT_MIN, INT_MAX) : 0);
}

/**
 * isBST - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * @min: min value for check in each subtree
 * @max: max value for check in each subtree
 */
int isBST(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (isBST(tree->left, min, tree->n - 1) &&
		isBST(tree->right, tree->n + 1 , max));
}
