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
 * print_tree - Affiche l'arbre de manière simple
 * @tree: Pointeur vers la racine
 * @level: Niveau actuel (pour l'indentation)
 */
void print_tree(const binary_tree_t *tree, int level)
{
	int i;

	if (tree == NULL)
		return;

	print_tree(tree->right, level + 1);

	for (i = 0; i < level; i++)
		printf("    ");
	printf("%d\n", tree->n);

	print_tree(tree->left, level + 1);
}

/**
 * main - Point d'entrée du programme de test
 *
 * Return: Toujours 0 (Succès)
 */
int main(void)
{
	binary_tree_t *root;
	binary_tree_t *node;

	printf("=== Test 1: Insertion sur un nœud sans enfant droit ===\n\n");

	/* Créer la racine */
	root = binary_tree_node(NULL, 98);
	printf("Arbre initial:\n");
	print_tree(root, 0);

	/* Insérer un enfant droit */
	printf("\nInsertion de 402 à droite de 98:\n");
	node = binary_tree_insert_right(root, 402);
	if (node)
		printf("Nœud créé avec valeur: %d\n", node->n);
	print_tree(root, 0);

	printf("\n=== Test 2: Insertion quand il y a déjà un enfant droit ===\n\n");

	/* Insérer un autre enfant droit (qui va pousser le précédent) */
	printf("Insertion de 128 à droite de 98 (402 existe déjà):\n");
	node = binary_tree_insert_right(root, 128);
	if (node)
	{
		printf("Nouveau nœud créé: %d\n", node->n);
		printf("L'ancien enfant droit (402) devient enfant de 128\n");
	}
	print_tree(root, 0);

	printf("\n=== Test 3: Insertion multiple ===\n\n");

	/* Insérer encore un enfant droit */
	printf("Insertion de 54 à droite de 98:\n");
	node = binary_tree_insert_right(root, 54);
	if (node)
		printf("Nouveau nœud créé: %d\n", node->n);
	print_tree(root, 0);

	printf("\n=== Test 4: Insertion à un niveau inférieur ===\n\n");

	/* Insérer un enfant droit au nœud 54 */
	printf("Insertion de 512 à droite de 54:\n");
	node = binary_tree_insert_right(root->right, 512);
	if (node)
		printf("Nouveau nœud créé: %d\n", node->n);
	print_tree(root, 0);

	printf("\n=== Test 5: Combinaison gauche et droite ===\n\n");

	/* Ajouter aussi des enfants à gauche */
	binary_tree_insert_left(root, 12);
	printf("Ajout de 12 à gauche de 98:\n");
	print_tree(root, 0);

	printf("\n=== Test 6: Insertion avec parent NULL ===\n\n");

	node = binary_tree_insert_right(NULL, 100);
	if (node == NULL)
		printf("Insertion avec parent NULL: retourne NULL ✓\n");
	else
		printf("ERREUR: devrait retourner NULL\n");

	printf("\n=== Arbre final ===\n\n");
	print_tree(root, 0);

	printf("\nStructure finale (visualisation):\n");
	printf("        98\n");
	printf("       /  \\\n");
	printf("      12  54\n");
	printf("           \\\n");
	printf("           512\n");
	printf("            \\\n");
	printf("            128\n");
	printf("             \\\n");
	printf("             402\n");

	return (0);
}
