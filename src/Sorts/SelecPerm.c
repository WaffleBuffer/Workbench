/**
 * \file SelecPerm.c
 * \brief Sort algorithim using selection/permutation.
 * \author Thomas MEDARD, Remi SEGRETAIN
 */

#include "../Utils.c"

#include <stdlib.h>

/**
 * \fn void selecPerm (TYPE tab[], const size_t tabSize)
 * \brief Sort an array of TYPE with selection/permutation algorithim.
 * \param[in, out] tab The array of TYPE to sort. All tabSize values must be initialized.
 * \param[in] tabSize the size of tab.
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
