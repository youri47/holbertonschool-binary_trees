#include "binary_trees.h"

/*
 * Note: Cette fonction est généralement fournie comme un utilitaire
 * pour visualiser l'arbre. Le code exact peut varier.
 * La version ci-dessous est un exemple standard pour l'affichage.
 */

/*
 * Fonctions utilitaires privées pour l'affichage
 */
static size_t height(const binary_tree_t *tree);
static void print_t(const binary_tree_t *tree, int offset, int depth, char **s);

/**
 * binary_tree_print - Affiche un arbre binaire de manière lisible.
 * @tree: Pointeur vers le nœud racine de l'arbre à afficher.
 *
 * Cette fonction est basée sur une implémentation standard
 * et n'est pas censée être modifiée.
 * Elle est ici pour la complétude du projet.
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t h;

	if (!tree)
		return;

	h = height(tree);
	s = malloc(sizeof(*s) * (h + 1));
	if (!s)
		return;

	for (h = 0; h < height(tree) + 1; h++)
	{
		s[h] = malloc(sizeof(**s) * 256);
		if (!s[h])
			return;
		/* Initialiser la ligne avec des espaces */
		s[h][0] = '\0';
	}

	/* Remplir le tableau de chaînes de caractères avec les données de l'arbre */
	print_t(tree, 0, 0, s);

	/* Afficher le tableau ligne par ligne */
	for (h = 0; h < height(tree) + 1; h++)
	{
		printf("%s\n", s[h]);
		free(s[h]);
	}

	free(s);
}

/**
 * height - Mesure la hauteur d'un arbre binaire.
 * @tree: Pointeur vers le nœud racine pour mesurer.
 *
 * Return: La hauteur de l'arbre, ou 0 si tree est NULL.
 */
static size_t height(const binary_tree_t *tree)
{
	size_t h_left = 0;
	size_t h_right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		h_left = 1 + height(tree->left);

	if (tree->right)
		h_right = 1 + height(tree->right);

	return (h_left > h_right ? h_left : h_right);
}

/**
 * print_t - Fonction récursive pour l'affichage de l'arbre.
 * @tree: Le nœud courant.
 * @offset: Décalage horizontal.
 * @depth: Profondeur verticale.
 * @s: Tableau de chaînes pour la représentation de l'arbre.
 */
static void print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int width;

	if (!tree)
		return;

	sprintf(b, "(%03d)", tree->n);
	width = 6; /* Longueur de "(xxx)" */

	/* Mettre à jour la ligne courante */
	sprintf(s[depth] + offset, "%s", b);

	/* Traiter l'enfant gauche */
	if (tree->left)
	{
		print_t(tree->left, offset, depth + 1, s);
	}

	/* Traiter l'enfant droit */
	if (tree->right)
	{
		print_t(tree->right, offset + width, depth + 1, s);
	}
}
