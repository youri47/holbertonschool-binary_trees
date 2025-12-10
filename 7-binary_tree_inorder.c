#include "binary_trees.h"

/**
 * binary_tree_inorder - Parcourt un arbre binaire en in-ordre
 * @tree: Pointeur vers le nœud racine de l'arbre à parcourir
 * @func: Pointeur vers une fonction à appeler pour chaque nœud
 *
 * Description: Le parcours in-ordre visite les nœuds dans l'ordre:
 * 1. Sous-arbre gauche (LEFT)
 * 2. Nœud courant (ROOT)
 * 3. Sous-arbre droit (RIGHT)
 *
 * Pour un arbre binaire de recherche, ce parcours donne les valeurs
 * dans l'ordre croissant.
 *
 * La valeur du nœud est passée en paramètre à la fonction func.
 * Si tree ou func est NULL, la fonction ne fait rien.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	/* Si l'arbre ou la fonction est NULL, on ne fait rien */
	if (tree == NULL || func == NULL)
		return;

	/* 1. Parcourir le sous-arbre gauche (LEFT) */
	binary_tree_inorder(tree->left, func);

	/* 2. Visiter le nœud courant (ROOT) */
	func(tree->n);

	/* 3. Parcourir le sous-arbre droit (RIGHT) */
	binary_tree_inorder(tree->right, func);
}
