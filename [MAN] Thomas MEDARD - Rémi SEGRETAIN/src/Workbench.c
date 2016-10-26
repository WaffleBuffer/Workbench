/**
 * \file Workbench.c
 * \brief Run benchmark tests for sorting algorithim.
 * \author Thomas MEDARD, Remi SEGRETAIN
 */

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
#include "Sorts/BinaryTreeSort - struct.c"
#include "Sorts/HeapSort.c"

#include <stdio.h>  // printf
#include <stdlib.h> // itoa
#include <time.h>   // clock_t
#include <string.h> // strcmp
#include <unistd.h> // sleep
#include <string.h> // strcpy_s
#include <signal.h> //SA_RESTART

/**
 * \def SIZE1
 * \brief Size 1.
 */
#define SIZE1 100
/**
 * \def SIZE2
 * \brief Size 2.
 */
#define SIZE2 500
/**
 * \def SIZE3
 * \brief Size 3.
 */
#define SIZE3 5000
/**
 * \def SIZE4
 * \brief Size 4.
 */
#define SIZE4 10000
/**
 * \def SIZE5
 * \brief Size 5.
 */
#define SIZE5 50000
/**
 * \def SIZE6
 * \brief Size 6.
 */
#define SIZE6 100000
/**
 * \def SIZE7
 * \brief Size 7.
 */
#define SIZE7 200000
/**
 * \def SIZE8
 * \brief Size 8.
 */
#define SIZE8 300000
/**
 * \def SIZE9
 * \brief Size 9.
 */
#define SIZE9 400000
/**
 * \def SIZE10
 * \brief Size 10.
 */
#define SIZE10 500000
/**
 * \def SIZE11
 * \brief Size 11.
 */
#define SIZE11 600000
/**
 * \def SIZE12
 * \brief Size 12.
 */
#define SIZE12 700000
/**
 * \def SIZE13
 * \brief Size 13.
 */
#define SIZE13 800000
/**
 * \def SIZE14
 * \brief Size 14.
 */
#define SIZE14 900000
/**
 * \def MAX
 * \brief Size 15 and also max size.
 */
#define MAX    1000000

/**
 * \def BUBBLES
 * \brief argument waited for bubble sorting algorithim.
 */
#define BUBBLES "Bubbles"
/**
 * \def SEQUENTIAL_INS
 * \brief argument waited sequential insertion sorting algorithim.
 */
#define SEQUENTIAL_INS "SequentialInsertion"
/**
 * \def SEQUENTIAL_INS_CHAINED
 * \brief argument waited for chained list sequential insertion sorting algorithim.
 */
#define SEQUENTIAL_INS_CHAINED "SequentInsChained"
/**
 * \def DICHO_INS
 * \brief argument waited for dichotomous insertion sorting algorithim.
 */
#define DICHO_INS "DichotomousInsertion"
/**
 * \def SELEC_PERM
 * \brief argument waited for selection/permutation sorting algorithim.
 */
#define SELEC_PERM "SelectionPermutation"
/**
 * \def MERGE
 * \brief argument waited for merge sorting algorithim.
 */
#define MERGE "Merge"
/**
 * \def QUICKSORT
 * \brief argument waited for quicksort sorting algorithim.
 */
#define QUICKSORT "QuickSort"
/**
 * \def B_TREE
 * \brief argument waited for binary tree sorting algorithim.
 */
#define B_TREE_STRUCT "BinaryTree"
/**
 * \def HEAP
 * \brief argument waited for heap sorting algorithim.
 */
#define HEAP "HeapSort"

/**
 * \def NB_TEST_PER_SIZE
 * \brief Number of test to run for each size.
 */
#define NB_TEST_PER_SIZE 20

/**
 * \def NB_SIZE_TO_TEST
 * \brief Number of size to test.
 */
#define NB_SIZE_TO_TEST 15

/**
 * \def TIME_BEFORE_STOP
 * \brief The time left for each test sequences (All tests on a size) befor we stop it.
 */
#define TIME_BEFORE_STOP 300

/**
 * \def MAX_RAND_VALUE
 * \brief The maximum value for random generated values inside arrays to sort.
 */
#define MAX_RAND_VALUE 100

/**
 * \def CSV_SEPARATOR
 * \brief The character used to separate values in CSV generated files. 
 */
#define CSV_SEPARATOR ';'

// All the sizes to test
const size_t sizesTab[NB_SIZE_TO_TEST] = {SIZE1, SIZE2, SIZE3, SIZE4, SIZE5, SIZE6,
						SIZE7, SIZE8, SIZE9, SIZE10, SIZE11, SIZE12,
						SIZE13, SIZE14, MAX};

// All the available algorithims
const char* algos[9] = {BUBBLES, SEQUENTIAL_INS, SEQUENTIAL_INS_CHAINED, DICHO_INS, SELEC_PERM,
						MERGE, QUICKSORT, B_TREE_STRUCT, HEAP};

// The name of the chosen algorithim
char* chosenAlgo;
// The pointer to the chosen algorithim
void (*algo)(TYPE tab[], const size_t tabSize);

// All the results
double results[15];
// The inedx of the current size
size_t currentSize;

/**
 * \fn void initTabRand (TYPE tab[], const size_t size)
 * \brief Initialize all values in tab of size size to a random number. tab must have been set to size size.
 * \param[in, out] tab The table to generate values into. Must have been set to size size.
 * \param[in] size The size of tab. Must be valid.
 */
void initTabRand (TYPE tab[], const size_t size) {
	for (size_t i = 0; i < size; ++i) {
		tab[i] = (TYPE) rand() % MAX_RAND_VALUE;
	}//for
}// initTabRand

/**
 * \fn void initListRand(List *list, const size_t size)
 * \brief Add values to list with size random number. list must have been initialized
 * \param[in, out] list The List to generate values into. Must have been initialized
 * \param[in] size the number of value to add to list. Must be valid.
 */
void initListRand(List *list, const size_t size) {

	for (size_t i = 0; i < size; ++i) {
		list->push(list, (unsigned int) rand() % MAX_RAND_VALUE);
	}
}

/**
 * \fn void displayArgsErr(void)
 * \brief Displays an error message about needed arguments
 */
void displayArgsErr(void) {
	fprintf(stderr, "Need to precise a valid algorithim.\nValids algorithims are :\n");

	for (size_t i = 0; i < 9; ++i) {
		fprintf(stderr, "%s, ", algos[i]);
	}
	fprintf(stderr, "\n");
}

/**
 * \fn void testTime(TYPE tab[], const size_t tabSize)
 * \brief Placeholder function to replace unfinished sorting algorithim.
 * \param[in, out] tab the table to test.
 * \param[in] tabSize the size of tab.
 */
void testTime(TYPE tab[], const size_t tabSize) {
	(void) tab;
	(void) tabSize;
	sleep(1);
}

/**
 * \fn FILE* createCSV(char* fileName, const size_t titlesTab[], size_t tableSize)
 * \brief Create (or replace) a csv file named fileName and write all elements of titleTab inside.
 * \param[in] fileName The name of the file that should be created or replaced. Must be initialized.
 * \param[in] titleTab Elements writen in a line. Correspond to a line of titles. Must be initialized.
 * \param[in] tableSize The size of titleTab. Must be valid.
 * \return The file descriptor (of second level) of the csv file.
 */
FILE* createCSV(const char* fileName, const size_t titlesTab[], size_t tableSize) {

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
 * \fn void writeLineCsv(const char* fileName, const double tab[], const size_t tableSize)
 * \brief Write a line of element in a csv file (that must exists).
 * \param[in] fileName the name of the file to write into. This file must exists.
 * \param[in] tab The elements to write. Must be initilized.
 * \param[in] tableSize the size of tab. Must be valid.
 */
void writeLineCsv(const char* fileName, const double tab[], const size_t tableSize) {
	FILE* file = fopen(fileName, "a");

	if (file == NULL) {
		perror("fopen");
		exit(1);
	}

	for (size_t i = 0; i <= tableSize; ++i) {
		fprintf(file, "%lf%c", tab[i], CSV_SEPARATOR);
	}

	fprintf(file, "\n");
	fclose(file);
}

/**
 * \fn void creatReport(void)
 * \brief Create the csv report for the current tested test. The test must be over.
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
 * \fn void alarmHandler(int sig)
 * \brief Function called on SIGALRM (when a test is too long).
 * \param[in] sig the code of the signal (unused).
 */
void alarmHandler(int sig) {
	// Suppress compiler warning about unused argument
	(void)sig;

	printf("Test too long on size %zu, current average : %lf ms\n", sizesTab[currentSize], results[currentSize]);

	creatReport();

	exit(0);
}

/**
 * \fn void launchTest(const size_t sizeToTest)
 * \brief Function to lauch a test of sizeToTest size.
 * \param[in] sizeToTest The size of the table to test.
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
			results[currentSize] = resultsSum / (double) i+1;

			continue;
		} // End chained list test

		// Generating  its values
		initTabRand(tab, sizeToTest);

		/*for (size_t i = 0; i < sizeToTest; ++i) {
			printf("%d ", tab[i]);
		}
		printf("\n");*/

		// Begin time mesure
		clock_t begin = clock();

		// Calling the chosen algorithim
		algo(tab, sizeToTest);

		// End time mesure
		clock_t end = clock();

		/*for (size_t i = 0; i < sizeToTest; ++i) {
			printf("%d ", tab[i]);
		}
		printf("\n\n");*/

		// Calculating passed time
		resultsSum += ((double)end - (double)begin) / CLOCKS_PER_SEC * 1000.0;
		results[currentSize] = resultsSum / (double) i+1;
	}

	const double finalRes = resultsSum / (double) NB_TEST_PER_SIZE;
	results[currentSize] = finalRes;

	printf("for size %zu : %lf ms\n", sizeToTest, finalRes);

}

/**
 * \fn void chooseAlgo(char* arg)
 * \bref Affect chooseAlgo and algo corresponding to the argument.
 * \param[in] arg The chosen algo. If it's invalid, will exit with error message.
 */
void chooseAlgo(const char* arg) {
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
	else if (strcmp(arg, B_TREE_STRUCT) == 0) {
		chosenAlgo = B_TREE_STRUCT;
		algo = bTreeSort_Struct;
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
 * \fn int main(int argc, char* argv[])
 * \brief The main : make all tests for one sorting algorithim
 * \param[in] argc The number of arguments. Must be > 1.
 * \param[in] argv The arguments. argv[1] must be initialized and a size_t (under string format).
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
