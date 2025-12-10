#include "binary_trees.h"

/**
 * binary_tree_preorder - Parcourt un arbre binaire en pré-ordre
 * @tree: Pointeur vers le nœud racine de l'arbre à parcourir
 * @func: Pointeur vers une fonction à appeler pour chaque nœud
 *
 * Description: Le parcours pré-ordre visite les nœuds dans l'ordre:
 * 1. Nœud courant (ROOT)
 * 2. Sous-arbre gauche (LEFT)
 * 3. Sous-arbre droit (RIGHT)
 *
 * La valeur du nœud est passée en paramètre à la fonction func.
 * Si tree ou func est NULL, la fonction ne fait rien.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	/* Si l'arbre ou la fonction est NULL, on ne fait rien */
	if (tree == NULL || func == NULL)
		return;

	/* 1. Visiter le nœud courant (ROOT) */
	func(tree->n);

	/* 2. Parcourir le sous-arbre gauche (LEFT) */
	binary_tree_preorder(tree->left, func);

	/* 3. Parcourir le sous-arbre droit (RIGHT) */
	binary_tree_preorder(tree->right, func);
}
