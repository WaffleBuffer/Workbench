/**
 * \file Bubbles.c
 * \brief Sort algorithim using bubbles.
 * \author Thomas MEDARD, Remi SEGRETAIN
 */

#include "../Utils.c"

#include <stdlib.h>

/**
 * \fn void bubblesSort (TYPE tab[], const size_t tabSize)
 * \brief Sort an int tab with bubbles algorithim.
 * \param[in, out] tab The table of TYPE to sort. All tabSize values must be initialized.
 * \param[in] tabSize The size of tab.
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
