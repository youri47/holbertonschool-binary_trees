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
	int balance;

	/* Test 1: Arbre NULL */
	balance = binary_tree_balance(NULL);
	printf("Balance factor d'un arbre NULL: %d\n\n", balance);

	/* Test 2: Arbre avec un seul nœud (équilibré) */
	root = binary_tree_node(NULL, 98);
	balance = binary_tree_balance(root);
	printf("Arbre avec un seul nœud:\n");
	printf("  98\n");
	printf("Balance factor: %d (équilibré)\n\n", balance);
	free(root);

	/* Test 3: Arbre équilibré */
	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	balance = binary_tree_balance(root);
	printf("Arbre équilibré:\n");
	printf("    98\n");
	printf("   /  \\\n");
	printf("  12  402\n");
	printf("Balance factor: %d (équilibré)\n\n", balance);
	free(root->left);
	free(root->right);
	free(root);

	/* Test 4: Arbre penché à gauche */
	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	root->left->left = binary_tree_node(root->left, 6);
	root->left->right = binary_tree_node(root->left, 56);
	balance = binary_tree_balance(root);
	printf("Arbre penché à gauche:\n");
	printf("       98\n");
	printf("      /  \\\n");
	printf("    12    402\n");
	printf("   / \\\n");
	printf("  6  56\n");
	printf("Balance factor: %d (penche à gauche)\n\n", balance);

	/* Test 5: Arbre penché à droite */
	free(root->left->left);
	free(root->left->right);
	free(root->left);
	root->right->left = binary_tree_node(root->right, 256);
	root->right->right = binary_tree_node(root->right, 512);
	balance = binary_tree_balance(root);
	printf("Arbre penché à droite:\n");
	printf("    98\n");
	printf("      \\\n");
	printf("      402\n");
	printf("     /  \\\n");
	printf("   256  512\n");
	printf("Balance factor: %d (penche à droite)\n\n", balance);

	/* Test 6: Arbre très déséquilibré (liste chaînée gauche) */
	free(root->right->left);
	free(root->right->right);
	free(root->right);
	free(root);

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->left->left = binary_tree_node(root->left, 6);
	root->left->left->left = binary_tree_node(root->left->left, 3);
	balance = binary_tree_balance(root);
	printf("Arbre très déséquilibré (gauche):\n");
	printf("  98\n");
	printf(" /\n");
	printf("12\n");
	printf("/\n");
	printf("6\n");
	printf("/\n");
	printf("3\n");
	printf("Balance factor: %d (très déséquilibré à gauche)\n\n", balance);

	/* Test 7: Arbre très déséquilibré (liste chaînée droite) */
	free(root->left->left->left);
	free(root->left->left);
	free(root->left);
	free(root);

	root = binary_tree_node(NULL, 98);
	root->right = binary_tree_node(root, 402);
	root->right->right = binary_tree_node(root->right, 512);
	root->right->right->right = binary_tree_node(root->right->right, 1024);
	balance = binary_tree_balance(root);
	printf("Arbre très déséquilibré (droite):\n");
	printf("98\n");
	printf("  \\\n");
	printf("  402\n");
	printf("    \\\n");
	printf("    512\n");
	printf("      \\\n");
	printf("      1024\n");
	printf("Balance factor: %d (très déséquilibré à droite)\n", balance);

	return (0);
}
