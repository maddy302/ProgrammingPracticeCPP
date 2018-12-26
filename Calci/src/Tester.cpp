/*
 * Tester.cpp
 *
 *  Created on: 12-Apr-2018
 *      Author: Madhukar
 */


#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){

	string expression="12+3";
	cin>>expression;

string::iterator it = expression.begin();
vector<string> expInVector;

string tempN="";

while(it!=expression.end()){

	if(isdigit(*it)){
		string x(1,*it);
		tempN = tempN.append(x);
	}else{
		if(tempN.size()!=0){
			expInVector.push_back(tempN);
			tempN="";
		}
		string tempS(1,*it);
		expInVector.push_back(tempS);

	}
	it++;
}
expInVector.pop_back();
for(int i=0;i<expInVector.size();i++){
	cout<<expInVector[i]<<endl;
}

	return 0;

}
