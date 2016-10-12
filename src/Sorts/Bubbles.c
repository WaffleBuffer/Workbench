#include "../Utils.c"

#include <stdlib.h>

/*
* Sort an int tab with bubbles algorithim.
* @param tab The table of int to sort.
* @param tabSize the size of tab.
* @author Thomas MEDARD
*/
void bubblesSort (TYPE tab[], const size_t tabSize) {

    int sorted = 0;
	TYPE tmp;
	size_t iteration = 1;
	while (!sorted) {
		sorted = 1;
		
		for (size_t i = 0; i < tabSize - iteration; ++i) {
			if (tab[i] > tab[i+1]) {
				sorted = 0;
				tmp = tab[i];
				tab[i] = tab[i+1];
				tab[i+1] = tmp;		
			}
		}
		++iteration;
	}
}
