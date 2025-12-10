#include "binary_trees.h"

/**
 * binary_tree_leaves - Compte le nombre de feuilles dans un arbre binaire
 * @tree: Pointeur vers le nœud racine de l'arbre
 *
 * Description: Une feuille est un nœud qui n'a pas d'enfants.
 * C'est-à-dire que ses pointeurs left et right sont tous les deux NULL.
 *
 * Exemples:
 * - Un arbre NULL a 0 feuille
 * - Un arbre avec un seul nœud a 1 feuille (la racine elle-même)
 * - Un NULL pointer n'est pas une feuille
 *
 * Algorithme récursif:
 * 1. Si l'arbre est NULL, retourner 0
 * 2. Si le nœud est une feuille (left == NULL && right == NULL), retourner 1
 * 3. Sinon, retourner nombre_feuilles(gauche) + nombre_feuilles(droite)
 *
 * Return: Le nombre de feuilles dans l'arbre, ou 0 si tree est NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	/* Si l'arbre est NULL, il n'y a pas de feuilles */
	if (tree == NULL)
		return (0);

	/* Si le nœud est une feuille, on compte 1 */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* Sinon, on compte les feuilles dans les sous-arbres */
	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
