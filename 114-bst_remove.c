#include "binary_trees.h"
#include "104-binary_tree_rotate_right.c"

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *cur = root, *new_root = 0;

	if (!root)
		return (0);

	while (cur)
	{
		if (cur->n == value)
		{
			new_root = cur->right ? cur->right : cur->left;

			while (new_root && new_root->left)	
				new_root = new_root->left;

			new_root->parent->left = 0;
			new_root->parent = cur->parent;

			if (cur->parent)
			{
				if (cur->parent->left == cur)
					cur->parent->left = new_root;
				else
					cur->parent->right = new_root;
			}
			new_root->left = cur->left;

			if (cur->left)
				cur->left->parent = new_root;

			new_root->right = cur->right;

			if (cur->right)
				cur->right->parent = new_root;

			printf("%i\n", root->n);
			free(cur);

			if (!new_root->parent)
				root = new_root;
			return root;
		}
		else if (cur->n > value)
			cur = cur->left;
		else
			cur = cur->right;
	}

	return (root);
}
