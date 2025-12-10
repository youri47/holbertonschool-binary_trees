#include "binary_trees.h"

/**
 * binary_tree_height - Mesure la hauteur d'un arbre binaire
 * @tree: Pointeur vers le nœud racine de l'arbre à mesurer
 *
 * Description: La hauteur d'un arbre est le nombre d'arêtes (edges)
 * sur le chemin le plus long de la racine jusqu'à une feuille.
 *
 * Exemples:
 * - Un arbre NULL a une hauteur de 0
 * - Une feuille (nœud sans enfants) a une hauteur de 0
 * - Un nœud avec un seul enfant a une hauteur de 1
 *
 * Algorithme récursif:
 * 1. Si l'arbre est NULL ou c'est une feuille, retourner 0
 * 2. Calculer récursivement la hauteur du sous-arbre gauche
 * 3. Calculer récursivement la hauteur du sous-arbre droit
 * 4. Retourner 1 + max(hauteur_gauche, hauteur_droite)
 *
 * Return: La hauteur de l'arbre, ou 0 si tree est NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	/* Si l'arbre est NULL, la hauteur est 0 */
	if (tree == NULL)
		return (0);

	/* Si c'est une feuille (pas d'enfants), la hauteur est 0 */
	if (tree->left == NULL && tree->right == NULL)
		return (0);

	/* Calculer récursivement la hauteur du sous-arbre gauche */
	height_left = binary_tree_height(tree->left);

	/* Calculer récursivement la hauteur du sous-arbre droit */
	height_right = binary_tree_height(tree->right);

	/* Retourner 1 + la hauteur maximale des deux sous-arbres */
	if (height_left > height_right)
		return (1 + height_left);
	else
		return (1 + height_right);
}
