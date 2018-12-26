/*
 * DataGenerator.cpp
 *
 *  Created on: 22-Apr-2018
 *      Author: Madhukar
 */

#include <string>
#include <vector>
#include "DataGenerator.h"

/***** Complete this file. *****/


DataGenerator::DataGenerator(string name){
	this->name = name;
}

string DataGenerator::get_name(){
	return name;
}

DataGenerator::~DataGenerator(){

}
