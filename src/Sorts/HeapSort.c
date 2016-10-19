/**
 * \file HeapSort.c
 * \brief Sort algorithim using Heap.
 * \author Thomas MEDARD, Remi SEGRETAIN
 */

#include "../Utils.c"

#include <stdlib.h>

/** 
 * \def Heap 
 * \briefWhen we use Heap, we know we use a Heap like array 
 */
typedef TYPE Heap[];


/**
 * \fn void addHeap(Heap heap, const size_t index, const TYPE value)
 * \brief Add a value to a Heap.
 * \param[in, out] heap the Heap to add he value into.
 * \param[in] index The last index of heap. When called outside recursivity, index should be equal to the size of heap - 1.
 * \param[in] value The value to insert.
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
 * \fn void createHeap(TYPE tab[], const size_t tabSize)
 * \brief Convert an array into a Heap like array.
 * \param[in, out] tab The array to convert.
 * \param[in] tabSize The size of tab.
 */
void createHeap(TYPE tab[], const size_t tabSize) {
	for (size_t i = 0; i < tabSize; ++i) {
		addHeap(tab, i, tab[i]);
	}
}

/**
 * \fn void deleteMaxHeapValue(Heap heap, size_t *heapSize)
 * \brief Delete tha max value from a Heap and keep the Heap format.
 * \param[in, out] heap The Heap to delete the max value from.
 * \param[in] heapSize a pointer to the size of heap.
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
 * \fn void heapSort(TYPE tab[], const size_t tabSize)
 * \brief Sort an array using Heap format.
 * \param[in, out] tab The array of TYPE to sort. All tabSize values must be initialized.
 * \param[in] tabSize The size of tab.
 */
void heapSort(TYPE tab[], const size_t tabSize) {
	
	createHeap(tab, tabSize);
	size_t heapSize = tabSize;
	
	for (size_t i = tabSize; i > 1; --i) {
		deleteMaxHeapValue(tab, &heapSize);
	}
}
