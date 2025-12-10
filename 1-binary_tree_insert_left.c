#include "binary_trees.h"

/**
 * binary_tree_insert_left - Insère un nœud comme enfant gauche d'un autre
 * @parent: Pointeur vers le nœud parent où insérer l'enfant gauche
 * @value: Valeur à stocker dans le nouveau nœud
 *
 * Description: Cette fonction crée un nouveau nœud et l'insère comme
 * enfant gauche du parent. Si le parent a déjà un enfant gauche:
 * 1. Le nouveau nœud prend la place de l'ancien enfant gauche
 * 2. L'ancien enfant gauche devient l'enfant gauche du nouveau nœud
 *
 * Exemple:
 * Avant:         Après insertion de 54:
 *   98              98
 *  /               /
 * 12              54
 *                /
 *               12
 *
 * Return: Pointeur vers le nouveau nœud créé, ou NULL en cas d'échec
 *         ou si parent est NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;
	binary_tree_t *old_left;

	/* Si le parent est NULL, on ne peut pas insérer */
	if (parent == NULL)
		return (NULL);

	/* Créer le nouveau nœud */
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	/* Initialiser le nouveau nœud */
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	/* Sauvegarder l'ancien enfant gauche du parent */
	old_left = parent->left;

	/* Le nouveau nœud devient l'enfant gauche du parent */
	parent->left = new_node;

	/* Si le parent avait déjà un enfant gauche */
	if (old_left != NULL)
	{
		/* L'ancien enfant gauche devient l'enfant gauche du nouveau nœud */
		new_node->left = old_left;
		/* Mettre à jour le parent de l'ancien enfant gauche */
		old_left->parent = new_node;
	}

	return (new_node);
}
