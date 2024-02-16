/*
 ============================================================================
 Name        : BDishionNucleotideCounter.c
 Author      : Brendan Dishion
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	char filenamei[BUFSIZ];
	char filenamew[BUFSIZ];
	FILE *inputFi;
	FILE *outputFi;

	printf("Enter input filename:\n");
	scanf("%s", filenamei);
	printf("Enter output filename:\n");
	scanf("%s", filenamew);

	inputFi = fopen(filenamei, "r");
	outputFi = fopen(filenamew, "w");

	printf("Complete\n");

	int numA;
	int numC;
	int numG;
	int numT;
	char nextChar;

	while ((nextChar = fgetc(inputFi)) != EOF) {

		switch (nextChar) {

		case 'A':
			++numA;
			break;
		case 'C':
			++numC;
			break;
		case 'G':
			++numG;
			break;
		case 'T':
			++numT;
			break;
		case '\n':
			fprintf(outputFi, "%i %i %i %i\n", numA, numC, numG, numT);
			numA = numC = numG = numT = 0;
			break;
		}
	}

	fclose(inputFi);
	fclose(outputFi);
	return EXIT_SUCCESS;
}
