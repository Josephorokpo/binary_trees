#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: This function performs a level-order traversal of the binary tree,
 * calling the given function for each visited node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* Initialize a queue for level-order traversal */
	queue_t *queue = NULL;

	/* Enqueue the root node */
	queue_push(&queue, (void *)tree);

	/* Perform level-order traversal */
	while (queue != NULL)
	{
		const binary_tree_t *current = (const binary_tree_t *)queue_pop(&queue);

		/* Call the given function for the current node */
		func(current->n);

		/* Enqueue the left child if exists */
		if (current->left != NULL)
			queue_push(&queue, (void *)current->left);

		/* Enqueue the right child if exists */
		if (current->right != NULL)
			queue_push(&queue, (void *)current->right);
	}

	/* Free the queue after traversal */
	queue_free(&queue);
}
