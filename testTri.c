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
TABLEAU genereTab (const int size) {
	TABLEAU tab;
	srand(time(0));
	for (int i = 0; i < size; ++i) {
		tab[i] = (unsigned int) rand();
	}//for
	return tab;
}// genereTab

int main (int argc, char* argv[]) {
	
}
