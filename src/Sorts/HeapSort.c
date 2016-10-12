#include "../Utils.c"

#include <stdlib.h>

// When we use Heap, we know we use a Heap like array
typedef TYPE Heap[];


/**
 * Add a value to a Heap.
 * @param heap the Heap to add he value into.
 * @param index The last index of heap. When called, index should be equal to the size of heap - 1.
 * @param value The value to insert.
 * @author Thomas MEDARD, Remi SEGRETAIN
 */
void addHeap(Heap heap, const size_t index, const TYPE value) {
	const size_t parent = (index - 1) / 2;
	heap[index] = value;
	
	if (index > 0 && value > heap[parent]) {
		heap[index] = heap[parent];
		addHeap(heap, parent, value);
	}
}

/**
 * Convert an array into a Heap like array.
 * @param tab The array to convert.
 * @param tabSize The size of tab.
 * @author Thomas MEDARD, Remi SEGRETAIN
 */
void createHeap(TYPE tab[], const size_t tabSize) {
	for (size_t i = 0; i < tabSize; ++i) {
		addHeap(tab, i, tab[i]);
	}
}

/**
 * Delete tha max value from a Heap and keep the Heap format.
 * @param heap The Heap to delete the max value from.
 * @param heapSize a pointer to the size of heap.
 * @author Thomas MEDARD, Remi SEGRETAIN
 */
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

/**
 * Sort an array using Heap format.
 * @param tab The array to sort.
 * @param tabSize The size of tab.
 * @author Thomas MEDARD, Remi SEGRETAIN
 */
void heapSort(TYPE tab[], const size_t tabSize) {
	
	createHeap(tab, tabSize);
	size_t heapSize = tabSize;
	
	for (size_t i = tabSize; i > 1; --i) {
		deleteMaxHeapValue(tab, &heapSize);
	}
}
