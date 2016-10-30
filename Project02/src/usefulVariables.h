/*
 * usefulVaritables.h
 * Given by project assignment
 *  Created on: Oct 20, 2016
 *      Author: Kevin Kan
 */

#ifndef USEFULVARIABLES_H_
#define USEFULVARIABLES_H_

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int bool;
#define true 1
#define false 0

int SuperviseThreads(int numObs, int numRegions, bool chatty);
void *dataFiller(void *sourceData);
void *accountingFunction(void *currVar);

typedef struct currentVariables{
	int start_region;
	int num_shops;
	double *Revenue;
	double *Expenses;
	double *Overhead;
	double *Profit;
	double RegionProfit;
	int regionNumber;
	bool beChatty;
} currVar;

typedef struct input_data{
	char* sourceFileName;
	double *values;
	int numObs;
	bool beChatty;
} sourceData;

#define max(a,b) __typeof__ (a) _a = (a);

#endif /* USEFULVARIABLES_H_ */
