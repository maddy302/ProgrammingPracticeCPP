/*
 * Calculator.cpp
 *
 *  Created on: 11-Apr-2018
 *      Author: Madhukar
 */

#include "Calculator.h"
#include<sstream>
int Calculator::openParanthesis = 0;
int Calculator::closeParanthesis = 0;
Calculator::Calculator() {
	// TODO Auto-generated constructor stub

}



Calculator::~Calculator() {
	// TODO Auto-generated destructor stub
}

void Calculator::setInput(char temp){
	this->input = temp;
}

char Calculator::getInput()
{
	return this->input;
}

const string& Calculator::getCompleteExp() const {
	return completeExp;
}

void Calculator::setCompleteExp(const string& completeExp) {
	this->completeExp = completeExp;
}

double Calculator::getOutput() const {
	return output;
}

void Calculator::setOutput(double output) {
	this->output = output;
}

const stringstream& Calculator::getStream() const {
	return stream;
}

/*void Calculator::setStream(const stringstream& stream) {
	this->stream = stream;
}*/

void Calculator::clearStream(){
	stream.clear();

}

double Calculator::factor(){
	char c;
	double outFactor=0;

	if(this->getInput()){
		c = getInput();
		setInput(0);
	}else{
		stream >> c;
	}
	if(c=='('){
		openParanthesis++;
		outFactor = expression();
		stream>>c;
		/*if(c!=')'){
			throw "***** Missing )";
		}
		else{
			closeParanthesis++;
			stream>>c;
			stream.unget();
			//stream.unget();
			if(c==')'){
				closeParanthesis++;
				if(openParanthesis<closeParanthesis ){
					throw "****** Unexpected )";
				}else{
					closeParanthesis--;
				}
			}
		}*/
	}
	else if( c>=48 && c<=57){

		stream.unget();
		stream>>outFactor;
		//return outFactor;
	}else{
		throw "********* Unexpexted "+c;
	}


	return outFactor;
}


double Calculator::expression(){
//initial landing from main method
	output = term();//eventually returns a factor

	while(!stream.eof()){
		//output = term();
		char c;
		stream>>c;//check for the operator after the factor
		double t=0;
		//evaluate the coressponding output
		if(c=='/'){
			stream.unget();
			output = term();
		}
		else if(c=='*'){
			stream.unget();
			output = term();
		}
		else if(c=='+'){
			t = term();
			output = output+t;
		}else if(c=='-'){
			t = term();
			output = output-t;
		}/*else if(c=='*'){
			stream.unget();
			output = term();
		}*//*else if(c=='/'){
			stream.unget();
			output = term();
		}*/
	}
	return output;
}

double Calculator::term(){

	double outTerm=0;
	outTerm = factor();
	char s;
	while(!stream.eof()){

		stream>>s;


		if(s=='*'){

			outTerm = outTerm*factor();
		}else if(s=='/'){
			double d = factor();
			if(d==0){
				throw "Division by zero";
			}else{
				outTerm = outTerm/d;
			}
		}else if(s=='-'){
			stream.unget();
			return outTerm;
		}else if(s=='+'){
			stream.unget();
			return outTerm;
		}else if(s=='%'){
			throw "********unexpected %";

		}

	}

	return outTerm;
}

