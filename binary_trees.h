#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h> /* Pour size_t et NULL */
#include <stdlib.h> /* Pour malloc et free */
#include <stdio.h>  /* Pour printf */

/* ... (Définition de la structure binary_tree_s) ... */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/*
 * Prototypes de fonctions pour les exercices
 */

/* 0-binary_tree_node.c */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* 1-binary_tree_insert_left.c */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value); /* <-- C'est la ligne manquante ! */

/* binary_tree_print.c (Prototype de la fonction d'affichage) */
void binary_tree_print(const binary_tree_t *);

#endif /* _BINARY_TREES_H_ */
