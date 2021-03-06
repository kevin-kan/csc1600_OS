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

	long frames = 6;
	int numObs = 40;
	int numRegions = 125;

	SuperviseThreads(numObs, numRegions, false);

	while(frames > 0)
	{
		printf("Number of frames: ");
		scanf("%ld", &frames);
		LRU(frames);
	}

	return (0);
}
