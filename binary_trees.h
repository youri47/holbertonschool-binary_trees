#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Nœud d'arbre binaire
 * ...
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/* Prototypes de fonctions */
/* 0-binary_tree_node.c */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* 1-binary_tree_insert_left.c */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/* 2-binary_tree_insert_right.c <--- NOUVEAU PROTOTYPE REQUIS */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/* Utilitaires */
void binary_tree_print(const binary_tree_t *);

#endif /* _BINARY_TREES_H_ */
