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
	
	while (currentNode->next) {
		
		while (currentNode->value > currentSortedNode->value && currentSortedNode != currentNode->next) {
			currentSortedNode = currentSortedNode->next;
		}
		
		tmp = currentNode->value;
		
		i = 0;
		// Get all node from currentSortedNode to kNode
		for (tmpNode = currentSortedNode; tmpNode != currentNode; tmpNode = tmpNode->next) {
			nodes[i++] = tmpNode;
		}	
		// To get the last index
		--i;
		
		for (kNode = currentNode; kNode != currentSortedNode; kNode = nodes[i--]) {
			kNode->value = nodes[i - 1]->value;
		}
		
		currentSortedNode->value = tmp;		
		
		currentNode = currentNode->next;
		currentSortedNode = list->top;
	}
}
