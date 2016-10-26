/**
 * \file InsSeq.c
 * \brief Sort algorithim using insertion/permutation.
 * \author Thomas MEDARD, Remi SEGRETAIN
 */

#include "../Utils.c"

#include <stdlib.h>

/**
 * \fn void ins_seq (TYPE tab[], const size_t size)
 * \brief Sort an array using selection/permutation.
 * \param[in, out] tab The array of Type to sort. All size values must initialized.
 * \param[in] size The size of tab. Must be valid.
 */
void ins_seq (TYPE tab[], const size_t size) {
	size_t i, j, k;
	TYPE tmp;

	j = 0;
	for (i = 1; i < size; ++i) {
		while ( tab[i] > tab[j]) 
			++j;

		tmp = tab[i];

		for (k = i; k > j; --k)
			tab[k] = tab[k -1 ];

		tab[j] = tmp;

		j = 0;
	}
}
