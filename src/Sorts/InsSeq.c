#include "../Utils.c"

#include <stdlib.h>

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
