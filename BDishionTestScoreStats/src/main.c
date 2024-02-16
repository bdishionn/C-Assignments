/*
 ============================================================================
 Name        : BDishionTestScoreStats.c
 Author      : Brendan Dishion
 Version     :
 Copyright   : Your copyright notice
 Description : Program which computes mean, min, max, and standard deviation of input
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float deviation(float arr[], float size, float sum) {
	double newsum;
	for (int i = 0; i < size; i++) {
		double sumsqs = pow(arr[i], 2);
		newsum += sumsqs;
	}
	float dev = ((newsum - (pow(sum, 2) / size)) / size);
	float root = sqrt(dev);
	if (size == 0) {
		root = 0;
	}
	return root;
}

float average(float sum, float size) {
	float average;
	average = sum / size;

	if (size == 0) {
		average = 0;
	}
	return average;
}

float min(float arr[], float size) {
	float min = 100;
	for (int i = 0; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	if (size == 0) {
		min = 0;
	}
	return min;
}

float max(float arr[], float size) {

	float max = 0;
	for (int i = 0; i < size; i++) {

		if (arr[i] > max) {
			max = arr[i];
		}
	}

	return max;
}

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	float scores[BUFSIZ + 1];
	char score[BUFSIZ + 1];
	float sum;
	float count;
	int i = 0;

	printf(
			"Enter scores, one per line. Press <ENTER> on a blank line to end.\n");

	do {

		fgets(score, BUFSIZ, stdin);
		scores[i] = atof(score);
		sum += scores[i];
		count++;
		i++;

	} while (score[0] != '\n');
	count = count - 1;

	float a = average(sum, count);
	float m = min(scores, count);
	float ma = max(scores, count);
	float dev = deviation(scores, count, sum);

	printf("%0.f\t%f\t%f\t%f\t%f\n", count, m, ma, a, dev);

	return 0;
}
