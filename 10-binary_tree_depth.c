#include "binary_trees.h"

/**
 * binary_tree_depth - Mesure la profondeur d'un nœud dans un arbre binaire
 * @tree: Pointeur vers le nœud dont on veut mesurer la profondeur
 *
 * Description: La profondeur d'un nœud est le nombre d'arêtes (edges)
 * depuis la racine jusqu'à ce nœud.
 *
 * Exemples:
 * - La racine (parent == NULL) a une profondeur de 0
 * - Un enfant direct de la racine a une profondeur de 1
 * - Un arbre NULL a une profondeur de 0
 *
 * Algorithme récursif:
 * 1. Si le nœud est NULL, retourner 0
 * 2. Si le nœud n'a pas de parent (c'est la racine), retourner 0
 * 3. Sinon, retourner 1 + profondeur(parent)
 *
 * Return: La profondeur du nœud, ou 0 si tree est NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	/* Si le nœud est NULL, la profondeur est 0 */
	if (tree == NULL)
		return (0);

	/* Si le nœud n'a pas de parent, c'est la racine (profondeur 0) */
	if (tree->parent == NULL)
		return (0);

	/* Sinon, la profondeur = 1 + profondeur du parent */
	return (1 + binary_tree_depth(tree->parent));
}
