/*
 * DataRandom.cpp
 *
 *  Created on: 22-Apr-2018
 *      Author: Madhukar
 */

#include "DataRandom.h"
#include <stdlib.h>
#include <time.h>
#include "DataRandom.h"
#include "Element.h"

DataRandom::DataRandom() : DataGenerator("Unsorted random") {}

/***** Complete this file. *****/
void DataRandom::generate_data(vector<Element>& data, const int size){

srand(time(0));

	for(int i=0;i<size;i++){
		data.push_back(Element(rand()));
	}

}

DataRandom::~DataRandom(){

}
