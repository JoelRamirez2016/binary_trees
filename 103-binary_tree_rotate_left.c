#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root = 0, *new_right_root = 0;

	if (tree && tree->right)
	{
		new_root = tree->right;
		new_right_root = new_root->left;
		new_root->parent = tree->parent;

		if (tree->parent)
		{
			if (tree->parent->left == tree)
				tree->parent->left = new_root;
			else
				tree->parent->right = new_root;
		}

		tree->right = new_right_root;

		if (new_right_root)
			new_right_root->parent = tree->right;

		new_root->left = tree;
		tree->parent = new_root;
	}

	return (new_root);
}
