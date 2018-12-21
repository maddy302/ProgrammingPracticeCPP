/*
 * Calculator.h
 *
 *  Created on: 11-Apr-2018
 *      Author: Madhukar
 */
#include <list>
#include <string>
#include <sstream>
using namespace std;
#ifndef SRC_CALCULATOR_H_
#define SRC_CALCULATOR_H_


class Calculator {

public:
	static int openParanthesis;
	static int closeParanthesis;
	Calculator();
	virtual ~Calculator();
	double expression();
	double factor();
	double term();
	Calculator(string);
	string completeExp;
	void setInput(char temp);
	char getInput();
	const string& getCompleteExp() const;
	void setCompleteExp(const string& completeExp);
	double getOutput() const;
	void setOutput(double output);
	const stringstream& getStream() const;
	void setStream(const stringstream& stream);
	void clearStream();
	stringstream stream;
private:

	char input;
	double output;

};

#endif /* SRC_CALCULATOR_H_ */
