#include "binary_trees.h"

/**
 * print_num - Affiche un nombre
 * @n: Le nombre à afficher
 *
 * Return: Rien
 */
void print_num(int n)
{
	printf("%d\n", n);
}

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

	printf("Parcours post-ordre (LEFT-RIGHT-ROOT):\n");
	binary_tree_postorder(root, &print_num);

	return (0);
}
