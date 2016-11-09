/*
 * dataFiller.c
 *
 *  Created on: Oct 20, 2016
 *      Author: Kevin Kan
 */

#include "usefulVariables.h"

void *dataFiller(void * sourceIn){
	sourceData *source = (sourceData*) sourceIn;
	int i;

	FILE* myfile = fopen(source-> sourceFileName, "r");
	long pageW, pageX;
	FILE *pagesOut = source -> outfile;
	pageW = ((long) &i)/PAGESIZE;

	for (i = 0; i< source->numObs; i++){
		fprintf(pagesOut, " %ld \n", pageW);
		pageX = ((long) source -> values)/PAGESIZE;
		fprintf(pagesOut, " %ld \n", pageX);
		fscanf(myfile, "%lf", source->values++);

	}
	fclose(myfile);
	return 0;
}
