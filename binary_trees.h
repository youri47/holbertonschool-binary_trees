#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Structure d'un nœud d'arbre binaire
 * @n: Valeur entière stockée dans le nœud
 * @parent: Pointeur vers le nœud parent
 * @left: Pointeur vers l'enfant gauche
 * @right: Pointeur vers l'enfant droit
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/* Prototype de la fonction */
int binary_tree_is_leaf(const binary_tree_t *node);

/* Fonctions utilitaires pour les tests */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

#endif /* BINARY_TREES_H */
