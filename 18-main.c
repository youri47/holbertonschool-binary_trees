#include "binary_trees.h"

/**
 * binary_tree_node - Crée un nouveau nœud d'arbre binaire
 * @parent: Pointeur vers le nœud parent
 * @value: Valeur à stocker dans le nouveau nœud
 *
 * Return: Pointeur vers le nouveau nœud, ou NULL en cas d'échec
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * main - Point d'entrée du programme de test
 *
 * Return: Toujours 0 (Succès)
 */
int main(void)
{
	binary_tree_t *root;
	binary_tree_t *uncle;

	/* Création d'un arbre binaire pour les tests */
	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	root->left->left = binary_tree_node(root->left, 6);
	root->left->right = binary_tree_node(root->left, 56);
	root->right->left = binary_tree_node(root->right, 256);
	root->right->right = binary_tree_node(root->right, 512);
	root->left->left->left = binary_tree_node(root->left->left, 3);
	root->left->left->right = binary_tree_node(root->left->left, 8);

	printf("Structure de l'arbre:\n");
	printf("         98 (grand-parent)\n");
	printf("        /  \\\n");
	printf("      12    402 (parents/oncles)\n");
	printf("     / \\    / \\\n");
	printf("    6  56 256 512\n");
	printf("   / \\\n");
	printf("  3  8\n\n");

	/* Test 1: Uncle de 6 */
	uncle = binary_tree_uncle(root->left->left);
	if (uncle)
		printf("Uncle de 6: %d\n", uncle->n);
	else
		printf("Uncle de 6: NULL\n");

	/* Test 2: Uncle de 56 */
	uncle = binary_tree_uncle(root->left->right);
	if (uncle)
		printf("Uncle de 56: %d\n", uncle->n);
	else
		printf("Uncle de 56: NULL\n");

	/* Test 3: Uncle de 256 */
	uncle = binary_tree_uncle(root->right->left);
	if (uncle)
		printf("Uncle de 256: %d\n", uncle->n);
	else
		printf("Uncle de 256: NULL\n");

	/* Test 4: Uncle de 512 */
	uncle = binary_tree_uncle(root->right->right);
	if (uncle)
		printf("Uncle de 512: %d\n", uncle->n);
	else
		printf("Uncle de 512: NULL\n");

	/* Test 5: Uncle de 3 (niveau 3) */
	uncle = binary_tree_uncle(root->left->left->left);
	if (uncle)
		printf("Uncle de 3: %d\n", uncle->n);
	else
		printf("Uncle de 3: NULL\n");

	/* Test 6: Uncle de 8 (niveau 3) */
	uncle = binary_tree_uncle(root->left->left->right);
	if (uncle)
		printf("Uncle de 8: %d\n", uncle->n);
	else
		printf("Uncle de 8: NULL\n");

	/* Test 7: Uncle de 12 (enfant de la racine) */
	uncle = binary_tree_uncle(root->left);
	if (uncle)
		printf("Uncle de 12: %d\n", uncle->n);
	else
		printf("Uncle de 12: NULL (parent est racine)\n");

	/* Test 8: Uncle de 402 (enfant de la racine) */
	uncle = binary_tree_uncle(root->right);
	if (uncle)
		printf("Uncle de 402: %d\n", uncle->n);
	else
		printf("Uncle de 402: NULL (parent est racine)\n");

	/* Test 9: Uncle de la racine */
	uncle = binary_tree_uncle(root);
	if (uncle)
		printf("Uncle de 98 (racine): %d\n", uncle->n);
	else
		printf("Uncle de 98 (racine): NULL (pas de parent)\n");

	/* Test 10: Nœud NULL */
	uncle = binary_tree_uncle(NULL);
	if (uncle)
		printf("Uncle de NULL: %d\n", uncle->n);
	else
		printf("Uncle de NULL: NULL\n");

	printf("\n--- Test avec nœud sans oncle ---\n\n");

	/* Modifier l'arbre pour avoir un nœud sans oncle */
	free(root->right->left);
	free(root->right->right);
	free(root->right);
	root->right = NULL;

	printf("Structure de l'arbre modifié:\n");
	printf("         98\n");
	printf("        /\n");
	printf("      12 (parent sans sibling)\n");
	printf("     / \\\n");
	printf("    6  56\n");
	printf("   / \\\n");
	printf("  3  8\n\n");

	/* Test 11: Uncle de 6 (parent n'a pas de sibling) */
	uncle = binary_tree_uncle(root->left->left);
	if (uncle)
		printf("Uncle de 6: %d\n", uncle->n);
	else
		printf("Uncle de 6: NULL (parent n'a pas de sibling)\n");

	return (0);
}
