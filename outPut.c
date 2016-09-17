#include <stdio.h>
#include <stdlib.h>

#include "Workbench.c"

#define csvSeparator ';'

/**
* Create (or replace) a csv file names fileName and write all elements in titleTab.
*
* @param fileName The name of the file that should be created or replaced.
* @param titleTab The first elements wrote in a line. Correspond to a line of titles.
* @param tableSize The size of titleTab, because we can't know it here.
* @return the file descriptor of the csv file.
* @author Thomas MEDARD
*/
FILE* createCSV(const char* fileName, const char* titleTab[], const size_t tableSize) {
	FILE* file = fopen(fileName, "w");
	
	if (file == NULL) {
		fprintf(stderr, "fopen failed (file maybe already opened)\n");
		exit(1);
	}
	
	for (size_t i = 0; i < tableSize; ++i) {
		fprintf(file, "%s%c", titleTab[i], csvSeparator);
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
void writeLineCsv(const char* fileName, const TABLEAU tab, const size_t tableSize) {
	FILE* file = fopen(fileName, "a");
	
	if (file == NULL) {
		fprintf(stderr, "fopen failed (file maybe already opened or doesn't exists)\n");
		exit(1);
	}
	
	for (size_t i = 0; i < tableSize; ++i) {
		fprintf(file, "%d%c", tab[i], csvSeparator);
	}
	
	fprintf(file, "\n");
	fclose(file);
}
// Testing main
/*int main() {
	char* titles[] = {"title1", "title2", "title3", "title4"};
	int tab[4];
	
	genereTab(tab, 4);
	
	createCSV("test.csv", titles, 4);
	writeLineCsv("test.csv", tab, 4);
	
	return 0;
}*/