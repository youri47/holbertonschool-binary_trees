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
	int ret;

	/* Création d'un arbre binaire pour les tests */
	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	root->left->left = binary_tree_node(root->left, 6);
	root->left->right = binary_tree_node(root->left, 56);
	root->right->left = binary_tree_node(root->right, 256);
	root->right->right = binary_tree_node(root->right, 512);

	printf("Structure de l'arbre:\n");
	printf("       98 (parent=NULL)\n");
	printf("      /  \\\n");
	printf("    12    402 (parent=98)\n");
	printf("   / \\    / \\\n");
	printf("  6  56 256 512 (parent=12 ou 402)\n\n");

	/* Test sur la racine */
	ret = binary_tree_is_root(root);
	printf("Nœud 98 (racine) est une racine: %d\n", ret);

	/* Test sur des nœuds internes */
	ret = binary_tree_is_root(root->left);
	printf("Nœud 12 (enfant de 98) est une racine: %d\n", ret);

	ret = binary_tree_is_root(root->right);
	printf("Nœud 402 (enfant de 98) est une racine: %d\n", ret);

	/* Test sur des feuilles */
	ret = binary_tree_is_root(root->left->left);
	printf("Nœud 6 (feuille) est une racine: %d\n", ret);

	ret = binary_tree_is_root(root->left->right);
	printf("Nœud 56 (feuille) est une racine: %d\n", ret);

	ret = binary_tree_is_root(root->right->left);
	printf("Nœud 256 (feuille) est une racine: %d\n", ret);

	ret = binary_tree_is_root(root->right->right);
	printf("Nœud 512 (feuille) est une racine: %d\n", ret);

	/* Test avec NULL */
	ret = binary_tree_is_root(NULL);
	printf("NULL est une racine: %d\n", ret);

	return (0);
}
