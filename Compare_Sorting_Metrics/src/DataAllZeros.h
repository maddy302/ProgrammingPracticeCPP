/*
 * DataAllZeroes.h
 *
 *  Created on: 22-Apr-2018
 *      Author: Madhukar
 */

#ifndef DATAALLZEROS_H_
#define DATAALLZEROS_H_
#include "DataGenerator.h"
#include "Element.h"
#include <vector>
using namespace std;
/**
 * Generator for data that is all zeros.
 */
class DataAllZeros: public DataGenerator
{
public:
    /**
     * Default constructor.
     */
    DataAllZeros();

    /**
     * Destructor.
     */
    virtual ~DataAllZeros();

    /**
     * Generate all zeros to fill a data vector.
     * @param data the data vector to fill.
     */
    virtual void generate_data(vector<Element>& data, const int size);
};

#endif /* DATAALLZEROS_H_ */
