#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insère un nœud comme enfant droit d'un autre
 * @parent: Pointeur vers le nœud parent où insérer l'enfant droit
 * @value: Valeur à stocker dans le nouveau nœud
 *
 * Description: Cette fonction crée un nouveau nœud et l'insère comme
 * enfant droit du parent. Si le parent a déjà un enfant droit:
 * 1. Le nouveau nœud prend la place de l'ancien enfant droit
 * 2. L'ancien enfant droit devient l'enfant droit du nouveau nœud
 *
 * Exemple:
 * Avant:         Après insertion de 54:
 *   98              98
 *    \               \
 *   402              54
 *                     \
 *                    402
 *
 * Return: Pointeur vers le nouveau nœud créé, ou NULL en cas d'échec
 *         ou si parent est NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;
	binary_tree_t *old_right;

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

	/* Sauvegarder l'ancien enfant droit du parent */
	old_right = parent->right;

	/* Le nouveau nœud devient l'enfant droit du parent */
	parent->right = new_node;

	/* Si le parent avait déjà un enfant droit */
	if (old_right != NULL)
	{
		/* L'ancien enfant droit devient l'enfant droit du nouveau nœud */
		new_node->right = old_right;
		/* Mettre à jour le parent de l'ancien enfant droit */
		old_right->parent = new_node;
	}

	return (new_node);
}
