#include "binary_trees.h"

/**
 * binary_tree_nodes - Compte les nœuds avec au moins 1 enfant
 * @tree: Pointeur vers le nœud racine de l'arbre
 *
 * Description: Un nœud interne est un nœud qui a au moins un enfant
 * (gauche ou droit). Les feuilles (nœuds sans enfants) ne sont pas comptées.
 *
 * Exemples:
 * - Un arbre NULL a 0 nœud interne
 * - Un arbre avec un seul nœud (feuille) a 0 nœud interne
 * - Un nœud avec au moins un enfant est compté
 *
 * Algorithme récursif:
 * 1. Si l'arbre est NULL, retourner 0
 * 2. Si le nœud n'a pas d'enfants (feuille), retourner 0
 * 3. Sinon, retourner 1 + nombre_nœuds_internes(gauche)
 *                         + nombre_nœuds_internes(droite)
 *
 * Return: Le nombre de nœuds avec au moins 1 enfant, ou 0 si tree est NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	/* Si l'arbre est NULL, il n'y a pas de nœud interne */
	if (tree == NULL)
		return (0);

	/* Si le nœud est une feuille (pas d'enfants), on ne compte pas */
	if (tree->left == NULL && tree->right == NULL)
		return (0);

	/* Sinon, on compte 1 + les nœuds internes des sous-arbres */
	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
