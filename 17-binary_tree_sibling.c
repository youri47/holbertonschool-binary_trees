#include "binary_trees.h"

/**
 * binary_tree_sibling - Trouve le sibling (frère/sœur) d'un nœud
 * @node: Pointeur vers le nœud dont on cherche le sibling
 *
 * Description: Un sibling est un nœud qui partage le même parent.
 * Si le nœud est l'enfant gauche du parent, son sibling est l'enfant droit.
 * Si le nœud est l'enfant droit du parent, son sibling est l'enfant gauche.
 *
 * Conditions pour avoir un sibling:
 * - Le nœud doit exister (pas NULL)
 * - Le nœud doit avoir un parent (pas la racine)
 * - Le parent doit avoir deux enfants
 *
 * Return: Pointeur vers le sibling, ou NULL si:
 *         - node est NULL
 *         - node->parent est NULL (c'est la racine)
 *         - node n'a pas de sibling (parent a 1 seul enfant)
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/* Si le nœud est NULL, pas de sibling */
	if (node == NULL)
		return (NULL);

	/* Si le nœud n'a pas de parent, c'est la racine, pas de sibling */
	if (node->parent == NULL)
		return (NULL);

	/* Si le nœud est l'enfant gauche, retourner l'enfant droit du parent */
	if (node->parent->left == node)
		return (node->parent->right);

	/* Si le nœud est l'enfant droit, retourner l'enfant gauche du parent */
	if (node->parent->right == node)
		return (node->parent->left);

	/* Cas par défaut (ne devrait jamais arriver) */
	return (NULL);
}
