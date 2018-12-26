/*
 * QuickSortSuboptimal.cpp
 *
 *  Created on: 22-Apr-2018
 *      Author: Madhukar
 */

#include "QuickSortSuboptimal.h"
#include "VectorSorter.h"
#include "Element.h"
#include "Sorter.h"
#include <vector>

QuickSortSuboptimal::QuickSortSuboptimal() : QuickSorter("Quicksort suboptimal") {}

/***** Complete this file. *****/
QuickSortSuboptimal::~QuickSortSuboptimal(){

}

Element& QuickSortSuboptimal::choose_pivot_strategy(int left, int right){
return VectorSorter::data[left];
}
