#include "../Utils.c"

#include <stdlib.h>

#ifndef QUICKSORT__c
#define QUICKSORT__c

void swap(TYPE tab[], TYPE x, TYPE y) {
	TYPE tmp = tab[x];
	tab[x] = tab[y];
	tab[y] = tmp;
}

void putPivot (TYPE tab[], const size_t left, const size_t right, size_t *p) {
	*p = left;
		
	for (size_t i = left + 1; i <= right; ++i) {
		if (tab[i] < tab[left]) {
			
			++(*p);
			swap(tab, i, *p);
		}
	}
	
	swap(tab, left, *p);
}

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

void quickSortMain (TYPE tab[], const size_t tabSize) {
	quickSort( tab, 0, tabSize -1);
}

#endif /* QUICKSORT__c */