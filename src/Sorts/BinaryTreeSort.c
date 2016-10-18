#include "../Utils.c"

#include <stdio.h>
#include <stdlib.h>

/**
 * A binary search tree node
 * @author Thomas MEDARD, Remi SEGRETAIN
 */
struct BTreeNode {

    struct BTreeNode *left;
    TYPE data ;
    struct BTreeNode *right;
};

/**
 * The current index of the table to reinsert.
 */
size_t btIndex;

/**
 * Insert a value inside a bTreeNode.
 * @param BTreeNode the node to insert the value after. Must be initialized.
 * @param value The value to insert. Must be initialized.
 * @author Thomas MEDARD, Remi SEGRETAIN
 */
void insert (struct BTreeNode **node, TYPE value) {
    if (*node == NULL) {
        *node = malloc(sizeof(struct BTreeNode));

        (*node)->left = NULL ;
        (*node)->data = value ;
        (*node)->right = NULL ;
    }
    else {
        if(value < (*node)->data)
            insert(&((*node)->left), value) ;
        else
            insert (&((*node)->right), value) ;
    }
	free(*node);
}

/**
 * Insert all the value of a BTreeNode inside an array.
 * @param node The BTreeNode to get the values from.
 * @param tab The array to put the values into. It's size must be equal to the number of values in node.
 * @author Thomas MEDARD, Remi SEGRETAIN
 */
void inorder (const struct BTreeNode *node, TYPE tab[]){

    if (node != NULL){

        inorder(node->left, tab);
        tab[btIndex] = node->data;
        ++btIndex;
        inorder(node->right, tab);
    }
}

/**
 * Sort an array with a binary search tree.
 * @param tab The array to sort. Must be initialized.
 * @param tabSize The size of the array. Must be valid.
 * @author Thomas MEDARD, Remi SEGRETAIN
 */
void bTreeSort(TYPE tab[], const size_t tabSize) {

	struct BTreeNode *bTree = NULL;

	for (size_t i = 0; i < tabSize; ++i) {
		insert(&bTree, tab[i]);
	}

	btIndex = 0;
	inorder(bTree, tab);
}
