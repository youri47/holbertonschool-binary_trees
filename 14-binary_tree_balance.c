#include "binary_trees.h"

/**
 * binary_tree_height_balance - Mesure la hauteur pour le calcul du balance
 * @tree: Pointeur vers le nœud racine
 *
 * Description: Cette fonction auxiliaire calcule la hauteur d'un arbre
 * en incluant le nœud lui-même. C'est différent de binary_tree_height
 * de l'exercice 9 qui compte seulement les arêtes.
 *
 * Pour le balance factor:
 * - Un arbre NULL a une hauteur de 0
 * - Un arbre avec un nœud a une hauteur de 1
 * - Hauteur = 1 + max(hauteur_gauche, hauteur_droite)
 *
 * Return: La hauteur de l'arbre, ou 0 si tree est NULL
 */
size_t binary_tree_height_balance(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	/* Si l'arbre est NULL, la hauteur est 0 */
	if (tree == NULL)
		return (0);

	/* Calculer récursivement la hauteur du sous-arbre gauche */
	left_height = binary_tree_height_balance(tree->left);

	/* Calculer récursivement la hauteur du sous-arbre droit */
	right_height = binary_tree_height_balance(tree->right);

	/* Retourner 1 + la hauteur maximale des deux sous-arbres */
	if (left_height > right_height)
		return (1 + left_height);
	else
		return (1 + right_height);
}

/**
 * binary_tree_balance - Mesure le facteur d'équilibre d'un arbre binaire
 * @tree: Pointeur vers le nœud racine de l'arbre
 *
 * Description: Le facteur d'équilibre (balance factor) est la différence
 * entre la hauteur du sous-arbre gauche et celle du sous-arbre droit.
 *
 * Balance Factor = Hauteur(gauche) - Hauteur(droite)
 *
 * Interprétation:
 * - BF > 0 : Sous-arbre gauche plus grand (penche à gauche)
 * - BF = 0 : Arbre équilibré
 * - BF < 0 : Sous-arbre droit plus grand (penche à droite)
 *
 * Dans un arbre AVL équilibré, le balance factor doit être -1, 0 ou 1.
 *
 * Return: Le facteur d'équilibre, ou 0 si tree est NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	/* Si l'arbre est NULL, le balance factor est 0 */
	if (tree == NULL)
		return (0);

	/* Calculer la hauteur du sous-arbre gauche */
	left_height = (int)binary_tree_height_balance(tree->left);

	/* Calculer la hauteur du sous-arbre droit */
	right_height = (int)binary_tree_height_balance(tree->right);

	/* Retourner la différence (balance factor) */
	return (left_height - right_height);
}
