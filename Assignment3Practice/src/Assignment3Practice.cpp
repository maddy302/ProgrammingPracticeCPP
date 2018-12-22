//============================================================================
// Name        : Assignment3Practice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

/**
   Computes the average of all nonnegative elements in the given array.
   @param a an array of integers
   @param alen the number of elements in a
   @return the average of all nonnegative elements in a, or 0 if there are none.
*/
double nnavg(int a[], int alen)
{

	double pavg = 0;
	int count=0;
	for(int i=0;i<alen;i++){
		if(!(a[i]<0)){
			count++;
			pavg = pavg + a[i];
		}
	}

	if(count == 0)
		return 0;
	else
	return pavg/count;

}


/**
   Swaps the third and last value of a.
   For example, if a is {3, 1, 4, 1, 5, 9, 2, 6}
   after calling this method it is {3, 1, 6, 1, 5, 9, 1, 4}.
   If the array has length < 3, do nothing.
   @param a a vector of integers
*/
void swap3last(vector<int>& a)
{
	int temp =0;
	int positionToSwap = 3;
	if(a.size()>=3){
		temp = a.at(positionToSwap-1);
		a[positionToSwap-1] = a.at(a.size()-1);
		a[a.size()-1] = temp;

	}

}

/**
   Replaces each element in an array with the sum of itself and the
   elements preceding it.

   For example { 1, 2, 3, 4 } turns into { 1, 3, 6, 10 }

   Do not declare any arrays or vectors.
   @param a an array
   @param n the length of the array
*/

void precedingsum(double a[], int n)
{

	for (int i=1;i<n;i++){

		a[i] = a[i]+a[i-1];
		cout<<a[i]<<endl;
	}

}

//*********************************************************************************
/**
   Return a string that mixes the characters in the string a
   with the characters in b reversed. For example,
   intertwine("Fred", "Mary") yields "FyrreadM".

   If one string is longer than the other, append the unused
   characters (in reverse order if the second string is longer).
   intertwine("Sue", "Peggy") yields "SyugegeP".
*/
string intertwine(string a, string b)
{
	string c="";
	//iterator  ritb = b.rbegin();
	//iterator  ita = a.begin();

	/*while(*ita != "\0" || *ritb != "\0"){
		c.append(*ita,*ritb);
		ita++;
		ritb--;
	}*/
	int sizeA = a.size();
	int sizeB = b.size();
	int max = 0;
	//char emp = '';
	if(sizeA>=sizeB)
		max = sizeA;
	else
		max = sizeB;

	for (int i=0;i<max;i++){
		if(sizeA>sizeB){
		if(i<sizeB){
			//c.append(a.at(i),b.at(sizeB-i-1));
			c.append(1,a.at(i));
			c.append(1,b.at(sizeB-i-1));
		}
		else{
			c.append(1,a.at(i));
		}

	}
		else if(sizeA<sizeB){
			if(i<sizeA){
				//c.append(a.at(i),b.at(sizeB-i-1));
							c.append(1,a.at(i));
							c.append(1,b.at(sizeB-i-1));
			}
			else{
				c.append(1,b.at(sizeB-i-1));
			}
		}
		else{
			//c.append(a.at(i),b.at(sizeB-i-1));
										c.append(1,a.at(i));
										c.append(1,b.at(sizeB-i-1));		}
	}
return c;
}



//IGNORESPACE false
/**
   This program reads in the name of a file from stdin.
   Then it opens the file and reads all lines of the file.
   Each line has the form

   label abbreviation value

   The label and abbreviation are nonempty strings without spaces.
   The value is a floating-point number.

   Print out the label and abbreviation with the smallest and
   largest value, in a left-justified, field of width 50,
   followed by the value in a right-justified field of width 10, with
   three digits after the decimal point.
*/



int main() {
	/*cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	int alen;
	double avg=0;
	cout<<"Enter the length of the array"<<endl;
	cin>>alen;
	int a[alen];
	cout<<"Enter the "<<alen<<" integers"<<endl;
	for(int i=0;i<alen;i++){
		cin>>a[i];
	}
	//avg = nnavg(a,alen);


	cout<<"the average is "<<avg<<endl;*/

//*********************************************************************************

/*
	vector<int> a;
	a = {1,6,7,8,9};
	swap3last(a);
	for(int i=0;i<a.size();i++){
		cout<<a[i]<<endl;
	}
*/
//*********************************************************************************
/*
	int alen;
		double avg=0;
		cout<<"Enter the length of the array"<<endl;
		cin>>alen;
		double a[alen];
		cout<<"Enter the "<<alen<<" integers"<<endl;
		for(int i=0;i<alen;i++){
			cin>>a[i];
		}

		precedingsum(a,alen);*/

//**********************************************************************************
/*	string a="qwer",b="zxcvAB";
	//getline(cin,a);
	//getline(cin,b);
	string c = intertwine(a,b);
	cout<<c;

	return 0;*/
//**********************************************************************************


	   cout << "Input file:" << endl;
	   string input_file;
	   input_file = "C:/Users/Madhukar/CPP/FileIO/src/abc.txt";
	   ifstream in(input_file);
	   float value[20];
	   	   string label[20];
	   	   string abbr[20];
	   	   float a;
	   	   int max=0,min=RAND_MAX;
	   	   int index=0;
	   	   char b,c;
	   in.open(input_file);
	   while(in.eof()){
		   in>> b >> c >>a;
		   label[index] = b;
		   abbr[index] = c;
		   value[index] = (a);

		   if( a> max){
			   max = index;
		   }
		   if(a<min)
		   {
			   min = index;
		   }
		   index++;
	   }

	   cout<<left<<setw(50)<<abbr[min]<<" "<<label[min];
	   cout<<right<<setw(10)<<value[min]<<endl;
	   cout<<left<<setw(50)<<abbr[max]<<" "<<label[max];
	   cout<<right<<setw(10)<<value[max]<<endl;
	   in.close();
	   return 0;

}
