#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, \n
	const binary_tree_t *second)
{
	const binary_tree_t *ancestor1, *ancestor2;

	if (first == NULL || second == NULL)
		return (NULL);

	ancestor1 = first;
	while (ancestor1 != NULL)
	{
		ancestor2 = second;
		while (ancestor2 != NULL)
		{
			if (ancestor1 == ancestor2)
				return ((binary_tree_t *)ancestor1);
			ancestor2 = ancestor2->parent;
		}
		ancestor1 = ancestor1->parent;
	}
	return (NULL);
}
