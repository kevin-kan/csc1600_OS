/*
 * SuperviseThreads.c
 *
 *  Created on: Oct 20, 2016
 *      Author: Kevin Kan
 */

#include "usefulVariables.h"

int SuperviseThreads(int numObs, int numRegions, bool chatty ){
	int i, k;
	int threadcount = 0;
	int maxThreads = numRegions + 2;
	int totalSize = numObs * numRegions;

//	printf("superviseThreads1\n");
	sourceData revenue;
	sourceData expenses;
	currVar corporate;
	currVar region[numRegions];
	pthread_t tid[maxThreads];
	pthread_attr_t attr[maxThreads];

	for(i = 0; i<maxThreads; i++){
		pthread_attr_init(&attr[i]);
		threadcount++;
	}
//	printf("superviseThreads2\n");
	// Allocate space for corporate
	corporate.start_region = 0;
	corporate.num_shops = totalSize;
	corporate.Revenue = (double *) malloc(sizeof(double)*totalSize);
	corporate.Expenses = (double *) malloc(sizeof(double)*totalSize);
	corporate.Overhead = (double *) malloc(sizeof(double)*totalSize);
	corporate.Profit = (double *) malloc(sizeof(double)*totalSize);

//	printf("totalSize = %d\n", totalSize);

	revenue.values = corporate.Revenue;
	revenue.numObs = totalSize;
	revenue.sourceFileName = "Revenue.txt";

	expenses.values = corporate.Expenses;
	expenses.numObs = totalSize;
	expenses.sourceFileName = "Expenses.txt";

//	printf("superviseThreads3\n");

	pthread_create(&tid[0], &attr[0], dataFiller, (void *) &revenue); //create thread for revenue
//	printf("superviseThreads in between revenue and expenses\n");
	pthread_create(&tid[1], &attr[1], dataFiller, (void *) &expenses); //create thread for expenses

//	printf("superviseThreads4\n");

	for (k=0; k<2; k++){
		pthread_join(tid[k], NULL);
	}

//	printf("superviseThreads5");

	double TotalRevenue = 0;
	for (i=0; i<totalSize; i++){
		TotalRevenue += corporate.Revenue[i];
	}

	double Overhead = 1234567;		// given
	double magicFraction = 100 * Overhead/TotalRevenue;


	// Allocate
	double amountCents, partialCents, amountDollars;
	long wholeCents;

	for (i=0; i< totalSize;i++){
		amountCents = corporate.Revenue[i] * magicFraction;
		wholeCents = (long) amountCents;
		partialCents = amountCents - (double) wholeCents;
		if(partialCents > 0) wholeCents++;
		amountDollars = (double) wholeCents / 100.0;
		corporate.Overhead[i] = amountDollars;
	}

	// Compute Profit
	int begin;
	for (i = 0; i<numRegions; i++){
		begin = i*numObs;
		region[i].start_region = begin;
		region[i].num_shops = numObs;
		region[i].Revenue = &corporate.Revenue[begin];
		region[i].Expenses = &corporate.Expenses[begin];
		region[i].Overhead = &corporate.Overhead[begin];
		region[i].Profit = &corporate.Profit[begin];
		region[i].regionNumber = i;
		//create thread
		pthread_create(&tid[2+i], &attr[2+i], accountingFunction, (void *) &region[i]);
	}

	// waiting for threads to end...
	for (k=2; k<maxThreads; k++){
		pthread_join(tid[k], NULL);
	}

	//Summarize Profits
	double TotalExpenses = 0;
	double TotalOverhead = 0;
	double TotalProfit = 0;

	for (i = 0; i < totalSize; i++){
		TotalExpenses += corporate.Expenses[i];
		TotalOverhead += corporate.Overhead[i];
		TotalProfit += corporate.Profit[i];
	}

	printf("\nTotalRevenue = %12.2lf \n", TotalRevenue);
	printf("Total Expenses = %12.2lf \n", TotalExpenses);
	printf("Total Overhead = %12.2lf \n", TotalOverhead);
	printf("Total Profit = %12.2lf \n\n", TotalProfit);

	TotalProfit = 0;
	for (i = 0; i < numRegions; i++){
		begin = i*numObs;
		region[i].start_region = begin;
		printf("Region %d profits = %13.2lf \n", i, region[i].RegionProfit);
		TotalProfit += region[i].RegionProfit;
	}
	printf("\nTotal firm profit = %12.2lf\n\n", TotalProfit);
	return threadcount;
}
