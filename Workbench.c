#include <stdio.h> // printf
#include <stdlib.h>
#include <time.h> //clock_t
#include <string.h> // strcmp
#include <unistd.h> // sleep
#include <signal.h> //SIGALARM

#include "bor-util.h"

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

// Maximum time allowed to a test
#define TIME_BEFORE_STOP 300

// Maximum value for a random element
#defint MAX_RAND_VALUE

// All the sizes to test
const size_t sizesTab[15] = {SIZE1, SIZE2, SIZE3, SIZE4, SIZE5, SIZE6,
						SIZE7, SIZE8, SIZE9, SIZE10, SIZE11, SIZE12,
						SIZE13, SIZE14, MAX};
						
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


/**
* Initialize all values in tab of size size to a random number. tab must have been set to size size.
* @param tab The table to generate values into. Must have been set to size size.
* @param size the size of tab.
* @author Remi SEGRETAIN
*/
void initTabRand (int tab[], const size_t size) {
	srand(time(0));
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
	// Creating the table
	int tab[sizeToTest];
	// Generating  its values
	initTabRand(tab, sizeToTest);
	
	// Affecting SIGALRM handler
	bor_signal(SIGALRM, alarmHandler, 0);
	
	// Begin time mesure
	clock_t begin = clock();
	// Launching alarm
	alarm(TIME_BEFORE_STOP);
	// Calling the chosen algorithim
	algo(tab, sizeToTest);
	// End time mesure
	clock_t end = clock();
	
	// Calculating passed time
	double time = ((double) (end - begin) / CLOCKS_PER_SEC);
	
	printf("%lf\n", time);
}

/**
* Affect chooseAlgo and algo corresponding to the argument.
* @param arg The chosen algo. If it's invalid, will exit with error message.
* @author Thomas MEDARD
*/
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

/**
* The main
*/
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