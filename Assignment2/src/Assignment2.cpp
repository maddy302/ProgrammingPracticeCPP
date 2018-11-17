//============================================================================
// Name        : Assignment2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

/**
 * Computes the smallest of four values.
 */

int min(int a, int b, int c, int d)
{
   int result = a;
   if (b < result) result = b;
   if (c < result) result = c;
   if (d < result) result = d;
   return result;
}

/**
   Computes the average of the middle values of four given values
   (that is, without the largest and smallest value).
   Hint: Use the given min function. You may also want to define a
   max helper function or take advantage of the fact that max can be
   computed from the min of the negative values.
*/

double middle(int a, int b, int c, int d){
	double avg = 0.0;
	int minimum=0,max=0, sum =0;
	minimum = min(a,b,c,d);
	max = min(-a,-b,-c,-d); // get max by converting them to -ve and find minimum
	max = max*-1;//rever the value
	avg = (a+b+c+d-minimum-max)*1.0/2;



	return avg;
}

int main() {
	cout << "Enter any 4 Interger values" << endl; // prints !!!Hello World!!!
	int a,b,c,d;
	cin >>a>>b>>c>>d;
	cout<<"The input was "<<a<<","<<b<<","<<c<<","<<d<<endl;
	cout<<"The average of the middle two is "<<middle(a,b,c,d)<<endl;


	return 0;
}
