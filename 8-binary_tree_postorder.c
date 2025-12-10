#include "binary_trees.h"

/**
 * binary_tree_postorder - Parcourt un arbre binaire en post-ordre
 * @tree: Pointeur vers le nœud racine de l'arbre à parcourir
 * @func: Pointeur vers une fonction à appeler pour chaque nœud
 *
 * Description: Le parcours post-ordre visite les nœuds dans l'ordre:
 * 1. Sous-arbre gauche (LEFT)
 * 2. Sous-arbre droit (RIGHT)
 * 3. Nœud courant (ROOT)
 *
 * Ce parcours est particulièrement utile pour supprimer un arbre
 * car on traite les enfants avant le parent.
 *
 * La valeur du nœud est passée en paramètre à la fonction func.
 * Si tree ou func est NULL, la fonction ne fait rien.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	/* Si l'arbre ou la fonction est NULL, on ne fait rien */
	if (tree == NULL || func == NULL)
		return;

	/* 1. Parcourir le sous-arbre gauche (LEFT) */
	binary_tree_postorder(tree->left, func);

	/* 2. Parcourir le sous-arbre droit (RIGHT) */
	binary_tree_postorder(tree->right, func);

	/* 3. Visiter le nœud courant (ROOT) */
	func(tree->n);
}
