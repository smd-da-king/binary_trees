#include "binary_trees.h"

/**
 * binary_tree_size - get the size of a binary tree
 * @tree: the binary tree
 * Return: number of nodes in the binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	size++;
	size += binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);
	return (size);
}

/**
 * check_is_complete - binary_tree_is_complete helper
 * @root: tree
 * @index: index of the node
 * @size: size of the tree
 * Return: 0 (not complete) | 1 (complete)
 */
int check_is_complete(const binary_tree_t *root, int index, int size)
{

	if (root == NULL)
		return (1);

	if (index >= size)
		return (0);

	return (check_is_complete(root->left, 2 * index + 1, size)
		&& check_is_complete(root->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_complete - check if a binary tree is complete
 * @tree: tree
 * Return: 0 (not complete) | 1 (complete)
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (check_is_complete(tree, 0, (int)binary_tree_size(tree)));
}
