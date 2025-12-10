#include "binary_trees.h"

/**
 * binary_tree_delete - Supprime un arbre binaire entier
 * @tree: Pointeur vers le nœud racine de l'arbre à supprimer
 *
 * Description: Cette fonction supprime récursivement tous les nœuds
 * d'un arbre binaire. Elle utilise un parcours en post-ordre pour
 * s'assurer que les enfants sont supprimés avant leurs parents.
 *
 * Algorithme:
 * 1. Si l'arbre est NULL, on ne fait rien
 * 2. On supprime récursivement le sous-arbre gauche
 * 3. On supprime récursivement le sous-arbre droit
 * 4. On libère la mémoire du nœud courant
 */
void binary_tree_delete(binary_tree_t *tree)
{
	/* Si l'arbre est NULL, on ne fait rien */
	if (tree == NULL)
		return;

	/* Supprime récursivement le sous-arbre gauche */
	binary_tree_delete(tree->left);

	/* Supprime récursivement le sous-arbre droit */
	binary_tree_delete(tree->right);

	/* Libère la mémoire du nœud courant */
	free(tree);
}
