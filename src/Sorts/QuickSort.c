#include "../Utils.c"

#include <stdlib.h>

/*void swap(TYPE tab[], TYPE x, TYPE y) {
	TYPE tmp = tab[x];
	tab[x] = tab[y];
	tab[y] = tmp;
}*/

void putPivot (TYPE tab[], const size_t left, const size_t right, size_t *p) {
	*p = left;
	TYPE tmp;
	
	//printf("left : %zu right : %zu\n", left, right);
	for (size_t i = left + 1; i <= right; ++i) {
		//printf("%zu : %zu\n", i, right);
		if (tab[i] < tab[left]) {
			
			
			++(*p);
			//printf("debug1.0\n");
			tmp = tab[i];
			//printf("debug1.1\n");
			tab[i] = tab[*p];
			//printf("debug1.2\n");
			tab[*p] = tmp;
			//printf("debug1.3\n");
		}
	}
	
	//printf("Après\n");
	tmp = tab[left];
	tab[left] = tab[*p];
	tab[*p] = tmp;
	
	//printf("fin\n");
	//swap (tab, left, *p);
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
