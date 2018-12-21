#include<iostream>
using namespace std;

void searchSubArray(long* a,long length,long index,long& totalSubarray){

	long subArrayLength = 4,countEven=0,countOdd=0;
	for(;subArrayLength<=index;subArrayLength=subArrayLength+2){
		long iterations = index-subArrayLength+1;
		for(long i=0;i<iterations;i++){
					long index = i;
					for(long k=i;k<subArrayLength+i;k++){
						//if(a[k]%2==0 && a[k]!=0 && !(a[k]<0))
						if(a[k]==0)
							countEven++;
						//if(a[k]%2==1 && a[k]!=0 && !(a[k]<0))
						if(a[k]==1)
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

	}
}

int main1 (){
	long n=0,countOdd=0,countEven=0,subArraysize=2,totalSubarray=0,temp=0;
	cin>>n;
	//long outputArray[n/2];
	long inputArray[n];
	//long totalSubarray=0;
for(long i=0;i<n;i++){
	cin>>temp;
	inputArray[i]=temp%2;
	if(i>0){
		if(inputArray[i-1]+inputArray[i]==1){
			totalSubarray++;
		}
	}
	 searchSubArray(inputArray,n,i+1,totalSubarray);

}
cout<<totalSubarray;

	return 0;
}

