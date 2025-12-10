#include "binary_trees.h"

/**
 * binary_tree_size - Mesure la taille d'un arbre binaire
 * @tree: Pointeur vers le nœud racine de l'arbre à mesurer
 *
 * Description: La taille d'un arbre binaire est le nombre total
 * de nœuds qu'il contient.
 *
 * Exemples:
 * - Un arbre NULL a une taille de 0
 * - Un arbre avec un seul nœud a une taille de 1
 * - Un arbre complet avec 3 niveaux a une taille de 7
 *
 * Algorithme récursif:
 * 1. Si l'arbre est NULL, retourner 0
 * 2. Sinon, retourner 1 (nœud courant)
 *                    + taille du sous-arbre gauche
 *                    + taille du sous-arbre droit
 *
 * Return: La taille de l'arbre (nombre de nœuds), ou 0 si tree est NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	/* Si l'arbre est NULL, la taille est 0 */
	if (tree == NULL)
		return (0);

	/* Taille = 1 (nœud courant) + taille(gauche) + taille(droite) */
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
