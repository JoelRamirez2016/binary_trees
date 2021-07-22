#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				const binary_tree_t *second)
{
	if (!first || !second)
		return (0);

	if (first == second)
		return ((binary_tree_t *) first);

	if (first == second->parent || !first->parent ||
	(!first->parent && second->parent))
		return (binary_trees_ancestor(first, second->parent));

	if (second == first->parent || !second->parent ||
	(!second->parent && first->parent))
		return (binary_trees_ancestor(first->parent, second));

	return (binary_trees_ancestor(first->parent, second->parent));
}
