/*
 ============================================================================
 Name        : Project05.c
 Author      : Kevin Kan
 Version     : 1.0
 Copyright   : 2016
 Description : Disk Arm Scheduling
 	 	 	 	 In this main file, the double array of integers is created,
 	 	 	 	 and then each scheduling algorithm is run.
 ============================================================================
 */

#include "Project05Header.h"

int main(){
	printf("Project 05 Begin.\n");
	int set[12][12]; 					// Double Array 12x12
	srand((unsigned) time(NULL)); 		// For rand() function

	for(int i=0; i<12; i++){			// Fill array
		for(int j=0; j<12; j++){
			set[i][j] = rand() % 1000; 	// random_number%1000 = 0-999
		}
	}

	/* PRINT ORIGINAL CYLINDERS */
	printf("Original Sets");
	printf ("\n------------------------------------------------------------------------------------------------------------\n");
	for(int i=0; i<12; i++){
		printf("Set %i:\t",i+1);
		for(int j=0; j<12; j++){
			printf("%i\t", set[i][j]);
		}
		printf("\n");
	}

	/* RUN ALGORITHMS */
	FCFS(12, 12, set); 		// First Come First Serve
	SST(12,12,set);			// Shortest Seek Time First
	Elevator(12,12,set); 	// Elevator Algorithm

	printf("\nProject 05 Finish.\n");
	return 0;
}
