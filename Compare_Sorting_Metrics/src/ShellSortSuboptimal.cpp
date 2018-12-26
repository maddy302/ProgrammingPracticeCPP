/*
 * ShellSortSuboptimal.cpp
 *
 *  Created on: 22-Apr-2018
 *      Author: Madhukar
 */

#include "ShellSortSuboptimal.h"

ShellSortSuboptimal::ShellSortSuboptimal() : VectorSorter("Shellsort suboptimal") {}

/***** Complete this file. *****/
ShellSortSuboptimal::~ShellSortSuboptimal(){

}
 void ShellSortSuboptimal::run_sort_algorithm(){

	 int shell = data.size();
	 shell = shell/2;

	 while(shell>0){
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
		 shell=shell/2;
	 }
 }
