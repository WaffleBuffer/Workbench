#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000
typedef int TABLEAU[MAX];

//int * tab = (int *) malloc (1 000 000 * sizeof(int));
//		(int*) calloc (1 000 000, sizeof(int));  = malloc + memset


/*
@author : Remi SEGRETAIN
*/
void genereTab (TABLEAU tab, const size_t size) {
	srand(time(0));
	for (size_t i = 0; i < size; ++i) {
		tab[i] = (unsigned int) rand() % 50;
	}//for
}// genereTab