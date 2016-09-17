#include <stdio.h> // printf
#include <stdlib.h>
#include <time.h> //clock_t
#include <string.h> // strcmp
#include <unistd.h> // sleep

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

// The name of the chosen algorithim
const char* chosenAlgo;
// The pointer to the chosen algorithim
void (*algo)(int tab[], const size_t tabSize);

//int * tab = (int *) malloc (1 000 000 * sizeof(int));
//		(int*) calloc (1 000 000, sizeof(int));  = malloc + memset


/*
@author : Remi SEGRETAIN
*/
void genereTab (int tab[], const size_t size) {
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

void testTime(int tab[], const size_t tabSize) {
	sleep(3);
}

void launchTest(const size_t sizeToTest) {
	int tab[sizeToTest];
	genereTab(tab, sizeToTest);
	
	clock_t begin = clock();
	algo(tab, sizeToTest);
	clock_t end = clock();
	
	double time = ((double) (end - begin) / CLOCKS_PER_SEC);
}

void chooseAlgo(char* arg) {
	if (strcmp(arg, bubbles) == 0) {
		chosenAlgo = bubbles;
		algo = testTime;
	}
	else if (strcmp(arg, sequentialIns) == 0) {
		chosenAlgo = sequentialIns;
		algo = testTime;
	}
	else if (strcmp(arg, dichoIns) == 0) {
		chosenAlgo = dichoIns;
		algo = testTime;
	}
	else if (strcmp(arg, selecPerm) == 0) {
		chosenAlgo = selecPerm;
		algo = testTime;
	}
	else if (strcmp(arg, fusion) == 0) {
		chosenAlgo = fusion;
		algo = testTime;
	}
	else if (strcmp(arg, findTrees) == 0) {
		chosenAlgo = findTrees;
		algo = testTime;
	}
	else if (strcmp(arg, stack) == 0) {
		chosenAlgo = stack;
		algo = testTime;
	}
	else if (strcmp(arg, quickSort) == 0) {
		chosenAlgo = quickSort;
		algo = testTime;
	}
	else {
		displayArgsErr();
		exit(1);
	}
}

int main(int argc, char* argv[]) {
	initAlgos();
	
	if (argc < 2) {
		displayArgsErr();
		exit(1);
	}
	
	chooseAlgo(argv[1]);
	
	launchTest(10);
	
	printf("Ended\n");
	
	return 0;
}