#include <stdlib.h>
/*
* Sort an int tab with dichotomous/insertion algorithim.
* @param tab The table of int to sort.
* @param tabSize the size of tab.
* @author Thomas MEDARD
*/
void dichoInser (int tab[], const size_t tabSize) {
	size_t i, j, left, right, middle;
	int save;

	for (i = 1; i < tabSize; ++i) {

        left = 0;
        right = i;

		while (left < right) {
            middle = (left + right) / 2;
            
            if (tab[i] <= tab[middle]) {
                right = middle;
            }
            else {
                left = middle + 1;
            }
        }

		save = tab[i];
        for (j = i; j > left; --j) {
            tab[j] = tab[j - 1];
        }
		tab[left] = save;
	}
}
