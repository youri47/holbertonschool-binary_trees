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
	size_t height;

	/* Test 1: Arbre NULL */
	height = binary_tree_height(NULL);
	printf("Hauteur d'un arbre NULL: %lu\n\n", height);

	/* Test 2: Arbre avec une seule feuille */
	root = binary_tree_node(NULL, 98);
	height = binary_tree_height(root);
	printf("Arbre avec une seule feuille:\n");
	printf("  98\n");
	printf("Hauteur: %lu\n\n", height);
	free(root);

	/* Test 3: Arbre complet avec 3 niveaux */
	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	root->left->left = binary_tree_node(root->left, 6);
	root->left->right = binary_tree_node(root->left, 56);
	root->right->left = binary_tree_node(root->right, 256);
	root->right->right = binary_tree_node(root->right, 512);

	height = binary_tree_height(root);
	printf("Arbre complet:\n");
	printf("       98\n");
	printf("      /  \\\n");
	printf("    12    402\n");
	printf("   / \\    / \\\n");
	printf("  6  56 256 512\n");
	printf("Hauteur: %lu\n\n", height);

	/* Test 4: Arbre déséquilibré (hauteur à gauche) */
	free(root->left->left);
	free(root->left->right);
	free(root->right->left);
	free(root->right->right);
	free(root->left);
	free(root->right);
	free(root);

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->left->left = binary_tree_node(root->left, 6);
	root->left->left->left = binary_tree_node(root->left->left, 3);

	height = binary_tree_height(root);
	printf("Arbre déséquilibré (gauche):\n");
	printf("    98\n");
	printf("   /\n");
	printf("  12\n");
	printf(" /\n");
	printf("6\n");
	printf("/\n");
	printf("3\n");
	printf("Hauteur: %lu\n\n", height);

	/* Test 5: Arbre avec un seul enfant droit */
	free(root->left->left->left);
	free(root->left->left);
	free(root->left);
	free(root);

	root = binary_tree_node(NULL, 98);
	root->right = binary_tree_node(root, 402);

	height = binary_tree_height(root);
	printf("Arbre avec un enfant droit:\n");
	printf("  98\n");
	printf("    \\\n");
	printf("    402\n");
	printf("Hauteur: %lu\n", height);

	return (0);
}
