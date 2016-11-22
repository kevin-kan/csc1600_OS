/*
 * FileTest.c
 *
 *  Created on: Nov 19, 2016
 *      Author: Kevin
 *
 *  This file is to run read and write times with a buffer
 */
#include "Project04.h"

void FileTest(int bufferSize){
	printf("Reading from input file...\n");
	/* READING FROM FILE */
	int inFile, outFile, readCount, writeCount;
	char buffer[bufferSize];

	/* Open the input file and create the output file */
	inFile = open("P4_input_file.txt", O_RDONLY);
	if (inFile < 0) {
		printf("error in opening read file.\n");
		exit(2);
	}
	outFile = creat("P4_output_file.txt", 0700);
	if (outFile < 0){
		printf("error in creating write file. \n");
		exit(3);
	}

	/* Copy loop */
	while (1) {
		readCount = read(inFile, buffer, bufferSize); /* read a block of data */
		if (readCount <= 0) break; /* if end of file or error, exit loop */
		writeCount = write(outFile, buffer, readCount); /* write data */
		if (writeCount <= 0){
			printf("error in writing.\n");
			exit(4);
		}
	}
	/* Close the files */
	close(inFile);
	close(outFile);
	if (readCount == 0) exit(0);
	else {
		printf("Error in last thread.\n");
		exit(5);
	}
}
