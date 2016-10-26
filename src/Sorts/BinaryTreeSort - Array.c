/**
 * \file BinaryTreeSort - Array.c
 * \brief Sort algorithim using binary sort tree without chained list.
          WARNING : this algorithm is not fully implemented (and probably never will) because
          as we need to rebalance the Binary Tree to not go out of array's bounds, this leads to 
          an AVL which is hard to implements (whatever says M. SEQUEIRA). Since it is not asked, the 
          time taken to implement it is not worth the reward especially without objects and pointers
          (which is the point of doing this compared to the other binaryTreeSort with a struct).
 * \author Thomas MEDARD, Remi SEGRETAIN
 */

#include "../Utils.c"

#include <stdio.h>
#include <stdlib.h>

// The current size of the binary tree as array
size_t bTreeSize;

/**
 * \fn int getHeight(const size_t index)
 * \brief Get the height of a certain index. 
    The height corresponds to the number of nodes to its farest leaf.
 * \param[in] index The index of tab to get the height from. Must be a valid index of tab.
 * \return The height of index.
 */
int getHeight(const size_t index) {

    size_t i;
    int height = 0;
    for (i = index; i < bTreeSize; i *= 2 + 1) {
        ++height;
    }
    return height;
}

/**
 * \fn void isBalanced(const size_t index)
 * \brief Check if an index is balanced in a binary tree.
 *        A node is balanced if the difference between all its child is not more than 1.
 * \param[in] index The index to check "balanceness". Must be a valid index of tab.
 * \return 1 if balanced, 0 otherwise.
 */
int isBalanced(const size_t index) {
    size_t left = index * 2 + 1;
    int leftHeight = 0;

    if (left < bTreeSize) {
        leftHeight = getHeight(left);
    }

    int rightHeight = 0;
    if (left + 1 < bTreeSize) {
        rightHeight = getHeight(left + 1);
    }

    return (leftHeight - rightHeight < 1 && leftHeight - rightHeight > -1);
}

/**
 * \fn ssize_t findFirstUnbalanced(const ssize_t index, const TYPE tab[])
 * \brief Find the first index of the binary tree which unbalanced if it exists.
 * \param[in] index The current index of tab tested. Must be valid if it's > 0.
 * \return The first unbalanced index or -1 if everything is balanced.
 */
ssize_t findFirstUnbalanced(const ssize_t index) {
    if (index < 0) {
        return -1;
    }
    else if (!isBalanced(index)) {
        return index;
    }
    else {
        return findFirstUnbalanced(index / 2 - 1);
    }
}

/**
 * \fn void balanceBTree(const size_t index, TYPE tab[])
 * \brief Balance a binary tree if needed.
 * \param[in] index The index of tab from which we should balance the tree. 
                    This is likely to be the index of the inserted value.
 * \param[in] tab The array of TYPE. Must contains at least index values.
 * \bug Unfinished function.
 */ 
void balanceBTree(const size_t index, TYPE tab[]) {
    ssize_t indexUnbalanced = findFirstUnbalanced(index, tab);

    if (indexUnbalanced < 0) {
        return;
    }
    // TODO : finish the function with all 4 cases
}

/**
 * \fn void insert_array (const size_t index, const TYPE value, TYPE tab[])
 * \brief Insert a value inside a binary tree array.
 * \param[in] value The value to insert. Must be initialized.
 * \param[in, out] tab The array of TYPE to insert into. 
                       Must be initialized and have engouh space to grant the new value to be inserted.
 * \bug Unfinished function.
 */
void insert_array (const TYPE value, TYPE tab[]) {

    printf("index : %zu\n", index);
    size_t index = 0;
    size_t left = index * 2 + 1;

    if (left > bTreeSize) {
        tab[index] = value;
        ++bTreeSize;
        return;
    }

    printf("left : %zu\n", left);

    if(value < tab[index])
        insert_array(left, value, tab) ;
    else
        insert_array(left + 1, value, tab);
}

/**
 * \fn bTreeSort_array(TYPE tab[], const size_t tabSize)
 * \brief Sort an array with a binary search tree without struct so with AVL.
 * \param[in, out] tab The array of TYPE to sort. All tabSize values must be initialized.
 * \param[in] tabSize The size of the array. Must be valid.
 * \bug Unfinished
 */
void bTreeSort_array(TYPE tab[], const size_t tabSize) {

    bTreeSize = 0;

	for (size_t i = 0; i < tabSize / 2; ++i) {
		insert_array(i, tab[i], tab);
	}
}
