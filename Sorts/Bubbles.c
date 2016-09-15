#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
typedef int TABLEAU[MAX];

//int * tab = (int *) malloc (1 000 000 * sizeof(int));
//		(int*) calloc (1 000 000, sizeof(int));  = malloc + memset


/*
@author : Remi SEGRETAIN
*/
void genereTab (const size_t size, TABLEAU tab) {
	srand(time(0));
	for (size_t i = 0; i < size; ++i) {
		tab[i] = (unsigned int) rand() % 50;
	}//for
	printf("%lu\n", sizeof(tab));
}// genereTab

void bubblesSort (TABLEAU tab, const size_t tabSize) {

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
}
