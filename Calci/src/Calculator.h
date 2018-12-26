/*
 * Calculator.h
 *
 *  Created on: 12-Apr-2018
 *      Author: Madhukar
 */

#ifndef SRC_CALCULATOR_H_
#define SRC_CALCULATOR_H_
#include<vector>
#include<iostream>
using namespace std;
class Calculator {
public:
	Calculator();
	virtual ~Calculator();
	vector<string> exp;
	double expression();
	double term();
	double factor();
	double result;
};

#endif /* SRC_CALCULATOR_H_ */
