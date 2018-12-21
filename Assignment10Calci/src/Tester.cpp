/*
 * Tester.cpp
 *
 *  Created on: 11-Apr-2018
 *      Author: Madhukar
 */
#include<iostream>
#include <iterator>
#include<list>
#include<string>
#include<sstream>
#include"Calculator.h"
using namespace std;

int main(){


	cout<<"Expression?"<<endl;

	list<string> exp;
	//list<string>::iterator it = exp.begin();
	string exprsn;
	cin>>exprsn;
	//exprsn = "(9+3)/2";
	Calculator calci;
	stringstream Stream;
	//Stream.str(exprsn);
	calci.stream<<exprsn;
	char i;
	Stream>>i;
	calci.stream>>i;
	calci.stream.unget();
	//calci.setInput(i);

	while(i!='.'){
		try{
			double res = calci.expression();
			cout<<res<<endl;

		}catch(const char* s){
			cout<<s<<endl;
		}
		cout<<"Expression?"<<endl;
		cin>>exprsn;
		Stream.clear();
		Stream.str(exprsn);
		calci.clearStream();
		//calci.stream=Stream;
		calci.stream<<exprsn;
		//Stream>>i;
		calci.stream>>i;
		calci.setInput(i);

	}
	cout<<"Done!"<<endl;


	return 0;

}


