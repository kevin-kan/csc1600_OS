/*
 * SST.c
 *
 *  Created on: Dec 2, 2016
 *      Author: Kevin Kan
 *
 *  Description: The Shortest Seek Time First algorithm is a direct improvement
 *  			off the FCFS algorithm. The drive keeps locates which request is
 *  			closest to the current position of the head, and services that
 *  			request first.
 */

#include "Project05Header.h"

void SST(int rows, int cols, int array[rows][cols]){
	double totalSum = 0, averageDist = 0;
	int sum, distance, armState;
	int next, temp, maxDist, tempK;
	int tempArr[12][12], distArray[12], numstore[12];

	for (int i = 0; i < 12; i++){				// Make a copy of array
		for (int j = 0; j < 12; j++){
			tempArr[i][j] = array[i][j];
		}
	}

	printf ("\n------------------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < 12; i++){			// SST, then store into array
		armState = 500; 						// Arm starts at 500
		sum = 0;
		distance = 0;
		for (int j = 0; j < 12; j++){
			maxDist = 1000;
			for (int k = 0; k < 12; k++){
				next = tempArr[i][k];
				distance = abs(armState - next);
				if(distance <= maxDist && next < 1000){
					maxDist = distance;
					temp = next;
					tempK = k;
				}
			}
			numstore[j] = temp;
			distArray[j] = maxDist;
			armState = temp;
			tempArr[i][tempK] = 1000;
			sum += maxDist;
		}

		printf("Set %i\tSST\n",i+1);
		printf("Cylinders:\t");
		for (int j = 0; j < 12; j++){
			printf("%i\t", numstore[j]);
		}

		printf("\nDistance\t");
		for (int j = 0; j < 12; j++){
			printf("%i\t", distArray[j]);
		}

		printf("\nTotal Distance:\t%i",sum);
		printf("\n------------------------------------------------------------------------------------------------------------\n");
		totalSum += sum;
	}
	averageDist = totalSum/12;
	printf("SST Algorithm Average: %f", averageDist);
	printf("\n\n");
}
