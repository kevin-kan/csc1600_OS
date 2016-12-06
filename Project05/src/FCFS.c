/*
 * FCFS.c
 *
 *  Created on: Dec 2, 2016
 *      Author: Kevin Kan
 *
 *  Description: The First Come First Serve Algorithm traverses the cylinders at
 *  			a "first come first serve" basis, where the first item in is the
 *  			first item viewed.
 */

#include "Project05Header.h"

void FCFS(int rows, int cols, int array[rows][cols]){
	double averageDist = 0, totalSum = 0;
	int sum, distance;
	printf ("\n------------------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < 12; i++){
		sum = 0;
		distance = 0;

		printf("\tSet %i FCFS\n",i+1);
		printf("Cylinders:\t");
		for (int j = 0; j < 12; j++){				// Print Cylinders for each set
			printf("%i\t", array[i][j]);
		}

		printf("\nDistance:\t");
		printf("%i\t", abs(500 - array[i][0]) );
		for (int j = 1; j < 12; ++j){
			distance = abs(array[i][j]-array[i][j-1]);
			sum += distance;
			printf("%i\t", distance );
		}

	printf("\nTotal Distance: %i", sum);
	totalSum += sum;
	printf("\n------------------------------------------------------------------------------------------------------------\n");
	}

	averageDist = totalSum/12;
	printf("FCFS Algorithm Average: %f", averageDist);
	printf("\n\n");
}
