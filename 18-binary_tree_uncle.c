#include "binary_trees.h"

/**
 * binary_tree_uncle - Trouve l'oncle d'un nœud
 * @node: Pointeur vers le nœud dont on cherche l'oncle
 *
 * Description: Un oncle est le sibling (frère/sœur) du parent d'un nœud.
 * Pour avoir un oncle, un nœud doit avoir:
 * 1. Un parent
 * 2. Un grand-parent (parent du parent)
 * 3. Le parent doit avoir un sibling
 *
 * L'oncle est l'autre enfant du grand-parent (pas le parent).
 *
 * Exemples:
 *       Grandparent
 *        /      \
 *    Parent    Uncle
 *     /
 *   Node
 *
 * Return: Pointeur vers l'oncle, ou NULL si:
 *         - node est NULL
 *         - node n'a pas de parent
 *         - node n'a pas de grand-parent (parent est la racine)
 *         - le parent n'a pas de sibling (grand-parent a 1 seul enfant)
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* Si le nœud est NULL, pas d'oncle */
	if (node == NULL)
		return (NULL);

	/* Si le nœud n'a pas de parent, pas d'oncle */
	if (node->parent == NULL)
		return (NULL);

	/* Si le parent n'a pas de parent (grand-parent), pas d'oncle */
	if (node->parent->parent == NULL)
		return (NULL);

	/* L'oncle est le sibling du parent */
	/* Si parent est l'enfant gauche, oncle est l'enfant droit */
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);

	/* Si parent est l'enfant droit, oncle est l'enfant gauche */
	if (node->parent->parent->right == node->parent)
		return (node->parent->parent->left);

	/* Cas par défaut (ne devrait jamais arriver) */
	return (NULL);
}
