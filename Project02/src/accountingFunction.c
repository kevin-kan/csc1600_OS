/*
 * accountingFunction.c
 * Calculates Total profit
 *  Created on: Oct 20, 2016
 *      Author: Kevin Kan
 */
#include "usefulVariables.h"

void *accountingFunction(void *dataIn){
	currVar *data = (currVar *) dataIn;

	double *Revenue = data -> Revenue;
	double *Expenses = data -> Expenses;
	double *Overhead = data -> Overhead;
	double *Profit = data -> Profit;

	double TotalProfit = 0;

	for (int i = 0; i < data->num_shops; i++){
		*Profit = (*Revenue++) - (*Expenses++) - (*Overhead++);
		TotalProfit = TotalProfit + *Profit++;
	}

	data -> RegionProfit = TotalProfit;
	return 0;
}

