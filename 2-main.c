#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Point d'entrée du test pour la fonction binary_tree_insert_right.
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

	/* 1. Insertion de l'enfant gauche pour complexifier la structure */
	binary_tree_insert_left(root, 12);
	printf("\nArbre après Insertion de 12 (Gauche):\n");
	binary_tree_print(root);

	/* 2. Insertion simple à droite (pas d'enfant existant) */
	binary_tree_insert_right(root, 402);
	printf("\nArbre après Insertion de 402 (Droite):\n");
	binary_tree_print(root);
	/* root->right est maintenant 402 */

	/* 3. Insertion avec enfant existant (le cas complexe) */
	/* On insère 500, qui prend la place de 402 */
	new_node = binary_tree_insert_right(root, 500);
	if (new_node)
	{
		printf("\nArbre après Insertion de 500 (Droite, remplaçant 402):\n");
		binary_tree_print(root);
		/* Attendu: root->right est 500, et 500->right est 402 */

		/* Vérification des liens */
		if (root->right->n == 500 && root->right->right->n == 402 && root->right->right->parent == root->right)
		{
			printf("\nVerification OK: Le nœud 402 a été déplacé correctement sous 500.\n");
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
