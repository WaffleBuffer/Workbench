#include <stdio.h> // printf
#include <stdlib.h>
#include <time.h> //clock_t
#include <string.h> // strcmp
#include <unistd.h> // sleep
#include <signal.h> //SIGALARM

#include "bor-util.h"
#include "Sorts/Bubbles.c"

// Table sizes to test
#define SIZE1  100
#define SIZE2  500
#define SIZE3  50000
#define SIZE4  10000
#define SIZE5  50000
#define SIZE6  100000
#define SIZE7  200000
#define SIZE8  300000
#define SIZE9  400000
#define SIZE10 500000
#define SIZE11 600000
#define SIZE12 700000
#define SIZE13 800000
#define SIZE14 900000
#define MAX    1000000

// List of all available alorithims
#define BUBBLES        "Bubbles"
#define SEQUENTIAL_INS "SequentialInsertion"
#define DICHO_INS 	   "DichotomousInsertion"
#define SELEC_PERM     "SelectionPermutation"
#define FUSION 		   "Fusion"
#define QUICKSORT	   "QuickSort"
#define FIND_TREES     "FindTrees"
#define STACK 		   "Stack"

// Number of test per size
#define NB_TEST_PER_SIZE 20

// Maximum time allowed to a test
#define TIME_BEFORE_STOP 300

// Maximum value for a random element
#define MAX_RAND_VALUE 100

// All the sizes to test
const size_t sizesTab[15] = {SIZE1, SIZE2, SIZE3, SIZE4, SIZE5, SIZE6,
						SIZE7, SIZE8, SIZE9, SIZE10, SIZE11, SIZE12,
						SIZE13, SIZE14, MAX};

// All the available algorithims
const char* algos[8] = {BUBBLES, SEQUENTIAL_INS, DICHO_INS, SELEC_PERM, FUSION, QUICKSORT
						FIND_TREES, STACK};

// The name of the chosen algorithim
const char* chosenAlgo;
// The pointer to the chosen algorithim
void (*algo)(int tab[], const size_t tabSize);

//int * tab = (int *) malloc (1 000 000 * sizeof(int));
//		(int*) calloc (1 000 000, sizeof(int));  = malloc + memset


/**
* Initialize all values in tab of size size to a random number. tab must have been set to size size.
* @param tab The table to generate values into. Must have been set to size size.
* @param size the size of tab.
* @author Remi SEGRETAIN
*/
void initTabRand (int tab[], const size_t size) {
	for (size_t i = 0; i < size; ++i) {
		tab[i] = (unsigned int) rand() % MAX_RAND_VALUE;
	}//for
}// initTabRand

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
* Placeholder function to replace unfinished sorting algorithim.
* @param tab the table to test
* @param tabSize the size of tab
* @author Thomas MEDARD
*/
void testTime(int tab[], const size_t tabSize) {
	sleep(5);
}

/**
* Function called on SIGALRM (when a test is too long).
* @param sig the code of the signal (unused but needed).
* @author Thomas MEDARD
*/
void alarmHandler(int sig) {
	printf("Test too long\n");
	exit(0);
}

/**
* Function to lauch a test of sizeToTest size.
* @param sizeToTest The size of the table to test.
* @author Thomas MEDARD
*/
void launchTest(const size_t sizeToTest) {
	srand(time(0));
	// Creating the table
	int tab[sizeToTest];
	
	// Affecting SIGALRM handler
	bor_signal(SIGALRM, alarmHandler, 0);
	
	// All results
	double resultsSum = 0.0;
	
	// Testing NB_TEST_PER_SIZE times then getting the avergare result
	for (int i = 0; i < NB_TEST_PER_SIZE; ++i) {
		
		// Generating  its values
		initTabRand(tab, sizeToTest);
		
		// Begin time mesure
		clock_t begin = clock();
		// Launching alarm
		alarm(TIME_BEFORE_STOP);
		
		// Calling the chosen algorithim
		algo(tab, sizeToTest);
		
		// End time mesure
		clock_t end = clock();
		
		// Calculating passed time
		resultsSum += (end - begin) / CLOCKS_PER_SEC * 1000.0;
	}
	
	// TODO : find why this result is wrong
	const double finalRes = resultsSum / NB_TEST_PER_SIZE;
	
	// TODO : Create a csv file for the result
	printf("%fl ms\n", finalRes);
	
}

/**
* Affect chooseAlgo and algo corresponding to the argument.
* @param arg The chosen algo. If it's invalid, will exit with error message.
* @author Thomas MEDARD
*/
void chooseAlgo(char* arg) {
	if (strcmp(arg, BUBBLES) == 0) {
		chosenAlgo = BUBBLES;
		algo = bubblesSort;
	}
	else if (strcmp(arg, SEQUENTIAL_INS) == 0) {
		chosenAlgo = SEQUENTIAL_INS;
		algo = testTime;
	}
	else if (strcmp(arg, DICHO_INS) == 0) {
		chosenAlgo = DICHO_INS;
		algo = testTime;
	}
	else if (strcmp(arg, SELEC_PERM) == 0) {
		chosenAlgo = SELEC_PERM;
		algo = testTime;
	}
	else if (strcmp(arg, FUSION) == 0) {
		chosenAlgo = FUSION;
		algo = testTime;
	}
	else if (strcmp(arg, FIND_TREES) == 0) {
		chosenAlgo = FIND_TREES;
		algo = testTime;
	}
	else if (strcmp(arg, STACK) == 0) {
		chosenAlgo = STACK;
		algo = testTime;
	}
	else if (strcmp(arg, QUICKSORT) == 0) {
		chosenAlgo = QUICKSORT;
		algo = testTime;
	}
	else {
		displayArgsErr();
		exit(1);
	}
}

/**
* The main
*/
int main(int argc, char* argv[]) {
	
	if (argc < 2) {
		displayArgsErr();
		exit(1);
	}
	
	chooseAlgo(argv[1]);
	
	//TODO : create sons for all sizes
	launchTest(SIZE1);
	
	// TODO gather all csv files from results and create the final one (and removing the others)
	printf("Ended\n");
	
	return 0;
}