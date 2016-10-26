/**
 * \file DichoInser.c
 * \brief Sort algorithim using dichotomous/insertion.
 * \author Thomas MEDARD, Remi SEGRETAIN
 */

#include "../Utils.c"

#include <stdlib.h>

/**
 * \fn void dichoInser (TYPE tab[], const size_t tabSize)
 * \brief Sort an int tab with dichotomous/insertion algorithim.
 * \param[in, out] tab The array of TYPE to sort. All tabSize values must be initialized.
 * \param[in] tabSize the size of tab.
 */
void dichoInser (TYPE tab[], const size_t tabSize) {
	size_t i, j, left, right, middle;
	TYPE save;

	// Main loop
	for (i = 1; i < tabSize; ++i) {

        left = 0;
        right = i;

		// While we didn't find the right spot
		while (left < right) {
            middle = (left + right) / 2;
            
            if (tab[i] <= tab[middle]) {
                right = middle;
            }
            else {
                left = middle + 1;
            }
        }

		// Insert the value at the right spot
		save = tab[i];
        for (j = i; j > left; --j) {
            tab[j] = tab[j - 1];
        }
		tab[left] = save;
	}
}
