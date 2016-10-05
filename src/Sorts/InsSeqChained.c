#include "../list.h"

#include <stdlib.h>

void ins_seqChained (List *list) {

	Node *currentNode = list->top->next;
	Node *currentSortedNode = list->top;
	Node *kNode;
	Node *tmpNode;

	TYPE tmp;

	Node* nodes[list->length(list)];

	size_t i;

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
