/*
 * DataReverseSorted.cpp
 *
 *  Created on: 22-Apr-2018
 *      Author: Madhukar
 */


#include "DataReverseSorted.h"

DataReverseSorted::DataReverseSorted() : DataGenerator("Reverse sorted") {}

/***** Complete this file. *****/
void DataReverseSorted::generate_data(vector<Element>& data,const int size){
	for(int i=size;i>0;i--){
		data.push_back(Element(i));
	}
}

DataReverseSorted::~DataReverseSorted(){

}
