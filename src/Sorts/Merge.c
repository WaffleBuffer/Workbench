#include "../Utils.c"

/**
 * Merge two sorted tables (which are in fact inside tab).
 * @param tab The table containing all values.
 * @param beginTab1 The begginnin index of first tab.
 * @param endTab1 The ending index of the first tab.
 * @param endTab2 The ending index of the second tab.
 * @author Thomas MEDARD
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
}

/**
 * Main recursion : cut tab in half (with indexes) and then try to merge them when the are sorted.
 * @param begin The begginning index.
 * @param end The ending index.
 * @author Thomas MEDARD
 */
void mergesort(TYPE tab[], size_t begin, size_t end) {        
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
 * Sort an int table with merge algorithim.
 * @param tab The table of int to sort.
 * @param tabSize the size of tab.
 * @author Thomas MEDARD
 */
void merge (TYPE tab[], size_t tabSize) {
	
	mergesort(tab, 0, tabSize - 1);
}
