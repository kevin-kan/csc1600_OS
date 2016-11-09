/*
 * dataSaver.c
 *
 *  Created on: Nov 1z, 2016
 *      Author: Kevin
 */

#include "usefulVariables.h"

FILE* dataSaver(char* fileName)
{
	FILE *myfile;
	printf("opening for output file%s\n", fileName); fflush(stdout);
	myfile = fopen(fileName, "w+");
	if(myfile == NULL)
	{
		printf("error in opening. errno = %d\n", errno); fflush(stdout);
		exit(-1);
	}
	else
	{
		printf("opened for output file %s\n", fileName); fflush(stdout);
		printf("no error in opening. errno = %d\n", errno); fflush(stdout);
	}
	return myfile;
}

