#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *current, *parent;

	if (tree == NULL)
		return NULL;

	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return NULL;

	if (*tree == NULL)
	{
		*tree = new_node;
		return new_node;
	}

	current = *tree;
	parent = NULL;

	while (current != NULL)
	{
		parent = current;

		if (value == current->n)
		{
			free(new_node);
			return NULL; // Value already present, ignore
		}
		else if (value < current->n)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}

	new_node->parent = parent;
	if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	return new_node;
}
