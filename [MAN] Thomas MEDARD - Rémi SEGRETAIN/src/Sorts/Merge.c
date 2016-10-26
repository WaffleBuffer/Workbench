/**
 * \file Merge.c
 * \brief Sort algorithim using merge.
 * \author Thomas MEDARD, Remi SEGRETAIN
 */

#include "../Utils.c"

/**
 * \fn void mergeTab(TYPE tab[], const size_t left, const size_t middle, const size_t right)
 * \brief Merge two sorted arrays (which are in fact inside tab).
 * \param[in, out] tab The array containing all values. All values must be initialized.
 * \param[in] beginTab1 The beginning index of first tab. Must be valid.
 * \param[in] endTab1 The ending index of the first tab. Must be valid.
 * \param[in] endTab2 The ending index of the second tab. Must be valid.
 */
void mergeTab(TYPE tab[], const size_t left, const size_t middle, const size_t right) {
	TYPE* tmp = (TYPE*) malloc((right - left + 1)*sizeof(TYPE));
	size_t tabLeft = left;
	size_t tabRight = middle + 1;

	for ( size_t i = left; i <= right; ++i) {
		tmp[i - left] = tab[i];
	}

	for ( size_t i = left; i <= right; ++i) {

		if (tabLeft == middle +1) {
			break;
		}
		else if ( tabRight == right + 1 || tmp[tabLeft - left] <= tmp[tabRight - left] ) {
			tab[i] = tmp[tabLeft - left];
			++tabLeft;
		}
		else {
			tab[i] = tmp[tabRight - left];
			++tabRight;
		}
	}
	free(tmp);
}

/**
 * \fn void mergesort(TYPE tab[], size_t begin, size_t end)
 * \brief Main recursion : cut tab in half (with indexes) and then try to merge them when they are sorted.
 * \param[in, out] tab The array of Type to sort. All values from begin to end must be initialized.
 * \param[in] begin The begginning index of tab. Must be valid.
 * \param[in] end The ending index of tab. Must be valid.
 */
void mergesort(TYPE tab[], const size_t begin, const size_t end) {
    if(begin < end) {
		// Middle
        size_t mid = (begin + end) / 2;

		// Left recursion
        mergesort(tab, begin, mid);
		// Right recursion
        mergesort(tab, mid + 1 , end);

		// Merging of two sorted tables
        mergeTab(tab, begin , mid, end);
    }
}

/**
 * \fn void merge (TYPE tab[], size_t tabSize)
 * \brief Sort an array of TYPE with merge algorithim.
 * \param[in, out] tab The array of TYPE to sort. All tabSize values must be initialized.
 * \param[in] tabSize the size of tab.
 */
void merge (TYPE tab[], const size_t tabSize) {

	mergesort(tab, 0, tabSize - 1);
}
