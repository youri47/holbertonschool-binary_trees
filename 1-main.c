#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Point d'entrée du test pour la fonction binary_tree_insert_left.
 *
 * Return: 0 en cas de succès, non-zéro si échec.
 */
int main(void)
{
	binary_tree_t *root;
	binary_tree_t *new_node;

	/* Création de la Racine (98) */
	root = binary_tree_node(NULL, 98);
	printf("Arbre Initial (Racine 98):\n");
	binary_tree_print(root);

	/* 1. Insertion simple (pas d'enfant existant) */
	binary_tree_insert_left(root, 12);
	printf("\nArbre après Insertion de 12 (Gauche):\n");
	binary_tree_print(root);
	/* root->left est maintenant 12 */

	/* 2. Insertion avec enfant existant (le cas complexe) */
	/* On insère 54, qui prend la place de 12 */
	new_node = binary_tree_insert_left(root, 54);
	if (new_node)
	{
		printf("\nArbre après Insertion de 54 (Gauche, remplaçant 12):\n");
		binary_tree_print(root);
		/* Attendu: root->left est 54, et 54->left est 12 */

		/* Vérification des liens */
		if (root->left->n == 54 && root->left->left->n == 12 && root->left->left->parent == root->left)
		{
			printf("\nVerification OK: Le nœud 12 a été déplacé correctement sous 54.\n");
		}
		else
		{
			printf("\nVerification ÉCHOUÉE: Les liens ne sont pas corrects.\n");
		}
	}

	/*
	 * Remarque: Il faudrait ici une fonction pour libérer correctement l'arbre.
	 */
	return (0);
}
