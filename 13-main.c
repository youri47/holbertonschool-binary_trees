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
	size_t nodes;

	/* Test 1: Arbre NULL */
	nodes = binary_tree_nodes(NULL);
	printf("Nombre de nœuds internes dans un arbre NULL: %lu\n\n", nodes);

	/* Test 2: Arbre avec un seul nœud (feuille) */
	root = binary_tree_node(NULL, 98);
	nodes = binary_tree_nodes(root);
	printf("Arbre avec un seul nœud (feuille):\n");
	printf("  98\n");
	printf("Nombre de nœuds internes: %lu\n\n", nodes);
	free(root);

	/* Test 3: Arbre avec 3 nœuds (1 nœud interne) */
	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	nodes = binary_tree_nodes(root);
	printf("Arbre avec 3 nœuds:\n");
	printf("    98 ← nœud interne\n");
	printf("   /  \\\n");
	printf("  12  402 ← feuilles\n");
	printf("Nombre de nœuds internes: %lu (seulement 98)\n\n", nodes);
	free(root->left);
	free(root->right);
	free(root);

	/* Test 4: Arbre complet avec 7 nœuds (3 nœuds internes) */
	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	root->left->left = binary_tree_node(root->left, 6);
	root->left->right = binary_tree_node(root->left, 56);
	root->right->left = binary_tree_node(root->right, 256);
	root->right->right = binary_tree_node(root->right, 512);

	nodes = binary_tree_nodes(root);
	printf("Arbre complet avec 7 nœuds:\n");
	printf("       98 ← nœud interne\n");
	printf("      /  \\\n");
	printf("    12    402 ← nœuds internes\n");
	printf("   / \\    / \\\n");
	printf("  6  56 256 512 ← feuilles\n");
	printf("Nombre de nœuds internes: %lu (98, 12, 402)\n\n", nodes);

	/* Test 5: Arbre déséquilibré (3 nœuds internes) */
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

	nodes = binary_tree_nodes(root);
	printf("Arbre déséquilibré:\n");
	printf("  98 ← nœud interne\n");
	printf(" /\n");
	printf("12 ← nœud interne\n");
	printf("/\n");
	printf("6 ← nœud interne\n");
	printf("/\n");
	printf("3 ← feuille\n");
	printf("Nombre de nœuds internes: %lu (98, 12, 6)\n\n", nodes);

	/* Test 6: Arbre avec un seul enfant */
	free(root->left->left->left);
	free(root->left->left);
	free(root->left);
	free(root);

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	root->left->right = binary_tree_node(root->left, 56);

	nodes = binary_tree_nodes(root);
	printf("Arbre avec configuration mixte:\n");
	printf("    98 ← nœud interne\n");
	printf("   /  \\\n");
	printf("  12  402 ← nœud interne et feuille\n");
	printf("    \\\n");
	printf("    56 ← feuille\n");
	printf("Nombre de nœuds internes: %lu (98 et 12)\n", nodes);

	return (0);
}
