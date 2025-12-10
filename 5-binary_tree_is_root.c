#include "binary_trees.h"

/**
 * binary_tree_is_root - Vérifie si un nœud est une racine
 * @node: Pointeur vers le nœud à vérifier
 *
 * Description: Une racine est un nœud qui n'a pas de parent.
 * C'est le nœud au sommet de l'arbre, dont le pointeur parent est NULL.
 *
 * Return: 1 si le nœud est une racine, 0 sinon
 *         Si node est NULL, retourne 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	/* Si le nœud est NULL, ce n'est pas une racine */
	if (node == NULL)
		return (0);

	/* Le nœud est une racine si son parent est NULL */
	if (node->parent == NULL)
		return (1);

	/* Sinon, ce n'est pas une racine */
	return (0);
}
