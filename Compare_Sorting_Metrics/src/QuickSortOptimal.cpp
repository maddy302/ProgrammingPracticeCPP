/*
 * QuickSortOptimal.cpp
 *
 *  Created on: 22-Apr-2018
 *      Author: Madhukar
 */

#include "QuickSortOptimal.h"
#include "VectorSorter.h"
#include "Element.h"
#include "Sorter.h"
#include <vector>
using namespace std;
QuickSortOptimal::QuickSortOptimal() : QuickSorter("Quicksort optimal") {}

/***** Complete this file. *****/
QuickSortOptimal::~QuickSortOptimal(){

}

Element& QuickSortOptimal::choose_pivot_strategy(int left, int right){

	int mid = (left+right)/2;
	//VectorSorter::compare_count++;
	   if ( VectorSorter::data[mid] < VectorSorter::data[left] )
	      swap(left,mid);

	  // VectorSorter::compare_count++;
	   if ( VectorSorter::data[right] < VectorSorter::data[left] )
	      swap(left,right);

	   //VectorSorter::compare_count++;
	   if ( VectorSorter::data[right] < VectorSorter::data[mid] )
	      swap(mid,right);

	   swap(left,mid);

	return VectorSorter::data[left];
}
