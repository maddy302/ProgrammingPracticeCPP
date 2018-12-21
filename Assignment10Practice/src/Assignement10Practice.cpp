/*
 * Assignement10Practice.cpp
 *
 *  Created on: 10-Apr-2018
 *      Author: Madhukar
 */
#include <string>
#include <iostream>
#include <vector>

using namespace std;
/**
   Return true if the given string contains at least two
   different characters. Use recursion. Do not use loops.
   Hint: If str[0] is not the same as str[1], you have
   your answer. Otherwise, look at str.substr(1) (the substring of str
   from position 1 to the end).
*/
bool someDifferent(string);
string shuffle(string, string);
string digits(string str);
int altSumHelper(vector<int> v,int index);
int altSum(vector<int> v);


 int main(){

/*	 string str = "aaka";
	bool status = someDifferent(str);
cout<<"status is "<<status;
	return 0;*/

	 /*string a = "Fred";
	 string b = "Wilma";
	 a= shuffle(a,b);
	 cout<<a;*/

/*string str = "01a34d";
cout<<digits(str);*/

	 vector<int> x = {1,3,2,1,3};
	 int sum =altSum(x);
	 cout<<sum;

}

/* bool someDifferent(string str)
 {
	 bool status = false;
int i=0,j=1;
int length = str.length();

if(str[0]!=str[1]&&str.length()>1){
	return true;
}else if(str[0]==str[1]&&str.length()>1){

status = someDifferent(str.substr(1));
}else{
	return false;
}

	 return status;
 }*/


 /**
    Shuffle two strings by alternating characters from them. If one string
    runs out before the other, just pick from the longer one.
    For example, shuffle("Fred", "Wilma") is "FWrieldma".
    Use recursion. Do not use loops.
    Hint: str.substr(1) is the substring of str from position 1 to
    the end.
 */

 string shuffle(string a, string b)
 {
int lena = a.length();
int lenb = b.length();
size_t z =1;
string x="";
if(lenb>0 && lena>0){
x.append(z,a[0]);
x.append(z,b[0]);
x.append(shuffle(a.substr(1),b.substr(1)));
return x;
//return a[0]+b[0];
 }else{
if(b.length()>a.length())
	 return a+b;
else
	return b+a;
 }

 }


 /**
    Given a string, return a string of all digits contained in it.
    Use recursion. Do not use loops.
    A digit is a character between '0' and '9' inclusive.
    Hint: str.substr(1) is the substring of str from position 1 to
    the end.
 */

 string digits(string str)
 {
string z = "";
size_t x;
if(str.length()>1){
	if(str[0]>47 && str[0]<58 ){
		z = z + str[0];
	}
	z = z + digits(str.substr(1));
return z;
}else{
	if(str[0]>47 && str[0]<58){
	return str;
	}else{
		return "";
	}
}

 }

 int altSumHelper(vector<int> v,int index)
 {
	 int sum = 0;
	//int k=0;
	 if(v.size()>0){
	 if(index!=v.size()-1){
		 if(index%2==1)
		 sum =v.at(index)- altSumHelper(v,++index);
		 else
			 sum =v.at(index)+ altSumHelper(v,++index);
		 return sum;
	 }else{
		 return v.at(index);
	 }
	 }
 }

 /**
    Given a vector of integers, return the alternating sum
    v[0] - v[1] + v[2] - v[3] + ...
    If the vector is empty, the alternating sum is zero.
    Use a recursive helper method. Do not use loops.

 */
 int altSum(vector<int> v)
 {
    return altSumHelper(v, 0);
 }

