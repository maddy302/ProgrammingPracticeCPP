/*
 * QuickSorter.cpp
 *
 *  Created on: 22-Apr-2018
 *      Author: Madhukar
 */

#include <iostream>
#include "VectorSorter.h"
#include "QuickSorter.h"
#include "Element.h"
#include "Sorter.h"
using namespace std;

QuickSorter::QuickSorter(string name) : VectorSorter(name) {}

QuickSorter::~QuickSorter() {}

void QuickSorter::run_sort_algorithm() throw (string)
				{
	quicksort( 0,  Sorter::size-1);
				}

void QuickSorter::quicksort(const int left, const int right)
{
	// Continue the recursive calls until the indexes cross.
	if (left <= right)
	{
		// Choose the pivot and partition this subrange.
		Element& pivot = choose_pivot(left, right);
		int p = partition(left, right, pivot);

		quicksort(left, p-1);  // Sort elements <  pivot
		quicksort(p+1, right); // Sort elements >= pivot
	}
}

Element& QuickSorter::choose_pivot(const int left, const int right)
{
	return choose_pivot_strategy(left, right);
}

//Mallik pg 557
int QuickSorter::partition(const int left, const int right, const Element& pivot)
{
	/***** Complete this function. *****/

	/*int i=left;
int j= right;

while(i<j){
	VectorSorter::compare_count++;
	while(1){
		//VectorSorter::compare_count++;
		if(VectorSorter::data[i]<pivot){
			i++;
		}else{
			break;
		}
	}
	while(1){
		//VectorSorter::compare_count++;
		if(VectorSorter::data[j]>pivot){
			j--;
		}else{
			break;
		}

	}
	if(i<j){
		VectorSorter::swap(i,j);
	}
}*/

	int index=0, smallIndex=0;
	smallIndex = left;
	for ( index = left + 1; index <= right; index++)
	{
		VectorSorter::compare_count++;
		if(VectorSorter::data[index] < pivot)
		{
			smallIndex++;
			swap(smallIndex, index);
		}
	}
	VectorSorter::swap(left, smallIndex);
	return smallIndex;
	//return i;
}
