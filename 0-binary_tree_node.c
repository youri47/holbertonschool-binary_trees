#include "binary_trees.h"

/**
 * binary_tree_node - Crée un nœud d'arbre binaire.
 *
 * @parent: Un pointeur vers le nœud parent du nœud à créer.
 * @value: La valeur (entier) à placer dans le nouveau nœud.
 *
 * Return: Un pointeur vers le nouveau nœud, ou NULL en cas d'échec.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* 1. Allouer la mémoire pour le nouveau nœud */
	new_node = malloc(sizeof(binary_tree_t));

	/* 2. Vérifier si l'allocation a échoué */
	if (new_node == NULL)
	{
		return (NULL);
	}

	/* 3. Initialiser les membres du nouveau nœud */
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	/* 4. Retourner le pointeur vers le nouveau nœud */
	return (new_node);
}
