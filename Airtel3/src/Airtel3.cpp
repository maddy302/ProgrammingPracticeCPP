//============================================================================
// Name        : Airtel3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
//#include <chrono>
using namespace std;

int main() {
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	//cout<<"enter the lenght of the array"<<endl;
	long n=0,countOdd=0,countEven=0,subArraysize=4,totalSubarray=0;
	std::ios::sync_with_stdio(false);
	cin>>n;
	//cout<<"enter the array"<<endl;
	//n = 4;
	long a[n];
	//std::ios::sync_with_stdio(false);
	//long a[4] = {1,2,1,2};
	for(long i=0;i<n;i++){
		cin>>a[i];
		a[i]=a[i]%2;
		if(i>0){
			if(a[i-1]+a[i]==1){
				totalSubarray++;
			}
		}
	//cout<<"subbarey of size 2 is "<<totalSubarray;
	}
	//steady_clock::time_point x = steady_clock::now();
//	for(long j=0;subArraysize<=n;subArraysize=subArraysize*2){
	for(long j=0;subArraysize<=n;subArraysize=subArraysize+2){
		long iterations = n-subArraysize+1;
		for(long i=0;i<iterations;i++){
			long index = i;
			for(long k=i;k<subArraysize+i;k++){
				//if(a[k]%2==0 && a[k]!=0 && !(a[k]<0))
				if(a[k]%2==0 )
					countEven++;
				//if(a[k]%2==1 && a[k]!=0 && !(a[k]<0))
				if(a[k]%2==1)
					countOdd++;
				//index++;
			}
			if(countOdd == countEven&& countEven!=0){
				totalSubarray++;
//cout<<"Subarraay of "<<subArraysize<<" is "<<totalSubarray<<endl;

			}
			countEven=0;
					countOdd=0;


		}
		countEven=0;
		countOdd=0;
	}

	//cout<<"total sub array are "
	cout<<totalSubarray<<endl;
	//printf("%d",totalSubarray);

	return 0;
}
