#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insère un nœud comme l'enfant droit d'un autre nœud.
 *
 * @parent: Un pointeur vers le nœud parent où insérer l'enfant droit.
 * @value: La valeur à stocker dans le nouveau nœud.
 *
 * Return: Un pointeur vers le nœud créé, ou NULL en cas d'échec
 * ou si le parent est NULL.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;
	binary_tree_t *old_right;

	/* 1. Vérification de la précondition */
	if (parent == NULL)
		return (NULL);

	/* 2. Création du nouveau nœud */
	new_node = binary_tree_node(parent, value);

	if (new_node == NULL)
		return (NULL);

	/* 3. Gestion de l'enfant droit existant (symétrique à l'insertion gauche) */
	if (parent->right != NULL)
	{
		/* Sauvegarder l'ancien enfant droit */
		old_right = parent->right;

		/* L'ancien enfant droit devient l'enfant droit du nouveau nœud */
		new_node->right = old_right;

		/* L'ancien enfant doit maintenant pointer vers le nouveau nœud comme son parent */
		old_right->parent = new_node;
	}

	/* 4. Liaison du nouveau nœud au parent */
	parent->right = new_node;

	return (new_node);
}
