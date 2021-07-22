#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				const binary_tree_t *second);
{
	if (!first || !second)
		return (0);

	if (first == second)
		return (first);

	return (binary_trees_ancestor(first->parent, second->parent));
}
