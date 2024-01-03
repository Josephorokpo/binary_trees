#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Initialize a queue for level-order traversal */
	queue_t *queue = NULL;
	int level_has_null = 0;

	/* Enqueue the root node */
	queue_push(&queue, (void *)tree);

	/* Perform level-order traversal */
	while (queue != NULL)
	{
		const binary_tree_t *current = (const binary_tree_t *)queue_pop(&queue);

		/* Check for NULL in the level */
		if (current == NULL)
			level_has_null = 1;
		else
		{
			/* If NULL was found in the previous level, the tree is not complete */
			if (level_has_null)
			{
				queue_free(&queue);
				return (0);
			}

			/* Enqueue the left child */
			queue_push(&queue, (void *)current->left);

			/* Enqueue the right child */
			queue_push(&queue, (void *)current->right);
		}
	}

	/* The tree is complete if no NULL was found in the levels */
	queue_free(&queue);
	return (1);
}
