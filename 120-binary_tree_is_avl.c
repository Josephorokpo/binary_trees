#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height, balance_factor;

	if (tree == NULL)
		return (0);

	left_height = (int)binary_tree_height(tree->left);
	right_height = (int)binary_tree_height(tree->right);

	balance_factor = left_height - right_height;

	if (balance_factor < -1 || balance_factor > 1)
		return (0);

	if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
		return (0);

	return (1);
}
