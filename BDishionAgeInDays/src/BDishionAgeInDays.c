/*
 ============================================================================
 Name        : BDishionAgeInDays.c
 Author      : Brendan Dishion
 Version     :
 Copyright   : Your copyright notice
 Description : Age in Days program, calculates age in days
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char buffer[BUFSIZ + 1];
	int ageInYears;
	int ageInDays;
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("Enter your age:\n");
	ageInYears = atoi(fgets(buffer, BUFSIZ, stdin));
	ageInDays = 365 * ageInYears;
	printf("%d years old is about %d days old.\n", ageInYears, ageInDays);
	return EXIT_SUCCESS;
}
