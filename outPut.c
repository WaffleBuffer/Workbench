#include <stdio.h>
#include <stdlib.h>

#include "testTri.c"

FILE* createCSV(const char* fileName, const char* titleTab[], const size_t tableSize) {
	FILE* file = fopen(fileName, "w");
	
	if (file == NULL) {
		fprintf(stderr, "fopen failed (file maybe already opened)\n");
		exit(1);
	}
	
	for (size_t i = 0; i < tableSize; ++i) {
		fprintf(file, "%s;", titleTab[i]);
	}
	
	fprintf(file, "\n");
	fclose(file);
	
	return file;
}

void writeLineCsv(const char* fileName, const TABLEAU tab, const size_t tableSize) {
	FILE* file = fopen(fileName, "a");
	
	if (file == NULL) {
		fprintf(stderr, "fopen failed (file maybe already opened)\n");
		exit(1);
	}
	
	for (size_t i = 0; i < tableSize; ++i) {
		fprintf(file, "%d;", tab[i]);
	}
	
	fprintf(file, "\n");
	fclose(file);
}

int main() {
	char* titles[] = {"title1", "title2", "title3", "title4"};
	int tab[4];
	
	genereTab(tab, 4);
	
	createCSV("test.csv", titles, 4);
	writeLineCsv("test.csv", tab, 4);
	
	return 0;
}