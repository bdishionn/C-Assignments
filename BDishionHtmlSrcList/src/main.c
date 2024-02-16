/*
 ============================================================================
 Name        : BDishionHtmlSrcList.c
 Author      : Brendan Dishion
 Version     :
 Copyright   : Your copyright notice
 Description : Html Src List Assignment
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int getNumAttributes(char *html);
int getUrl(char *html);
void getTags(char *html);

int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0);
	printf("URL:\n");

	char buffer[BUFSIZ + 1]; // array for buffer
	char *htmlPtr = (char*) malloc(260000); // dynamically allocates space so pointer can be cast to another pointer
	char *urlPtr = (char*) malloc(100000); // allocates space dynamically for url pointer

	strcat(urlPtr, "curl -s "); // concatenates curl onto url pointer
	gets(buffer);
	strcat(urlPtr, buffer);

	FILE *fp;
	fp = popen(urlPtr, "r");

	while (fgets(buffer, BUFSIZ, fp) != NULL) {
		htmlPtr = strcat(htmlPtr, buffer); // concatenates buffer onto htmlPtr
	}
	printf("Ready\n");
	int end = 0;
	do {
		switch (getc(stdin)) { // prints ready for each case
		case 'c': // gets count of tags
			getNumAttributes(htmlPtr);
			printf("Ready\n");
			break;
		case 't': // prints all valid src tags
			getTags(htmlPtr);
			printf("Ready\n");
			break;
		case 'u': // prints all valid url tags
			getUrl(htmlPtr);
			printf("Ready\n");
			break;
		case 'f':
			printf("Ready\n");
			break;
		case 'q': // exits on q, prints complete
			end = 1;
			break;
		default:
			break;
		}
	} while (end == 0);
	printf("Complete\n");
	return 0;
}
// gets and prints out all url related tags and the url
int getUrl(char *html) {
	while ((html = strstr(html, "src=\"")) != NULL) {
		if (isspace(*(html - 1))) { // checks whether character is white-space char
			html += 5; // adds 5 to html pointer
			while (*html != '\"') {
				// printing letter by letter
				printf("%c", *html);
				html++;
			}
			printf("\n");

		}
		html++;
	}
	return 0;
}
// prints all tags with valid src tags
void getTags(char *html) {
	int pos = 0;
	char tag[BUFSIZ];
	char *pointerTag;
	while ((html = strstr(html, "src=\"")) != NULL) {
		if (isspace(*(html - 1))) { // checks for whitespace
			pointerTag = html++; // set pointer equal to html increment
			while (*(pointerTag - 1) != '<') // decrement until we find <
				pointerTag--;
			pos = 0;
			while (!isspace(*pointerTag)) // while no whitespace, increment
				tag[pos++] = *(pointerTag++);
			tag[pos] = '\0';
			printf("%s\n", tag);
		}
		html++;
	}

}
// gets the # of valid src tags in html doc
int getNumAttributes(char *html) {
	int num = 0;
	while ((html = strstr(html, "src=\"")) != NULL) {
		if (isspace(*(html - 1))) { // checks for whitespace
			num++; // increment if this is the case
		}
		html++; // increment our html pointer
	}
	printf("%d\n", num); // prints num of attributes
	return 0;
}

