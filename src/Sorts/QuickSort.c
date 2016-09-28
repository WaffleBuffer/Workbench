
void swap(int tab[], int x, int y) {
	int tmp = tab[x];
	tab[x] = tab[y];
	tab[y] = tmp;
}

void putPivot (int tab[], int left, int right, int *p) {
	*p = left;
	for (int i = left + 1; i <= right; ++i) {
		if (tab[i] < tab[left]) {
			swap(tab, i, ++*p);
		}
	}
	swap (tab, left, *p);
}

void quickSort (int tab[], int left, int right) {
	if (left < right) {
		int pivot;
		putPivot  (tab, left, right, &pivot);
		quickSort (tab, left, pivot - 1);
		quickSort (tab, pivot + 1, right);
	}
}

void quickSortMain (int tab[], const size_t tabSize) {
	quickSort( tab, 0, tabSize -1);
}
