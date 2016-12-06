/*
 * MergeSort.c
 *
 *  Created on: Nov 16, 2016
 *      Author: Kevin
 *
 * 	Description: This is the definitions for mergesort, adapted from my mergesort written in C++ class.
 * 					Mergesort works by recursively sorting the left half and the right half of the dataset
 * 					with mergesort again, then merging the sorted pieces back together.
 * 					The Big-O Complexity of Mergesort is O(nlogn).
 */

void merge(int arr[], int first, int last){ //Merging for MergeSort
	int mid = (first + last) /2;
	int i = 0, l = first, r = mid + 1;
	int temp[last - first + 1];
	while (l <= mid && r <= last){		// compare numbers
		if (arr[l] < arr[r]){
			temp[i] = arr[l];
			l++;
		}
		else{
			temp[i] = arr[r];
			r++;
		}
		i++;
	}
	while (l <= mid){					//fill in what's remaining in left side
		temp[i] = arr[l];
		++i; ++l;
	}
	while (r <= last){					//fill in what's remaining in right side
		temp[i] = arr[r];
		++i; ++r;
	}
	long int b = first;
	for (long int a = 0; a < last-first+1; a++){	//put the sorted #s into original array
		arr[b] = temp[a];
		b++;
	}
}

void mergesortHelper(int arr[], int begin, int end){	//MergeSort Algorithm
	if (end - begin + 1 >= 2){
		int mid = (begin + end) /2;
		mergesortHelper(arr, begin, mid);		//left half
		mergesortHelper(arr, mid + 1, end);		//right half
		merge(arr, begin, end);					//put together at the end.
	}
}

void mergesort(int arr[], int size){			//So that mergesort can be called the same way as bubblesort
	mergesortHelper(arr, 0, size - 1);
}
