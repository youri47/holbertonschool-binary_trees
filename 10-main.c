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
	size_t depth;

	/* Création d'un arbre binaire pour les tests */
	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	root->left->left = binary_tree_node(root->left, 6);
	root->left->right = binary_tree_node(root->left, 56);
	root->right->left = binary_tree_node(root->right, 256);
	root->right->right = binary_tree_node(root->right, 512);
	root->left->left->left = binary_tree_node(root->left->left, 3);

	printf("Structure de l'arbre:\n");
	printf("         98 (racine)\n");
	printf("        /  \\\n");
	printf("      12    402\n");
	printf("     / \\    / \\\n");
	printf("    6  56 256 512\n");
	printf("   /\n");
	printf("  3\n\n");

	/* Test 1: Profondeur de la racine */
	depth = binary_tree_depth(root);
	printf("Profondeur de 98 (racine): %lu\n", depth);

	/* Test 2: Profondeur des enfants directs de la racine */
	depth = binary_tree_depth(root->left);
	printf("Profondeur de 12 (niveau 1): %lu\n", depth);

	depth = binary_tree_depth(root->right);
	printf("Profondeur de 402 (niveau 1): %lu\n", depth);

	/* Test 3: Profondeur au niveau 2 */
	depth = binary_tree_depth(root->left->left);
	printf("Profondeur de 6 (niveau 2): %lu\n", depth);

	depth = binary_tree_depth(root->left->right);
	printf("Profondeur de 56 (niveau 2): %lu\n", depth);

	depth = binary_tree_depth(root->right->left);
	printf("Profondeur de 256 (niveau 2): %lu\n", depth);

	depth = binary_tree_depth(root->right->right);
	printf("Profondeur de 512 (niveau 2): %lu\n", depth);

	/* Test 4: Profondeur au niveau 3 */
	depth = binary_tree_depth(root->left->left->left);
	printf("Profondeur de 3 (niveau 3): %lu\n", depth);

	/* Test 5: Nœud NULL */
	depth = binary_tree_depth(NULL);
	printf("Profondeur de NULL: %lu\n", depth);

	return (0);
}
