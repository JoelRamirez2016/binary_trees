#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root = 0, *new_left_root = 0;

	if (tree && tree->left)
	{
		new_root = tree->left;
		new_left_root = new_root->right;
		new_root->parent = tree->parent;

		if (tree->parent)
		{
			if (tree->parent->left == tree)
				tree->parent->left = new_root;
			else
				tree->parent->right = new_root;
		}

		tree->left = new_left_root;

		if (new_left_root)
			new_left_root->parent = tree->left;

		new_root->right = tree;
		tree->parent = new_root;
	}

	return (new_root);
}
