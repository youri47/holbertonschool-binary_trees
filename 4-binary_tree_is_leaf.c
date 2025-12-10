#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Vérifie si un nœud est une feuille
 * @node: Pointeur vers le nœud à vérifier
 *
 * Description: Une feuille est un nœud qui n'a pas d'enfants.
 * Cela signifie que ses pointeurs left et right sont tous les deux NULL.
 *
 * Return: 1 si le nœud est une feuille, 0 sinon
 *         Si node est NULL, retourne 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	/* Si le nœud est NULL, ce n'est pas une feuille */
	if (node == NULL)
		return (0);

	/* Le nœud est une feuille si left ET right sont NULL */
	if (node->left == NULL && node->right == NULL)
		return (1);

	/* Sinon, ce n'est pas une feuille */
	return (0);
}
