/*
 * InsertionSort.h
 *
 *  Created on: 22-Apr-2018
 *      Author: Madhukar
 */

#ifndef INSERTIONSORT_H_
#define INSERTIONSORT_H_
#include "VectorSorter.h"
#include "Sorter.h"
/**
 * Implement the insertion sort algorithm
 * for a vector of data.
 */
class InsertionSort: public VectorSorter
{
public:
    /**
     * Default constructor.
     */
    InsertionSort();

    /**
     * Destructor.
     */
    virtual ~InsertionSort();

    /**
     * Run the insertion sort algorithm.
     * @throws an exception if an error occurred.
     */
    virtual void run_sort_algorithm();
};

#endif /* INSERTIONSORT_H_ */
