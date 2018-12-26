/*
 * Calculator.cpp
 *
 *  Created on: 12-Apr-2018
 *      Author: Madhukar
 */

#include "Calculator.h"
#include<iostream>
#include<vector>
using namespace std;

int index=0;
Calculator::Calculator() {
	// TODO Auto-generated constructor stub

}

Calculator::~Calculator() {
	// TODO Auto-generated destructor stub
}


double Calculator::term(){
double outT;

return outT;
}




double Calculator::expression(){
	double outE;

	outE = term();
	if(ou)

}


double Calculator::factor(){

	double outF;
	string x = exp[index];
	if(isdigit(x[index])){
		outF = std::stoi(x);
	}else if(x[index]=='('){

outF = expression();
	}
	return outF;

}
