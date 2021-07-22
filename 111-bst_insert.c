#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *cur;

	if (!tree)
		return (0);

	if (!*tree)
		return (*tree = (bst_t *) binary_tree_node(NULL, value));

	cur = *tree;

	while (cur)
		if (cur->n > value)
		{
			if (!cur->left)
				return (cur->left = binary_tree_node(cur, value));
			cur = cur->left;
		}
		else if (cur->n < value)
		{
			if (!cur->right)
				return (cur->right = binary_tree_node(cur, value));
			cur = cur->right;
		}
		else
			return (0);
	return (*tree);
}
