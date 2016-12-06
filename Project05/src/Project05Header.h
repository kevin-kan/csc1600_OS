/*
 * Project05Header.h
 *
 *  Created on: Dec 2, 2016
 *      Author: Kevin Kan
 *
 *  Description: This file contains functions declarations and libraries used in the Project.
 */

#ifndef PROJECT05HEADER_H_
#define PROJECT05HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FCFS(int rows, int cols, int array[rows][cols]);		//First Come First Serve
void SST(int rows, int cols, int array[rows][cols]);		//Shortest Seek Time First
void Elevator(int rows, int cols, int array[rows][cols]);	//Elevator Algorithm

void merge(int arr[], int first, int last);				// Merge function for mergesort
void mergesortHelper(int arr[], int begin, int end);	// Main mergesort algorithm
void mergesort(int arr[], int size);					// Mergesort call (made similar to other sort calls).

#endif /* PROJECT05HEADER_H_ */
