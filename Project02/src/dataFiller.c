/*
 * dataFiller.c
 *
 *  Created on: Oct 20, 2016
 *      Author: Kevin Kan
 */

#include "usefulVariables.h"

void *dataFiller(void * sourceIn){
	sourceData *source = (sourceData*) sourceIn;

	FILE* myfile = fopen(source-> sourceFileName, "r");
//	printf("myfile = %d", myfile);
//	printf("in dataFiller %s \n", source -> sourceFileName);
//	double inner;
	for (int i = 0; i< source->numObs; i++){
//		printf("i = %d\n", i);
		fscanf(myfile, "%lf", source->values++);
//		fscanf(myfile, "%lf", &inner);
//		if (i < 10) printf("values[%i] = %lf\n", i, inner);
//		source -> values[i] = inner;
	}
	fclose(myfile);
	return 0;
}
