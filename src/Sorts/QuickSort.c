#include "../Utils.c"

#include <stdlib.h>

/*void swap(TYPE tab[], TYPE x, TYPE y) {
	TYPE tmp = tab[x];
	tab[x] = tab[y];
	tab[y] = tmp;
}*/

void putPivot (TYPE tab[], size_t left, size_t right, size_t *p) {
	*p = left;
	TYPE tmp;
	for (size_t i = left + 1; i <= right; ++i) {
		if (tab[i] < tab[left]) {
			
			tmp = tab[i];
			tab[i] = tab[++*p];
			tab[++*p] = tmp;
		}
	}
	
	tmp = tab[left];
	tab[left] = tab[*p];
	tab[*p] = tmp;
	//swap (tab, left, *p);
}

void quickSort (TYPE tab[], size_t left, size_t right) {
	if (left < right) {
		size_t pivot;
		putPivot  (tab, left, right, &pivot);
		quickSort (tab, left, pivot - 1);
		quickSort (tab, pivot + 1, right);
	}
}

void quickSortMain (TYPE tab[], const size_t tabSize) {
	quickSort( tab, 0, tabSize -1);
}
