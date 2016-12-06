/*
 * Elevator.c
 *
 *  Created on: Dec 2, 2016
 *      Author: Kevin Kan
 *
 *  Description: This Elevator algorithm starts at 500, and visits all cylinders
 *  			greater than 500 in ascending order, then all cylinders less
 *  			than 500 in descending order.
 *  			The algorithm is first sorted with mergesort, a recursive sorting
 *  			algorithm, to allow for easier sorted traversal.
 */

#include "Project05Header.h"

void Elevator(int rows, int cols, int array[rows][cols]){
	double totalSum = 0, averageDist = 0;
	int sum, distance, count;
	int distArray[12];
	printf ("\n------------------------------------------------------------------------------------------------------------\n");

	for (int i = 0; i < 12; i++){
		sum = 0;
		distance = 0;
		count = 0;

		mergesort(array[i],12);
		printf("Set %i Elevator\n",i+1);
		printf("Cylinders:\t");
		for (int j = 0; j < 12; j++){
			if (array[i][j] > 500){
				distArray[count] = array[i][j];
				count++;
				printf("%i\t", array[i][j]);
			}
		}

		for (int k = 11; k >= 0; k--){				// Prints Cylinders
			if (array[i][k] < 500){
				distArray[count] = array[i][k];
				count++;
				printf("%i\t", array[i][k]);
			}
		}

		printf("\nDistances:\t");
		printf("%i\t", abs(500-distArray[0]) );
		for (int j = 1; j < 12; ++j){
			distance = abs(distArray[j] - distArray[j-1]);
			sum += distance;
			printf("%i\t", distance );
		}
		printf("\nTotal Distance: %i", sum);
		totalSum += sum;
		printf("\n------------------------------------------------------------------------------------------------------------\n");
	}
	averageDist = totalSum/12;
	printf("\nElevator Algorithm Average: %f", averageDist);
	printf("\n\n");
}

