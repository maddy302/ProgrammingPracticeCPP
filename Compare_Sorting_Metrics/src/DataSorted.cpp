/*
 * DataSorted.cpp
 *
 *  Created on: 22-Apr-2018
 *      Author: Madhukar
 */

#include "DataSorted.h"

DataSorted::DataSorted() : DataGenerator("Already sorted") {}

/***** Complete this file. *****/
void DataSorted::generate_data(vector<Element>& data, const int size){
	for(int i=0;i<size;i++){
		data.push_back(Element(i));
	}
}
DataSorted::~DataSorted(){

}
