/*
 ============================================================================
 Name        : Project02.c
 Author      : Kevin Kan
 Version     : 1.0
 Copyright   : 2016
 Description : Using Threads to calculate net profits for shops and corporations
 ============================================================================
 */


#include "usefulVariables.h"

int main(int argc, char *argv[]) {
	setbuf(stdout, NULL);

	int numObs = 1000;
	int numRegions = 5;
//	printf("starting\n");
	SuperviseThreads(numObs, numRegions, false);
//	printf("finishing");

	return (0);
}
