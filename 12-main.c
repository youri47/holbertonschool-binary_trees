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
	size_t leaves;

	/* Test 1: Arbre NULL */
	leaves = binary_tree_leaves(NULL);
	printf("Nombre de feuilles dans un arbre NULL: %lu\n\n", leaves);

	/* Test 2: Arbre avec un seul nœud (c'est une feuille) */
	root = binary_tree_node(NULL, 98);
	leaves = binary_tree_leaves(root);
	printf("Arbre avec un seul nœud:\n");
	printf("  98\n");
	printf("Nombre de feuilles: %lu\n\n", leaves);
	free(root);

	/* Test 3: Arbre avec 3 nœuds (2 feuilles) */
	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	leaves = binary_tree_leaves(root);
	printf("Arbre avec 3 nœuds:\n");
	printf("    98\n");
	printf("   /  \\\n");
	printf("  12  402\n");
	printf("Nombre de feuilles: %lu (12 et 402)\n\n", leaves);
	free(root->left);
	free(root->right);
	free(root);

	/* Test 4: Arbre complet avec 7 nœuds (4 feuilles) */
	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	root->left->left = binary_tree_node(root->left, 6);
	root->left->right = binary_tree_node(root->left, 56);
	root->right->left = binary_tree_node(root->right, 256);
	root->right->right = binary_tree_node(root->right, 512);

	leaves = binary_tree_leaves(root);
	printf("Arbre complet avec 7 nœuds:\n");
	printf("       98\n");
	printf("      /  \\\n");
	printf("    12    402\n");
	printf("   / \\    / \\\n");
	printf("  6  56 256 512\n");
	printf("Nombre de feuilles: %lu (6, 56, 256, 512)\n\n", leaves);

	/* Test 5: Arbre déséquilibré (1 feuille) */
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

	leaves = binary_tree_leaves(root);
	printf("Arbre déséquilibré:\n");
	printf("  98\n");
	printf(" /\n");
	printf("12\n");
	printf("/\n");
	printf("6\n");
	printf("/\n");
	printf("3\n");
	printf("Nombre de feuilles: %lu (seulement 3)\n\n", leaves);

	/* Test 6: Arbre avec un seul enfant */
	free(root->left->left->left);
	free(root->left->left);
	free(root->left);
	free(root);

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	root->left->right = binary_tree_node(root->left, 56);

	leaves = binary_tree_leaves(root);
	printf("Arbre avec configuration mixte:\n");
	printf("    98\n");
	printf("   /  \\\n");
	printf("  12  402\n");
	printf("    \\\n");
	printf("    56\n");
	printf("Nombre de feuilles: %lu (56 et 402)\n", leaves);

	return (0);
}
