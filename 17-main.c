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
	binary_tree_t *sibling;

	/* Création d'un arbre binaire pour les tests */
	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	root->left->left = binary_tree_node(root->left, 6);
	root->left->right = binary_tree_node(root->left, 56);
	root->right->left = binary_tree_node(root->right, 256);
	root->right->right = binary_tree_node(root->right, 512);

	printf("Structure de l'arbre:\n");
	printf("       98\n");
	printf("      /  \\\n");
	printf("    12    402\n");
	printf("   / \\    / \\\n");
	printf("  6  56 256 512\n\n");

	/* Test 1: Sibling de 12 */
	sibling = binary_tree_sibling(root->left);
	if (sibling)
		printf("Sibling de 12: %d\n", sibling->n);
	else
		printf("Sibling de 12: NULL\n");

	/* Test 2: Sibling de 402 */
	sibling = binary_tree_sibling(root->right);
	if (sibling)
		printf("Sibling de 402: %d\n", sibling->n);
	else
		printf("Sibling de 402: NULL\n");

	/* Test 3: Sibling de 6 */
	sibling = binary_tree_sibling(root->left->left);
	if (sibling)
		printf("Sibling de 6: %d\n", sibling->n);
	else
		printf("Sibling de 6: NULL\n");

	/* Test 4: Sibling de 56 */
	sibling = binary_tree_sibling(root->left->right);
	if (sibling)
		printf("Sibling de 56: %d\n", sibling->n);
	else
		printf("Sibling de 56: NULL\n");

	/* Test 5: Sibling de 256 */
	sibling = binary_tree_sibling(root->right->left);
	if (sibling)
		printf("Sibling de 256: %d\n", sibling->n);
	else
		printf("Sibling de 256: NULL\n");

	/* Test 6: Sibling de 512 */
	sibling = binary_tree_sibling(root->right->right);
	if (sibling)
		printf("Sibling de 512: %d\n", sibling->n);
	else
		printf("Sibling de 512: NULL\n");

	/* Test 7: Sibling de la racine (98) */
	sibling = binary_tree_sibling(root);
	if (sibling)
		printf("Sibling de 98 (racine): %d\n", sibling->n);
	else
		printf("Sibling de 98 (racine): NULL\n");

	/* Test 8: Nœud NULL */
	sibling = binary_tree_sibling(NULL);
	if (sibling)
		printf("Sibling de NULL: %d\n", sibling->n);
	else
		printf("Sibling de NULL: NULL\n");

	printf("\n--- Test avec nœud sans sibling ---\n\n");

	/* Créer un nouveau nœud sans sibling */
	free(root->left->right);
	root->left->right = NULL;

	printf("Structure de l'arbre modifié:\n");
	printf("       98\n");
	printf("      /  \\\n");
	printf("    12    402\n");
	printf("   /      / \\\n");
	printf("  6     256 512\n\n");

	/* Test 9: Nœud 6 n'a plus de sibling */
	sibling = binary_tree_sibling(root->left->left);
	if (sibling)
		printf("Sibling de 6: %d\n", sibling->n);
	else
		printf("Sibling de 6: NULL (pas de sibling)\n");

	return (0);
}
