#include "binary_trees.h"

/**
 * binary_tree_height_perfect - Calcule la hauteur pour vérifier si perfect
 * @tree: Pointeur vers le nœud racine
 *
 * Description: Cette fonction auxiliaire calcule la hauteur en comptant
 * les nœuds (pas les arêtes). Nécessaire pour la vérification perfect.
 *
 * Return: La hauteur de l'arbre, ou 0 si tree est NULL
 */
size_t binary_tree_height_perfect(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height_perfect(tree->left);
	right_height = binary_tree_height_perfect(tree->right);

	if (left_height > right_height)
		return (1 + left_height);
	else
		return (1 + right_height);
}

/**
 * binary_tree_is_perfect - Vérifie si un arbre binaire est parfait
 * @tree: Pointeur vers le nœud racine de l'arbre à vérifier
 *
 * Description: Un arbre binaire est "perfect" si:
 * 1. Tous les niveaux sont complètement remplis
 * 2. Toutes les feuilles sont au même niveau
 * 3. Chaque nœud interne a exactement 2 enfants
 *
 * Un arbre parfait est aussi full et complete.
 *
 * Algorithme:
 * 1. Si tree est NULL, retourner 0
 * 2. Si c'est une feuille, retourner 1
 * 3. Si un sous-arbre est NULL mais pas l'autre, retourner 0
 * 4. Si les hauteurs des sous-arbres diffèrent, retourner 0
 * 5. Vérifier récursivement que les deux sous-arbres sont parfaits
 *
 * Return: 1 si l'arbre est parfait, 0 sinon
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	/* Si l'arbre est NULL, ce n'est pas un arbre parfait */
	if (tree == NULL)
		return (0);

	/* Calculer les hauteurs des sous-arbres */
	left_height = binary_tree_height_perfect(tree->left);
	right_height = binary_tree_height_perfect(tree->right);

	/* Si c'est une feuille (les deux hauteurs sont 0), c'est parfait */
	if (left_height == 0 && right_height == 0)
		return (1);

	/* Si les hauteurs sont différentes, ce n'est pas parfait */
	if (left_height != right_height)
		return (0);

	/* Vérifier récursivement que les deux sous-arbres sont parfaits */
	return (binary_tree_is_perfect(tree->left) &&
		binary_tree_is_perfect(tree->right));
}
