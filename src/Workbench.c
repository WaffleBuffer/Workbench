#include "bor-util.h" // SIGALRM
#include "list.h" // List
#include "Utils.c" //TYPE

// All sorting algotithims
#include "Sorts/Bubbles.c"
#include "Sorts/InsSeq.c"
#include "Sorts/InsSeqChained.c"
#include "Sorts/SelecPerm.c"
#include "Sorts/DichoInser.c"
#include "Sorts/Merge.c"
#include "Sorts/QuickSort.c"
#include "Sorts/BinaryTreeSort.c"
#include "Sorts/HeapSort.c"

#include <stdio.h>  // printf
#include <stdlib.h> // itoa
#include <time.h>   // clock_t
#include <string.h> // strcmp
#include <unistd.h> // sleep
#include <string.h> // strcpy_s
#include <signal.h> //SA_RESTART

// Table sizes to test
#define SIZE1  10
#define SIZE2  500
#define SIZE3  5000
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
#define SEQUENTIAL_INS_CHAINED "SequentInsChained"
#define DICHO_INS 	   "DichotomousInsertion"
#define SELEC_PERM     "SelectionPermutation"
#define MERGE 		   "Merge"
#define QUICKSORT	   "QuickSort"
#define B_TREE         "BinaryTree"
#define HEAP 		   "HeapSort"

// Number of test per size
#define NB_TEST_PER_SIZE 20

// Number of test to do
#define NB_SIZE_TO_TEST 1

// Maximum time allowed for a size test (5 minutes)
#define TIME_BEFORE_STOP 10

// Maximum value for a random element
#define MAX_RAND_VALUE 100

// The csv separator used
#define CSV_SEPARATOR ';'

// The tested type. Declared in list.h

// All the sizes to test
const size_t sizesTab[NB_SIZE_TO_TEST] = {SIZE1, SIZE2, SIZE3, SIZE4, SIZE5, SIZE6,
						SIZE7, SIZE8, SIZE9, SIZE10, SIZE11, SIZE12,
						SIZE13, SIZE14, MAX};

// All the available algorithims
const char* algos[9] = {BUBBLES, SEQUENTIAL_INS, SEQUENTIAL_INS_CHAINED, DICHO_INS, SELEC_PERM,
						MERGE, QUICKSORT, B_TREE, HEAP};

// The name of the chosen algorithim
char* chosenAlgo;
// The pointer to the chosen algorithim
void (*algo)(TYPE tab[], const size_t tabSize);

// All the results
double results[15];
// The inedx of the current size
size_t currentSize;

/**
 * Initialize all values in tab of size size to a random number. tab must have been set to size size.
 * @param tab The table to generate values into. Must have been set to size size.
 * @param size the size of tab. Must be > 0.
 * @author Thomas MEDARD, Remi SEGRETAIN
 */
void initTabRand (TYPE tab[], const size_t size) {
	for (size_t i = 0; i < size; ++i) {
		tab[i] = (TYPE) rand() % MAX_RAND_VALUE;
	}//for
}// initTabRand

/**
 * Add list with size random number. list must have been initialized
 * @param tab The table to generate values into. Must have been initialized
 * @param size the number of value to add to list. Must be > 0.
 * @author Thomas MEDARD, Remi SEGRETAIN
 */
void initListRand(List *list, const size_t size) {

	for (size_t i = 0; i < size; ++i) {
		list->push(list, (unsigned int) rand() % MAX_RAND_VALUE);
	}
}

/**
 * Displays an error message about needed arguments
 * @author Thomas MEDARD, Remi SEGRETAIN
 */
void displayArgsErr(void) {
	fprintf(stderr, "Need to precise a valid algorithim.\nValids algorithims are :\n");

	for (size_t i = 0; i < 9; ++i) {
		fprintf(stderr, "%s, ", algos[i]);
	}
	fprintf(stderr, "\n");
}

/**
 * Placeholder function to replace unfinished sorting algorithim.
 * @param tab the table to test
 * @param tabSize the size of tab
 * @author Thomas MEDARD, Remi SEGRETAIN
 */
void testTime(TYPE tab[], const size_t tabSize) {
	(void) tab;
	(void) tabSize;
	sleep(1);
}

/**
 * Create (or replace) a csv file named fileName and write all elements of titleTab inside.
 * @param fileName The name of the file that should be created or replaced.
 * @param titleTab Elements writen in a line. Correspond to a line of titles. Must be initialized.
 * @param tableSize The size of titleTab. Must be > 0.
 * @return The file descriptor (of second level) of the csv file.
 * @author Thomas MEDARD, Remi SEGRETAIN
 */
FILE* createCSV(char* fileName, const size_t titlesTab[], size_t tableSize) {

	FILE* file = fopen(fileName, "w");

	if (file == NULL) {
		perror("fopen");
		exit(1);
	}

	for (size_t i = 0; i < tableSize; ++i) {
		fprintf(file, "%zu%c", titlesTab[i], CSV_SEPARATOR);
	}

	fprintf(file, "\n");
	fclose(file);

	return file;
}

/**
 * Write a line of element in a csv file (that must exists).
 * @param fileName the name of the file to write into. This file must exists.
 * @param tab The elements to write. Must be initilized.
 * @param tableSize the size of tab. Must be > 0.
 * @author Thomas MEDARD, Remi SEGRETAIN
 */
void writeLineCsv(const char* fileName, const double tab[], const size_t tableSize) {
	FILE* file = fopen(fileName, "a");

	if (file == NULL) {
		perror("fopen");
		exit(1);
	}

	for (size_t i = 0; i < tableSize; ++i) {
		fprintf(file, "%lf%c", tab[i], CSV_SEPARATOR);
	}

	fprintf(file, "\n");
	fclose(file);
}

/**
 * Create the csv report for the current tested test. The test must be over.
 * @author Thomas MEDARD, Remi SEGETAIN
 */
void creatReport(void) {

	char fileName[32];

	fileName[0] = '.';
	fileName[1] = '/';

	strcat(fileName, chosenAlgo);
	strcat(fileName, ".csv");

	createCSV(fileName, sizesTab, NB_SIZE_TO_TEST);
	writeLineCsv(fileName, results, currentSize);

	printf("Report %s created\n", fileName);
}

/**
 * Function called on SIGALRM (when a test is too long).
 * @param sig the code of the signal (unused).
 * @author Thomas MEDARD, Remi SEGRETAIN
 */
void alarmHandler(int sig) {
	// Suppress compiler warning about unused argument
	(void)sig;
	
	printf("Test too long on size %zu\n", sizesTab[currentSize]);

	creatReport();

	exit(0);
}

/**
* Function to lauch a test of sizeToTest size.
* @param sizeToTest The size of the table to test.
* @author Thomas MEDARD, Remi SEGRETAIN
*/
void launchTest(const size_t sizeToTest) {
	srand(time(0));
	// Creating the table
	TYPE tab[sizeToTest];

	// All results
	double resultsSum = 0.0;

    // Launching alarm
	alarm(TIME_BEFORE_STOP);

	// If we want a chained list
	int isList = 0;
	List *list;

	// If we want a chained list
	if (strcmp(chosenAlgo, SEQUENTIAL_INS_CHAINED) == 0) {
		isList = 1;
	}

	// Testing NB_TEST_PER_SIZE times then getting the average result
	for (size_t i = 0; i < NB_TEST_PER_SIZE; ++i) {

		// If we want a chained list
		if (isList == 1) {

			list = new_List();

			// Generating the list
			initListRand(list, sizeToTest);

			// Begin time mesure
			clock_t begin = clock();

			ins_seqChained(list);

			// End time mesure
			clock_t end = clock();

			list->free(list);

			// Calculating passed time
			resultsSum += ((double)end - (double)begin) / CLOCKS_PER_SEC * 1000.0;

			continue;
		} // End chained list test

		// Generating  its values
		initTabRand(tab, sizeToTest);
		
		for (size_t i = 0; i < sizeToTest; ++i) {
			printf("%d ", tab[i]);
		}
		printf("\n");
		
		// Begin time mesure
		clock_t begin = clock();

		// Calling the chosen algorithim
		algo(tab, sizeToTest);

		// End time mesure
		clock_t end = clock();
		
		for (size_t i = 0; i < sizeToTest; ++i) {
			printf("%d ", tab[i]);
		}
		printf("\n\n");

		// Calculating passed time
		resultsSum += ((double)end - (double)begin) / CLOCKS_PER_SEC * 1000.0;
	}

	const double finalRes = resultsSum / (double) NB_TEST_PER_SIZE;
	results[currentSize] = finalRes;

	printf("for size %zu : %lf ms\n", sizeToTest, finalRes);

}

/**
* Affect chooseAlgo and algo corresponding to the argument.
* @param arg The chosen algo. If it's invalid, will exit with error message.
* @author Thomas MEDARD, Remi SEGRETAIN
*/
void chooseAlgo(char* arg) {
	if (strcmp(arg, BUBBLES) == 0) {
		chosenAlgo = BUBBLES;
		algo = bubblesSort;
	}
	else if (strcmp(arg, SEQUENTIAL_INS) == 0) {
		chosenAlgo = SEQUENTIAL_INS;
		algo = ins_seq;
	}
	else if (strcmp(arg, SEQUENTIAL_INS_CHAINED) == 0) {
		// Specific case, so specific algo
		chosenAlgo = SEQUENTIAL_INS_CHAINED;
	}
	else if (strcmp(arg, DICHO_INS) == 0) {
		chosenAlgo = DICHO_INS;
		algo = dichoInser;
	}
	else if (strcmp(arg, SELEC_PERM) == 0) {
		chosenAlgo = SELEC_PERM;
		algo = selecPerm;
	}
	else if (strcmp(arg, MERGE) == 0) {
		chosenAlgo = MERGE;
		algo = merge;
	}
	else if (strcmp(arg, B_TREE) == 0) {
		chosenAlgo = B_TREE;
		algo = bTreeSort;
	}
	else if (strcmp(arg, HEAP) == 0) {
		chosenAlgo = HEAP;
		algo = heapSort;
	}
	else if (strcmp(arg, QUICKSORT) == 0) {
		chosenAlgo = QUICKSORT;
		algo = quickSortMain;
	}
	else {
		displayArgsErr();
		exit(1);
	}
}

/**
* The main : make all tests for one sorting algorithim
* @param argc The number of arguments. Must be > 1.
* @param argv The arguments. argv[1] must be initialized and a size_t (under string format).
* @author Thomas MEDARD, Rémi SEGRETAIN
*/
int main(int argc, char* argv[]) {

	// Checking arguments
	if (argc < 2) {
		displayArgsErr();
		exit(1);
	}

	// Affecting the right algorithim depending on the argument
	chooseAlgo(argv[1]);

	// Affecting SIGALRM handler
	bor_signal(SIGALRM, alarmHandler, SA_RESTART);

	// Launching tests per sizes
	for (currentSize = 0; currentSize < NB_SIZE_TO_TEST; ++currentSize) {
		launchTest(sizesTab[currentSize]);
	}

	creatReport();

	return 0;
}
