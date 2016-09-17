#include <stdio.h> // printf
#include <stdlib.h>
#include <time.h>
#include <string.h> // strcmp

// Table sizes to test
#define size1  100
#define size2  500
#define size3  50000
#define size4  10000
#define size5  50000
#define size6  100000
#define size7  200000
#define size8  300000
#define size9  400000
#define size10 500000
#define size11 600000
#define size12 700000
#define size13 800000
#define size14 900000
#define MAX    1000000

typedef int TABLEAU[MAX];

// All the sizes to test
const size_t sizesTab[15] = {size1, size2, size3, size4, size5, size6,
						size7, size8, size9, size10, size11, size12,
						size13, size14, MAX};
						
// List of all available alorithims
const char* bubbles 	  = "Bubbles";
const char* sequentialIns = "SequentialInsertion";
const char* dichoIns 	  = "DichotomousInsertion";
const char* selecPerm     = "SelectionPermutation";
const char* fusion 		  = "Fusion";
const char* quickSort	  = "QuickSort";
const char* findTrees     = "FindTrees";
const char* stack 		  = "Stack";

// All the available algorithims
const char* algos[8];

// The chosen algorithim
const char* chosenAlgo;

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

/**
* Displays an error message about arguments
* @author Thomas MEDARD
*/
void displayArgsErr(void) {
	fprintf(stderr, "Need to precise a valid algorithim.\nValids algorithims are :\n");
	
	for (size_t i = 0; i < sizeof(algos) / sizeof(algos[0]); ++i) {
		fprintf(stderr, "%s, ", algos[i]);
	}
	fprintf(stderr, "\n");
}

/**
* Initialize algos variable with all valids algorithims' names.
* @author Thomas MEDARD
*/
void initAlgos(void) {
	algos[0] = bubbles;
	algos[1] = sequentialIns;
	algos[2] = dichoIns;
	algos[3] = selecPerm;
	algos[4] = fusion;
	algos[5] = quickSort;
	algos[6] = findTrees;
	algos[7] = stack;
}

int main(int argc, char* argv[]) {
	initAlgos();
	
	if (argc < 2) {
		displayArgsErr();
		exit(1);
	}
	
	for (size_t i = 0; i < sizeof(algos) / sizeof(algos[0]); ++i) {
		if (strcmp(algos[i], argv[1]) == 0) {
			chosenAlgo = argv[1];
			break;
		}
	}
	
	if (chosenAlgo == NULL) {
		displayArgsErr();
		exit(1);
	}
	
	printf("%s\n", chosenAlgo);
	
	return 0;
}