/*
 * accountingFunction.c
 * Calculates Total profit
 *  Created on: Oct 20, 2016
 *      Author: Kevin Kan
 */
#include "usefulVariables.h"

void *accountingFunction(void *dataIn){
	int i;
	currVar *data = (currVar *) dataIn;

	double *Revenue = data -> Revenue;
	double *Expenses = data -> Expenses;
	double *Overhead = data -> Overhead;
	double *Profit = data -> Profit;

	double TotalProfit = 0;

	long pageW, pageX, pageY1, pageY2, pageY3, pageZ;
	FILE* pagesOut = data -> outfile;
	pageZ = (long) &i/PAGESIZE;
	pageW = (long) &TotalProfit/PAGESIZE;
	fprintf(pagesOut, " %ld \n", pageZ);

	for (i = 0; i < data->num_shops; i++){
		pageX = (long) Profit/PAGESIZE;
		pageY1 = (long) Revenue/PAGESIZE;
		pageY2 = (long) Expenses/PAGESIZE;
		pageY3 = (long) Overhead/PAGESIZE;

		fprintf(pagesOut, " %ld \n", pageZ);
		fprintf(pagesOut, " %ld \n", pageX);
		fprintf(pagesOut, " %ld \n", pageY1);
		fprintf(pagesOut, " %ld \n", pageY2);
		fprintf(pagesOut, " %ld \n", pageY3);
		fprintf(pagesOut, " %ld \n", pageW);

		*Profit = (*Revenue++) - (*Expenses++) - (*Overhead++);
		TotalProfit = TotalProfit + *Profit++;
	}

	data -> RegionProfit = TotalProfit;
	return 0;
}

