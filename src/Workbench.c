#include "list.h"

// All sorts algotithims
#include "Sorts/Bubbles.c"
#include "Sorts/SelecPerm.c"
#include "Sorts/DichoInser.c"
#include "Sorts/Merge.c"
#include "Sorts/QuickSort.c"

#include <stdio.h>  // printf
#include <stdlib.h> // itoa
#include <time.h>   // clock_t
#include <string.h> // strcmp
#include <unistd.h> // sleep
#include <string.h> // strcpy_s

// Table sizes to test
#define SIZE1  100
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
#define FIND_TREES     "FindTrees"
#define STACK 		   "Stack"

// Number of test per size
#define NB_TEST_PER_SIZE 20

// Number of test to do
#define NB_SIZE_TO_TEST 15

// Maximum time allowed to a test (5 minutes)
#define TIME_BEFORE_STOP 300

// Maximum value for a random element
#define MAX_RAND_VALUE 100

// The csv separator used
#define CSV_SEPARATOR ';'

// The tested type
typedef int TYPE;

// All the sizes to test
const size_t sizesTab[NB_SIZE_TO_TEST] = {SIZE1, SIZE2, SIZE3, SIZE4, SIZE5, SIZE6,
						SIZE7, SIZE8, SIZE9, SIZE10, SIZE11, SIZE12,
						SIZE13, SIZE14, MAX};

// All the available algorithims
const char* algos[9] = {BUBBLES, SEQUENTIAL_INS, SEQUENTIAL_INS_CHAINED, DICHO_INS, SELEC_PERM, 
						MERGE, QUICKSORT, FIND_TREES, STACK};

// The name of the chosen algorithim
char* chosenAlgo;
// The pointer to the chosen algorithim
void (*algo)(int tab[], const size_t tabSize);

// All the results
double results[15];
// The inedx of the current size
size_t currentSize;

/**
* Initialize all values in tab of size size to a random number. tab must have been set to size size.
* @param tab The table to generate values into. Must have been set to size size.
* @param size the size of tab.
* @author Rémi SEGRETAIN
*/
void initTabRand (int tab[], const size_t size) {
	for (size_t i = 0; i < size; ++i) {
		tab[i] = (unsigned int) rand() % MAX_RAND_VALUE;
	}//for
}// initTabRand

void initListRand(LIST* myList, const size_t size) {
	LIST head = myList;
	NODE node = head;
	
	for (size_t i = 0; i < size; ++i) {
		node = node->new_LIST(myList);
		node->value = (unsigned int) rand() % MAX_RAND_VALUE;
		node = node->next;
	}
	
	myList = head;
}

/**
* Displays an error message about arguments
* @author Thomas MEDARD
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
* @author Thomas MEDARD
*/
void testTime(int tab[], const size_t tabSize) {
	sleep(1);
}

/**
* Create (or replace) a csv file names fileName and write all elements in titleTab.
*
* @param fileName The name of the file that should be created or replaced.
* @param titleTab The first elements wrote in a line. Correspond to a line of titles.
* @param tableSize The size of titleTab, because we can't know it here.
* @return the file descriptor of the csv file.
* @author Thomas MEDARD
*/
FILE* createCSV(char* fileName, const size_t titlesTab[], size_t tableSize) {
	
	FILE* file = fopen(fileName, "w");
	
	if (file == NULL) {
		perror("fopen");
		exit(1);
	}
	
	for (size_t i = 0; i < tableSize; ++i) {
		fprintf(file, "%uz%c", titlesTab[i], CSV_SEPARATOR);
	}
	
	fprintf(file, "\n");
	fclose(file);
	
	return file;
}

/**
* Write a line of element in a csv file (that must exists).
* 
* @param fileName the name of the file to write into.
* @param tab the elements to write.
* @tableSize the size of tab, because we can't know it here.
* @author Thomas MEDARD
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
* Create the csv report for the current tested test.
* @author Thomas MEDARD 
*/
void creatReport(void) {
	
	char fileName[29];
	
	fileName[0] = '.';
	fileName[1] = '.';
	fileName[2] = '/';
	
	strcat(fileName, chosenAlgo);
	strcat(fileName, ".csv");

	createCSV(fileName, sizesTab, NB_SIZE_TO_TEST);
	writeLineCsv(fileName, results, currentSize);
	
	printf("Report %s created", fileName);
}

/**
* Function called on SIGALRM (when a test is too long).
* @param sig the code of the signal (unused but needed).
* @author Thomas MEDARD
*/
void alarmHandler(int sig) {
	printf("Test too long on size %d\n", sizesTab[currentSize]);
	
	creatReport();
	
	exit(0);
}

/**
* Function to lauch a test of sizeToTest size.
* @param sizeToTest The size of the table to test.
* @author Thomas MEDARD, Rémi SEGRETAIN
*/
void launchTest(const size_t sizeToTest) {
	srand(time(0));
	// Creating the table
	int tab[sizeToTest];
	
	// All results
	double resultsSum = 0.0;
	
    // Launching alarm
	alarm(TIME_BEFORE_STOP);
	
	// If we want a chained list
	int isList = 0;
	LIST myList;
	
	// If we want a chained list
	if (strcmp(chosenAlgo, SEQUENTIAL_INS_CHAINED) == 0) {
		isList = 1;
	}

	// Testing NB_TEST_PER_SIZE times then getting the average result
	for (int i = 0; i < NB_TEST_PER_SIZE; ++i) {
		
		// If we want a chained list
		if (isList == 1) {
			
			
			// Generating the list
			initListRand(myList, sizeToTest)
			
			continue;
		}

		// Generating  its values
		initTabRand(tab, sizeToTest);
				
		// Begin time mesure
		clock_t begin = clock();
		
		// Calling the chosen algorithim
		algo(tab, sizeToTest);
		
		// End time mesure
		clock_t end = clock();
		
		// Calculating passed time
		resultsSum += ((double)end - (double)begin) / CLOCKS_PER_SEC * 1000.0;
	}
	
	const double finalRes = resultsSum / (double) NB_TEST_PER_SIZE;
	results[currentSize] = finalRes;
	
	printf("for size %d : %lf ms\n", sizeToTest, finalRes);
	
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
	else if (strcmp(arg, SEQUENTIAL_INS_CHAINED) == 0) {
		chosenAlgo = SEQUENTIAL_INS_CHAINED;
		algo = testTime;
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
		algo = quickSortMain;
	}
	else {
		displayArgsErr();
		exit(1);
	}
}

/**
* The main : make all test for on sorting algorithim
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
