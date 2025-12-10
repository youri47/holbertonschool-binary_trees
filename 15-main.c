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
	int full;

	/* Test 1: Arbre NULL */
	full = binary_tree_is_full(NULL);
	printf("Arbre NULL est full: %d\n\n", full);

	/* Test 2: Arbre avec un seul nœud (full) */
	root = binary_tree_node(NULL, 98);
	full = binary_tree_is_full(root);
	printf("Arbre avec un seul nœud:\n");
	printf("  98\n");
	printf("Est full: %d (OUI - feuille seule)\n\n", full);
	free(root);

	/* Test 3: Arbre full avec 3 nœuds */
	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	full = binary_tree_is_full(root);
	printf("Arbre full avec 3 nœuds:\n");
	printf("    98 (2 enfants ✓)\n");
	printf("   /  \\\n");
	printf("  12  402 (0 enfant ✓)\n");
	printf("Est full: %d (OUI)\n\n", full);
	free(root->left);
	free(root->right);
	free(root);

	/* Test 4: Arbre full avec 7 nœuds */
	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	root->left->left = binary_tree_node(root->left, 6);
	root->left->right = binary_tree_node(root->left, 56);
	root->right->left = binary_tree_node(root->right, 256);
	root->right->right = binary_tree_node(root->right, 512);

	full = binary_tree_is_full(root);
	printf("Arbre full avec 7 nœuds:\n");
	printf("       98 (2 enfants ✓)\n");
	printf("      /  \\\n");
	printf("    12    402 (2 enfants ✓)\n");
	printf("   / \\    / \\\n");
	printf("  6  56 256 512 (0 enfant ✓)\n");
	printf("Est full: %d (OUI)\n\n", full);

	/* Test 5: Arbre NON full (1 seul enfant) */
	free(root->left->right);
	root->left->right = NULL;
	full = binary_tree_is_full(root);
	printf("Arbre NON full:\n");
	printf("       98\n");
	printf("      /  \\\n");
	printf("    12    402\n");
	printf("   /      / \\\n");
	printf("  6     256 512\n");
	printf("         ↑\n");
	printf("  12 a seulement 1 enfant ✗\n");
	printf("Est full: %d (NON)\n\n", full);

	/* Test 6: Arbre NON full (liste chaînée) */
	free(root->left->left);
	free(root->right->left);
	free(root->right->right);
	free(root->left);
	free(root->right);
	free(root);

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->left->left = binary_tree_node(root->left, 6);
	full = binary_tree_is_full(root);
	printf("Arbre NON full (liste chaînée):\n");
	printf("  98 (1 seul enfant ✗)\n");
	printf(" /\n");
	printf("12 (1 seul enfant ✗)\n");
	printf("/\n");
	printf("6 (0 enfant ✓)\n");
	printf("Est full: %d (NON)\n\n", full);

	/* Test 7: Arbre avec un seul enfant droit */
	free(root->left->left);
	free(root->left);
	root->left = NULL;
	root->right = binary_tree_node(root, 402);
	full = binary_tree_is_full(root);
	printf("Arbre avec un seul enfant droit:\n");
	printf("  98 (1 seul enfant ✗)\n");
	printf("    \\\n");
	printf("    402\n");
	printf("Est full: %d (NON)\n", full);

	return (0);
}
