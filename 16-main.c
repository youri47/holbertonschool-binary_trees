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
	int perfect;

	/* Test 1: Arbre NULL */
	perfect = binary_tree_is_perfect(NULL);
	printf("Arbre NULL est parfait: %d\n\n", perfect);

	/* Test 2: Arbre avec un seul nœud (parfait) */
	root = binary_tree_node(NULL, 98);
	perfect = binary_tree_is_perfect(root);
	printf("Arbre avec un seul nœud:\n");
	printf("  98\n");
	printf("Est parfait: %d (OUI)\n\n", perfect);
	free(root);

	/* Test 3: Arbre parfait avec 3 nœuds */
	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	perfect = binary_tree_is_perfect(root);
	printf("Arbre parfait avec 3 nœuds:\n");
	printf("    98\n");
	printf("   /  \\\n");
	printf("  12  402\n");
	printf("Est parfait: %d (OUI - niveau 1 complet)\n\n", perfect);
	free(root->left);
	free(root->right);
	free(root);

	/* Test 4: Arbre parfait avec 7 nœuds */
	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	root->left->left = binary_tree_node(root->left, 6);
	root->left->right = binary_tree_node(root->left, 56);
	root->right->left = binary_tree_node(root->right, 256);
	root->right->right = binary_tree_node(root->right, 512);

	perfect = binary_tree_is_perfect(root);
	printf("Arbre parfait avec 7 nœuds:\n");
	printf("       98\n");
	printf("      /  \\\n");
	printf("    12    402\n");
	printf("   / \\    / \\\n");
	printf("  6  56 256 512\n");
	printf("Est parfait: %d (OUI - tous les niveaux remplis)\n\n", perfect);

	/* Test 5: Arbre NON parfait (manque un nœud) */
	free(root->left->right);
	root->left->right = NULL;
	perfect = binary_tree_is_perfect(root);
	printf("Arbre NON parfait (manque un nœud):\n");
	printf("       98\n");
	printf("      /  \\\n");
	printf("    12    402\n");
	printf("   /      / \\\n");
	printf("  6     256 512\n");
	printf("Est parfait: %d (NON - niveau incomplet)\n\n", perfect);

	/* Test 6: Arbre NON parfait (hauteurs différentes) */
	free(root->left->left);
	free(root->right->left);
	free(root->right->right);
	free(root->left);
	free(root->right);
	free(root);

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	root->left->left = binary_tree_node(root->left, 6);
	perfect = binary_tree_is_perfect(root);
	printf("Arbre NON parfait (hauteurs différentes):\n");
	printf("    98\n");
	printf("   /  \\\n");
	printf("  12  402\n");
	printf(" /\n");
	printf("6\n");
	printf("Est parfait: %d (NON - sous-arbres de hauteurs différentes)\n\n",
	       perfect);

	/* Test 7: Arbre parfait avec 15 nœuds */
	free(root->left->left);
	free(root->left);
	free(root->right);
	free(root);

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	root->left->left = binary_tree_node(root->left, 6);
	root->left->right = binary_tree_node(root->left, 56);
	root->right->left = binary_tree_node(root->right, 256);
	root->right->right = binary_tree_node(root->right, 512);
	root->left->left->left = binary_tree_node(root->left->left, 2);
	root->left->left->right = binary_tree_node(root->left->left, 8);
	root->left->right->left = binary_tree_node(root->left->right, 45);
	root->left->right->right = binary_tree_node(root->left->right, 67);
	root->right->left->left = binary_tree_node(root->right->left, 200);
	root->right->left->right = binary_tree_node(root->right->left, 300);
	root->right->right->left = binary_tree_node(root->right->right, 450);
	root->right->right->right = binary_tree_node(root->right->right, 600);

	perfect = binary_tree_is_perfect(root);
	printf("Arbre parfait avec 15 nœuds (4 niveaux):\n");
	printf("                98\n");
	printf("        /               \\\n");
	printf("      12                402\n");
	printf("    /    \\            /    \\\n");
	printf("   6     56         256    512\n");
	printf("  / \\    / \\        / \\    / \\\n");
	printf(" 2  8  45 67     200 300 450 600\n");
	printf("Est parfait: %d (OUI)\n", perfect);

	return (0);
}
