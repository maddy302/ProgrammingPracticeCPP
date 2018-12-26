/*
 * DataAllZeroes.cpp
 *
 *  Created on: 22-Apr-2018
 *      Author: Madhukar
 */

#include "DataAllZeros.h"
#include <vector>
using namespace std;
DataAllZeros::DataAllZeros() : DataGenerator("All zeroes") {}

/***** Complete this file. *****/

void DataAllZeros::generate_data(vector<Element>& data, const int size){

	for(int i=0; i<size; i++){
		data.push_back(Element(0));
	}
}


DataAllZeros::~DataAllZeros(){

}
