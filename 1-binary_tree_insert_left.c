#include "binary_trees.h"

/**
 * binary_tree_insert_left - Insère un nœud comme l'enfant gauche d'un autre nœud.
 *
 * @parent: Un pointeur vers le nœud parent où insérer l'enfant gauche.
 * @value: La valeur à stocker dans le nouveau nœud.
 *
 * Return: Un pointeur vers le nœud créé, ou NULL en cas d'échec
 * ou si le parent est NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;
	binary_tree_t *old_left;

	/* 1. Vérification de la précondition */
	if (parent == NULL)
		return (NULL);

	/* 2. Création du nouveau nœud */
	/* Le nouveau nœud est initialement créé avec 'parent' comme parent */
	new_node = binary_tree_node(parent, value);

	if (new_node == NULL)
		return (NULL);

	/* 3. Gestion de l'enfant existant */
	if (parent->left != NULL)
	{
		/* Sauvegarder l'ancien enfant gauche */
		old_left = parent->left;

		/* Le nouveau nœud prend la place de l'enfant gauche du parent */
		/* new_node->left est déjà NULL, nous n'avons pas besoin de l'écraser */

		/* L'ancien enfant gauche devient l'enfant gauche du nouveau nœud */
		new_node->left = old_left;

		/* L'ancien enfant doit maintenant pointer vers le nouveau nœud comme son parent */
		old_left->parent = new_node;
	}
	/*
	 * Si parent->left était NULL, le nouveau nœud est déjà correctement
	 * initialisé (new_node->left = NULL) et rien d'autre n'est nécessaire ici.
	 */

	/* 4. Liaison du nouveau nœud au parent */
	parent->left = new_node;

	return (new_node);
}
