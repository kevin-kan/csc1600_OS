/*
 ============================================================================
 Name        : Project04.c
 Author      : Kevin Kan
 Version     : 1.0
 Copyright   : 2016
 Description : Project 4: File Timing

 -	Implement a projegram to measure the impact of application-level buffer
 sizes on file write and read times. This involves writing to and reading
 from a large file (2GB). Vary the application buffer size (from 64 bytes to
 128 bytes to 256 bytes to ... to 64 KB, doubling buffer size each step).
 - Use timing measurement routines to measure time taken for different buffer
 sizes
 -Analyze.
 ============================================================================
 */

#include <time.h> // For Clock
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(void) {
	clock_t startR, endR, startW, endW;
	double readTime = 0, writeTime = 0;
	int inFile, outFile, readCount, writeCount;
	char buffer[BUFFER_SIZE];

	/* Open the input file and create the output file */
	inFile = open("P4_input_file.txt", O_RDONLY);
	if (inFile < 0) {
		printf("error in opening read file.\n");
		return(2);
	}
	outFile = creat("P4_output_file.txt", 0700);
	if (outFile < 0){
		printf("error in creating write file. \n");
		return(3);
	}

	/* Copy loop */
	while (1) {
		startR = clock();										// start read clock
        //fprintf("startR = %f",startR);
		readCount = read(inFile, buffer, BUFFER_SIZE);  		// read a block of data
		endR = clock();											// end read clock
		if (readCount <= 0) break; 								// if end of file or error, return loop
		readTime = (double)(endR - startR);

		startW = clock();										// start write clock
		writeCount = write(outFile, buffer, readCount); 		// write data
		endW = clock();											// end write clock
		if (writeCount <= 0) return(4);							// error in writing
		writeTime = (double)(endW - startW);
	}
	/* Close the files */
	close(inFile);
	close(outFile);

	/* output statements in clock cycles and seconds */
	printf("The read time for %i bytes is %f clock cycles or %f seconds.\n", BUFFER_SIZE, readTime, (double)readTime/CLOCKS_PER_SEC);
	printf("The write time for %i bytes is %f clock cycles or %f seconds.\n", BUFFER_SIZE, writeTime, (double)writeTime/CLOCKS_PER_SEC);

	if (readCount == 0) return(0);								// complete.
	else return(5); 												// error in last thread

	return 0;
}
