#include "../Utils.c"

#include <stdlib.h>
/*
* Sort an int tab with selection/permutation algorithim.
* @param tab The table of int to sort.
* @param tabSize the size of tab.
* @author Thomas MEDARD
*/
void selecPerm (TYPE tab[], const size_t tabSize) {
	size_t i, j, min;
    TYPE save;

	for (i = 0; i < tabSize - 1; ++i) {
		j = i + 1;
		min = i;

		for (j = i + 1; j < tabSize; ++j) {
			if (tab[j] < tab[min]) {
				min = j;
			}
		}

		save = tab[i];
		tab[i] = tab[min];
		tab[min] = save;
	}
}
