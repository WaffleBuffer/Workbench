#include <stdlib.h>
//int * tab = (int *) malloc (1 000 000 * sizeof(int));
//		(int*) calloc (1 000 000, sizeof(int));  = malloc + memset

void bubblesSort (int tab[], const size_t tabSize) {

    int sorted = 0;
	int tmp;
	int iteration = 1;
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

/*
int main () {
	TABLEAU tab;
	genereTab(10, tab);

	for (unsigned int i = 0; i < sizeof(tab) / sizeof(int); ++i) {
		printf("%d ", tab[i]);
	}
	printf("\n");

	bubblesSort (tab, 10);

	for (unsigned int i = 0; i < sizeof(tab) / sizeof(int); ++i) {
		printf("%d ", tab[i]);
	}
	printf("\n");

	return 0;
}*/
