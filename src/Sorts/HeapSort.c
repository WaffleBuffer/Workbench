#include "../Utils.c"

#include <stdlib.h>

typedef TYPE Heap[];

void addHeap(Heap heap, const size_t index, const TYPE value) {
	const size_t parent = (index - 1) / 2;
	heap[index] = value;
	
	if (index > 0 && value > heap[parent]) {
		heap[index] = heap[parent];
		addHeap(heap, parent, value);
	}
}

void createHeap(TYPE tab[], const size_t tabSize) {
	for (size_t i = 0; i < tabSize; ++i) {
		addHeap(tab, i, tab[i]);
	}
}

void deleteMaxHeapValue(Heap heap, size_t *heapSize) {
	size_t i, left, right, max;
	i = 0;
	left = 1;
	right = 2;
	
	// Putting the last value to the top
	TYPE tmp = heap[0];
	heap[0] = heap[*heapSize - 1];
	heap[(*heapSize) - 1] = tmp;
	
	--(*heapSize);
	
	while (left < (*heapSize)) {
		if (right < (*heapSize) && heap[left] < heap[right]) {
			max = right;
		}
		else {
			max = left;
		}
		
		if (heap[i] < heap[max]) {
			// Swap
			tmp = heap[i];
			heap[i] = heap[max];
			heap[max] = tmp;
		}
		else {
			break;
		}
		
		i = max;
		left = i * 2 + 1;
		right = left + 1;
	}
}

void heapSort(TYPE tab[], const size_t tabSize) {
	
	createHeap(tab, tabSize);
	size_t heapSize = tabSize;
	
	for (size_t i = tabSize; i > 1; --i) {
		deleteMaxHeapValue(tab, &heapSize);
	}
}
