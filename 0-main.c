#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * main - Point d'entrée du test pour la fonction binary_tree_node.
 *
 * Return: 0 en cas de succès, non-zéro si échec.
 */
int main(void)
{
	binary_tree_t *root;
	binary_tree_t *temp_node;

	/* 1. Création du nœud Racine (parent = NULL) */
	root = binary_tree_node(NULL, 98);
	if (!root)
	{
		fprintf(stderr, "Erreur: Impossible de créer la racine.\n");
		return (1);
	}

	/* Affichage de la racine (si binary_tree_print est disponible) */
	printf("Arbre après création de la Racine:\n");
	binary_tree_print(root);

	/* 2. Création d'un enfant gauche */
	temp_node = binary_tree_node(root, 12);
	if (!temp_node)
	{
		fprintf(stderr, "Erreur: Impossible de créer l'enfant gauche.\n");
		return (1);
	}
	root->left = temp_node;

	/* 3. Création d'un enfant droit */
	temp_node = binary_tree_node(root, 402);
	if (!temp_node)
	{
		fprintf(stderr, "Erreur: Impossible de créer l'enfant droit.\n");
		return (1);
	}
	root->right = temp_node;

	/* 4. Affichage de l'arbre complet */
	printf("\nArbre après ajout des enfants:\n");
	binary_tree_print(root);

	/*
	 * Remarque: En C, il est crucial de libérer la mémoire.
	 * Dans un vrai projet, il faudrait une fonction pour libérer l'arbre
	 * entier (par exemple, binary_tree_delete ou post-order traversal).
	 * Pour ce test simple, nous ne le ferons pas, sauf si l'on détruit manuellement.
	 */
	/*
	free(root->left);
	free(root->right);
	free(root);
	*/

	return (0);
}
