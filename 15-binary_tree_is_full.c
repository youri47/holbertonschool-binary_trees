#include "binary_trees.h"

/**
 * binary_tree_is_full - Vérifie si un arbre binaire est full
 * @tree: Pointeur vers le nœud racine de l'arbre à vérifier
 *
 * Description: Un arbre binaire est "full" (ou "strict") si chaque nœud
 * a soit 0 enfant (c'est une feuille), soit exactement 2 enfants.
 * Aucun nœud ne peut avoir seulement 1 enfant.
 *
 * Conditions pour être full:
 * - Tous les nœuds ont 0 ou 2 enfants
 * - Pas de nœud avec 1 seul enfant
 *
 * Algorithme:
 * 1. Si tree est NULL, retourner 0
 * 2. Si c'est une feuille (0 enfant), retourner 1 (OK)
 * 3. Si le nœud a 1 seul enfant, retourner 0 (PAS OK)
 * 4. Si le nœud a 2 enfants, vérifier récursivement les sous-arbres
 *
 * Return: 1 si l'arbre est full, 0 sinon
 *         Si tree est NULL, retourne 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	/* Si l'arbre est NULL, ce n'est pas un arbre full */
	if (tree == NULL)
		return (0);

	/* Si c'est une feuille (0 enfant), c'est OK pour un arbre full */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* Si le nœud a 1 seul enfant, ce n'est pas un arbre full */
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	/* Si le nœud a 2 enfants, vérifier récursivement les sous-arbres */
	return (binary_tree_is_full(tree->left) &&
		binary_tree_is_full(tree->right));
}
