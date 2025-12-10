#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node
 *
 * @parent: A pointer to the parent node of the node to create
 * @value: The value to put in the new node
 *
 * Return: A pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	/* 1. Déclarer un pointeur pour le nouveau nœud */
	binary_tree_t *new_node;

	/* 2. Allouer la mémoire pour le nouveau nœud */
	new_node = malloc(sizeof(binary_tree_t));

	/* 3. Vérifier si l'allocation a échoué */
	if (new_node == NULL)
	{
		return (NULL); /* Retourne NULL en cas d'échec */
	}

	/* 4. Initialiser les membres du nouveau nœud */
	new_node->n = value;       /* La valeur (data) du nœud */
	new_node->parent = parent; /* Le pointeur vers le parent (peut être NULL pour la racine) */
	new_node->left = NULL;     /* Un nouveau nœud n'a pas d'enfant gauche */
	new_node->right = NULL;    /* Un nouveau nœud n'a pas d'enfant droit */

	/* 5. Retourner le pointeur vers le nouveau nœud */
	return (new_node);
}
