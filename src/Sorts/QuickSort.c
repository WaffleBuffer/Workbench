#include "../Utils.c"

#include <stdlib.h>

#ifndef QUICKSORT__c
#define QUICKSORT__c

/**
 * Swap two value in an array.
 * @param tab The array to swap into. Must be initialized. and contains values of index x and y.
 * @param x The index of the first value. Must be a valid index of tab.
 * @param y The index of the second value. Must be a valide index of tab.
 * @author Thomas MEDARD, Remi SEGRETAIN
 */
void swap(TYPE tab[], size_t x, size_t y) {
	TYPE tmp = tab[x];
	tab[x] = tab[y];
	tab[y] = tmp;
}

/**
 * Place the pivot at the right place in the provided array 
 * so that all values on the "left" are below to the pivot and all values on the "right" are above.
 * @param tab The array tp make the modifications. Must be initialized.
 * @param left The current minimum index of tab. Must be a valid index of tab
 * @param right The current maximum index of tab. Must be a valide index of tab.
 * @param pivot A pointer to the current index of the pivot. Must point to a valid index of tab.
 * @author Thomas MEDARD, Remi SEGRETAIN
 */
void putPivot (TYPE tab[], const size_t left, const size_t right, size_t *pivot) {
	*pivot = left;

	for (size_t i = left + 1; i <= right; ++i) {
		if (tab[i] < tab[left]) {
			
			++(*pivot);
			swap(tab, i, *pivot);
		}
	}
	
	swap(tab, left, *pivot);
}

/**
 * Sort an array with the quicksort algorithim.
 * @param tab The array to sort. Must be initialized.
 * @param left The current minimum index of tab. Must be a valid index of tab
 * @param right The current maximum index of tab. Must be a valide index of tab.
 * @author Thomas MEDARD, Remi SEGRETAIN
 */
void quickSort (TYPE tab[], const size_t left, const size_t right) {
	if (left < right) {
		size_t pivot;
		putPivot  (tab, left, right, &pivot);
		if (pivot - left >= 1) {
			quickSort (tab, left, pivot - 1);
			quickSort (tab, pivot + 1, right);
		}
	}
}

/**
 * Function called by the test launcher. Exists because of the needed prototype.
 * Will call quicksort so this will sort an array with quicksort alogrithim.
 * @param tab The array to sort. Must be initialized.
 * @tabSize the size of tab.
 */
void quickSortMain (TYPE tab[], const size_t tabSize) {
	quickSort( tab, 0, tabSize -1);
}

#endif /* QUICKSORT__c */