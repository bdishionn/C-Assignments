/*
 ============================================================================
 Name        : BDishionThreeNPlusOne3.c
 Author      : Brendan Dishion
 Version     :
 Copyright   : Your copyright notice
 Description : Three N Plus One Algorithm
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int computeMaxSequenceLength(int, int);
int computeNextValue(int);
int computeSequenceLength(int);

// computes each value in the sequence

int computeNextValue(int n) {

	if (n % 2 == 0)
		return n / 2;
	return 3 * n + 1;
}

// returns and computes length of sequence

int computeSequenceLength(int n) {

	int length = 0;
	while (n != 1) {
		length++;
		n = computeNextValue(n);
	}
	return length + 1;
}

// for each value in a range, we update the max sequence length

int computeMaxSequenceLength(int first, int last) {
	int temp;
	int max = 0;
	for (int i = first; i <= last; i++) {
		temp = computeSequenceLength(i);
		if (temp > max) {
			max = temp;
		}
	}
	return max;
}

int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0);

	char buffer[BUFSIZ];

	FILE *fn;
	int first;
	int last;

	printf("Output Filename:\n");
	fgets(buffer, BUFSIZ, stdin);
	buffer[strlen(buffer) - 1] = '\0'; // replaces '/n' at end of buffer with 0
	fn = fopen(buffer, "w"); // open file for writing

	while (fgets(buffer, BUFSIZ, stdin)) { // used for conditions

		if (*buffer == '\n') // if address of buffer is newline
			break; // break statement

		first = atoi(buffer); // else set first as buffer and store as int

		fgets(buffer, BUFSIZ, stdin); // reads in next value
		last = atoi(buffer); // stores it in last value as int

		fprintf(fn, "%d\t%d\t%d\n", first, last,
				computeMaxSequenceLength(first, last));

	}

	printf("Complete\n");
	fclose(fn);

	return 0;
}
