/*
 * ShellSortOptimal.cpp
 *
 *  Created on: 22-Apr-2018
 *      Author: Madhukar
 */

#include "ShellSortOptimal.h"
#include "VectorSorter.h"

ShellSortOptimal::ShellSortOptimal() :VectorSorter("Shellsort optimal") {}

/***** Complete this file. *****/
ShellSortOptimal::~ShellSortOptimal(){

}

void ShellSortOptimal::run_sort_algorithm(){

	/* int shell = data.size();
	 vector<int> shellSize;
	 int temp=0;
	 for(int i=0;(3*i+1)<data.size();i++){
		 shellSize.push_back((3*i)+1);
	 }
	 shell = shellSize.pop_back();
	 while(!shellSize.empty() && shell<data.size() ){
		 for(int i = 0;i+shell<data.size();i=i+shell){
			 if(data[i+shell]<data[i]){

				 int outOfOrderLocation = i;
				 do{
					 swap(outOfOrderLocation+shell,outOfOrderLocation);
					 outOfOrderLocation = outOfOrderLocation - shell;
				 }while(outOfOrderLocation>=0 && data[outOfOrderLocation]>data[outOfOrderLocation+shell]);

			 }
		 }
		 shell=shellSize.pop_back();
	 }*/


		 int shell = data.size();
			 vector<int> shellSize;
			 int temp=0;
			 for(int i=0;((3*i)+1)<data.size();i++){
				 shellSize.push_back((3*i)+1);
				// cout<<(3*i)+1<<endl;
				 temp++;
			 }
			 //shell = shellSize.at(temp-1);
			 temp--;
			 shell=0;
			// cout<<"shell :"<<shell<<!shellSize.empty()<<"   "<<temp<<"    "<<data.size()<<endl;
			 while(!shellSize.empty() && shell<data.size() && !(temp<0) ){
				 shell=shellSize.at(temp);
				 for(int i = 0;i+shell<data.size();i=i+shell){
					 compare_count++;
					 if(data[i+shell]<data[i]){

						 int outOfOrderLocation = i;
						 do{
							 swap(outOfOrderLocation+shell,outOfOrderLocation);
							 outOfOrderLocation = outOfOrderLocation - shell;
							 compare_count++;
						 }while(outOfOrderLocation>=0 && data[outOfOrderLocation]>data[outOfOrderLocation+shell]);

					 }
				 }
				 temp--;

			 }
 }
