#include "binary_trees.h"

/**
 * is_bst_util - Utility function to check if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min: Pointer to the minimum valid value for the current subtree
 * @max: Pointer to the maximum valid value for the current subtree
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int is_bst_util(const binary_tree_t *tree, const binary_tree_t *min, const binary_tree_t *max)
{
	int current_value;

	if (tree == NULL)
		return 1;

	/* Check if the current node's value is within the valid range */
	current_value = tree->n;

	if ((min != NULL && current_value <= min->n) || (max != NULL && current_value >= max->n))
		return 0;

	/* Recursively check the left and right subtrees with updated ranges */
	return (is_bst_util(tree->left, min, tree) && is_bst_util(tree->right, tree, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return 0;

	return is_bst_util(tree, NULL, NULL);
}
