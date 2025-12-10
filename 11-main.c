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
	size_t size;

	/* Test 1: Arbre NULL */
	size = binary_tree_size(NULL);
	printf("Taille d'un arbre NULL: %lu\n\n", size);

	/* Test 2: Arbre avec un seul nœud */
	root = binary_tree_node(NULL, 98);
	size = binary_tree_size(root);
	printf("Arbre avec un seul nœud:\n");
	printf("  98\n");
	printf("Taille: %lu\n\n", size);
	free(root);

	/* Test 3: Arbre avec 3 nœuds */
	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	size = binary_tree_size(root);
	printf("Arbre avec 3 nœuds:\n");
	printf("    98\n");
	printf("   /  \\\n");
	printf("  12  402\n");
	printf("Taille: %lu\n\n", size);
	free(root->left);
	free(root->right);
	free(root);

	/* Test 4: Arbre complet avec 7 nœuds */
	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	root->left->left = binary_tree_node(root->left, 6);
	root->left->right = binary_tree_node(root->left, 56);
	root->right->left = binary_tree_node(root->right, 256);
	root->right->right = binary_tree_node(root->right, 512);

	size = binary_tree_size(root);
	printf("Arbre complet avec 7 nœuds:\n");
	printf("       98\n");
	printf("      /  \\\n");
	printf("    12    402\n");
	printf("   / \\    / \\\n");
	printf("  6  56 256 512\n");
	printf("Taille: %lu\n\n", size);

	/* Test 5: Arbre déséquilibré */
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
	root->left->left->left->left = binary_tree_node(root->left->left->left, 1);

	size = binary_tree_size(root);
	printf("Arbre déséquilibré (5 nœuds):\n");
	printf("  98\n");
	printf(" /\n");
	printf("12\n");
	printf("/\n");
	printf("6\n");
	printf("/\n");
	printf("3\n");
	printf("/\n");
	printf("1\n");
	printf("Taille: %lu\n", size);

	return (0);
}
