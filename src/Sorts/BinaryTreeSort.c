/**
 * \file BinaryTreeSort.c
 * \brief Sort algorithim using binary sort tree.
 * \author Thomas MEDARD, Remi SEGRETAIN
 */

#include "../Utils.c"

#include <stdio.h>
#include <stdlib.h>

/**
 * \struct BTreeNode BinaryTreeSort.c
 * \brief A binary search tree node
 */
struct BTreeNode {

    struct BTreeNode *left;
    TYPE data ;
    struct BTreeNode *right;
};

/**
 * \brief The current index of the table to reinsert.
 */
size_t btIndex;

/**
 * \fn void insert (struct BTreeNode **node, TYPE value)
 * \brief Insert a value inside a bTreeNode.
 * \param[in, out] BTreeNode the node to insert the value after. Must be initialized.
 * \param[in] value The value to insert. Must be initialized.
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
}

/**
 * \fn inorder (const struct BTreeNode *node, TYPE tab[])
 * \brief Insert all the value of a BTreeNode inside an array.
 * \param[in] node The BTreeNode to get the values from.
 * \param[in, out] tab The array to put the values into. It's size must be equal to the number of values in node.
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
 * \fn freeTree (struct BTreeNode *node)
 * \brief free all nodes linked to node recursievely.
 * \param[in, out] node The BTreeNode to free.
 */
void freeTree (struct BTreeNode *node) {
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

/**
 * \fn bTreeSort(TYPE tab[], const size_t tabSize)
 * \brief Sort an array with a binary search tree.
 * \param[in, out] tab The array of TYPE to sort. All tabSize values must be initialized.
 * \param[in] tabSize The size of the array. Must be valid.
 */
void bTreeSort(TYPE tab[], const size_t tabSize) {

	struct BTreeNode *bTree = NULL;

	for (size_t i = 0; i < tabSize; ++i) {
		insert(&bTree, tab[i]);
	}

	btIndex = 0;
	inorder(bTree, tab);
    freeTree(bTree);
}
