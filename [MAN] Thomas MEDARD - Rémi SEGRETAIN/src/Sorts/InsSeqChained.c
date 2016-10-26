/**
 * \file InsSeqChained.c
 * \brief Sort algorithim using insertion/permutation for chained list.
 * \author Thomas MEDARD, Remi SEGRETAIN
 */

#include "../list.h"

#include <stdlib.h>

/**
 * \fn void ins_seqChained (List *list)
 * \brief Sort a chained list of TYPE using selection/permutation.
 * \param[in, out] list The chained list to sort. All values must be initialized.
 */
void ins_seqChained (List *list) {

	// Make sure that we can sort it
	if (list->top == NULL || list->top->next == NULL) {
		return;
	} 

	Node *currentNode = list->top->next;
	Node *currentSortedNode = list->top;
	Node *kNode;

	TYPE tmp;

	while (currentNode->next != NULL) {

		while (currentNode->value > currentSortedNode->value) {
			currentSortedNode = currentSortedNode->next;
		}

		tmp = currentNode->value;

		for (kNode = currentSortedNode; kNode != currentNode; kNode = kNode->next) {
			kNode->next->value = kNode->value;
		}

		currentSortedNode->value = tmp;

		currentNode = currentNode->next;
		currentSortedNode = list->top;
	}
}
