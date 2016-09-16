#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000
typedef int TABLEAU[MAX];

// Table sizes to test
const int size1 = 100;
const int size2 = 500;
const int size3 = 50000;
const int size4 = 10000;
const int size5 = 50000;
const int size6 = 100000;
const int size7 = 200000;
const int size8 = 300000;
const int size9 = 400000;
const int size10 = 500000;
const int size11 = 600000;
const int size12 = 700000;
const int size13 = 800000;
const int size14 = 900000;
const int size15 = 1000000;

// All the sizes to test
const int sizesTab[15] = {size1, size2, size3, size4, size5, size6
						size7, size8, size9, size10, size11, size12
						size13, size14, size15}

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