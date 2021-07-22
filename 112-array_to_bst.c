#include "binary_trees.h"
/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = 0;
	size_t i;

	if (!array || size < 1)
		return (0);

	for (i = 0; i < size; i++)
	{
		bst_insert(&root, array[i]);

		if (2 * i + 1 < size)
			bst_insert(&root, array[2 * i + 1]);
		if (2 * i + 2 < size)
			bst_insert(&root, array[2 * i + 2]);
	}
	return (root);
}
