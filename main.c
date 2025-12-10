#include <stdio.h>
#include "binary_trees.h"

/*
 * Note : La structure binary_tree_t doit être définie dans binary_trees.h
 * La fonction binary_tree_node doit être définie dans 0-binary_tree_node.c
 */

/**
 * main - Point d'entrée pour le test de la fonction binary_tree_node
 *
 * Return: 0 en cas de succès, non-zéro en cas d'erreur
 */
int main(void)
{
    binary_tree_t *root;
    binary_tree_t *left_child;

    /* 1. Création du nœud Racine (parent = NULL) */
    root = binary_tree_node(NULL, 98);
    printf("Création de la Racine (98):\n");
    if (root)
    {
        printf("  Value: %d\n", root->n);
        printf("  Parent: %p (doit être NULL)\n", (void *)root->parent);
    }
    else
    {
        printf("Erreur lors de la création de la racine.\n");
        return (1);
    }

    /* 2. Création d'un enfant Gauche (parent = root) */
    left_child = binary_tree_node(root, 12);
    printf("\nCréation de l'enfant gauche (12) de la Racine:\n");
    if (left_child)
    {
        printf("  Value: %d\n", left_child->n);
        printf("  Parent: %p (doit être l'adresse de la Racine)\n", (void *)left_child->parent);

        /* Mettre à jour le pointeur left de la racine pour pointer vers ce nouvel enfant */
        root->left = left_child;
    }
    else
    {
        printf("Erreur lors de la création de l'enfant.\n");
        return (1);
    }

    /* 3. Vérification des liens de la Racine */
    printf("\nVérification des liens de la Racine:\n");
    printf("  Root->left (Value): %d\n", root->left->n);
    printf("  Root->right (Value): %p (doit être NULL)\n", (void *)root->right);

    /* (Optionnel) Libérer la mémoire après le test pour éviter les fuites */
    free(root->left); 
    free(root);
    
    return (0);
}
