#include "binary_trees.h"

bst_t *bst_remove_node(bst_t *, bst_t *);

/**
 * bst_remove_node - removes a node from a Binary Search Tree
 * @root: root of the tree
 * @cur: pointer to the node will remove
 * Return: pointer to the new root node of the tree after removing
 */
bst_t *bst_remove_node(bst_t *root, bst_t *cur)
{
	bst_t *new_root = cur->right ? cur->right : cur->left;

	while (new_root && new_root->left)
		new_root = new_root->left;

	if (new_root)
	{
		new_root->left = cur->left;

		if (cur->left)
			cur->left->parent = new_root;
		new_root->right = cur->right;

		if (cur->right)
			cur->right->parent = new_root;

		new_root->parent->left = 0;
		new_root->parent = cur->parent;

		if (!new_root->parent)
			root = new_root;
	}
	if (cur->parent)
	{
		if (cur->parent->left == cur)
			cur->parent->left = new_root;
		else
			cur->parent->right = new_root;
	}
	free(cur);
	return (root);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after removing
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *cur = root;

	while (cur)
	{
		if (cur->n == value)
			return (bst_remove_node(root, cur));

		else if (cur->n > value)
			cur = cur->left;

		else
			cur = cur->right;
	}
	return (root);
}
