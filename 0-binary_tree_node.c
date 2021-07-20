#include "binary_trees.h"

/**
 * binary_tree_node - that creates a binary tree node
 * @parent: parent node of the node to create
 * @value: value to put in the new node
 * Return: pointer to the created node, or NULL
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (!new_node)
		return (0);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = 0;
	new_node->right = 0;

	return (new_node);
}
