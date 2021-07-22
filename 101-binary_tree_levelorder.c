#include "binary_trees.h"
#include "9-binary_tree_height.c"

void currentLevelTravel(const binary_tree_t *tree, void (*func)(int), int lvl);

/**
 * binary_tree_levelorder - through a binary tree using levelorder traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int i, h = binary_tree_height(tree);

	for (i = 0; tree && i < h + 1 && func; i++)
		currentLevelTravel(tree, func, i);
}

/**
 * currentLevelTravel - through a binary tree using levelorder traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * @lvl: current level
 */
void currentLevelTravel(const binary_tree_t *tree, void (*func)(int), int lvl)
{
	if (lvl == 0)
		func(tree->n);

	else if (lvl > 0)
	{
		currentLevelTravel(tree->left, func, lvl - 1);
		currentLevelTravel(tree->right, func, lvl - 1);
	}
}
