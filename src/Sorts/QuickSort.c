/**
 * \file QuickSort.c
 * \brief Sort algorithim using QuickSort.
 * \author Thomas MEDARD, Remi SEGRETAIN
 */

#include "../Utils.c"

#include <stdlib.h>

#ifndef QUICKSORT__c
#define QUICKSORT__c

/**
 * \fn void swap(TYPE tab[], size_t x, size_t y)
 * \brief Swap two value in an array of TYPE.
 * \param[in, out] tab The array to swap into. Must be initialized and contains valids values of index x and y.
 * \param[in] x The index of the first value. Must be a valid index of tab.
 * \param[in] y The index of the second value. Must be a valide index of tab.
 */
void swap(TYPE tab[], const size_t x, const size_t y) {
	TYPE tmp = tab[x];
	tab[x] = tab[y];
	tab[y] = tmp;
}

/**
 * \fn void putPivot (TYPE tab[], const size_t left, const size_t right, size_t *pivot)
 * \brief Place the pivot at the right place in the provided array 
 * 		  so that all values on the "left" are below to the pivot and all values on the "right" are above.
 * \param[in, out] tab The array to modify. All values from left to right must be initialized.
 * \param[in] left The current minimum index of tab. Must be a valid index of tab
 * \param[in] right The current maximum index of tab. Must be a valide index of tab.
 * \param[in] pivot A pointer to the current index of the pivot. Must point to a valid index of tab.
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
 * \fn void quickSort (TYPE tab[], const size_t left, const size_t right)
 * \brief Sort an array with the quicksort algorithim.
 * \param[in, out] tab The array to sort. All values from left to right must be initialized.
 * \param[in] left The current minimum index of tab. Must be a valid index of tab
 * \param[in] right The current maximum index of tab. Must be a valide index of tab.
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
 * \fn void quickSortMain (TYPE tab[], const size_t tabSize)
 * \brief Function called by the test launcher. Exists because of the needed prototype for test functions.
 * 		  Will call quicksort so this will sort an array with quicksort alogrithim.
 * \param[in, out] tab The array to sort. All tabSize values must be initialized.
 * \param[in] tabSize the size of tab.
 */
void quickSortMain (TYPE tab[], const size_t tabSize) {
	quickSort( tab, 0, tabSize -1);
}

#endif /* QUICKSORT__c */