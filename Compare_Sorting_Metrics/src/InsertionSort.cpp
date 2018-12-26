/*
 * InsertionSort.cpp
 *
 *  Created on: 22-Apr-2018
 *      Author: Madhukar
 */

#include "InsertionSort.h"
#include "VectorSorter.h"
#include "Sorter.h"


InsertionSort::InsertionSort() : VectorSorter("Insertion sort") {}

/***** Complete this file. *****/
InsertionSort::~InsertionSort(){

}

void InsertionSort::run_sort_algorithm(){
//Element temp();
int sizem = VectorSorter::size-1;
/*for(int i=0;i<=sizem;i++){
	cout<<data[i]<<endl;
}*/
/*for(int i=1;i<=sizem;i++){
	compare_count++;
	if(VectorSorter::data[i]<VectorSorter::data[i-1]){
		int outOfOrderLocation  = i;
	//	temp = VectorSorter::data[i];
		do{
			swap(outOfOrderLocation,outOfOrderLocation-1);
			outOfOrderLocation--;
			compare_count++;
		}while(outOfOrderLocation>0 && VectorSorter::data[outOfOrderLocation]<VectorSorter::data[outOfOrderLocation-1]);
		//swap()
	}
}*/
for(int i=1;i<=sizem;i++){
	compare_count++;
	//if(VectorSorter::data[i]<VectorSorter::data[i-1]){
		int outOfOrderLocation  = i;
	//	temp = VectorSorter::data[i];
		while(outOfOrderLocation>0 && VectorSorter::data[outOfOrderLocation]<VectorSorter::data[outOfOrderLocation-1]){
			swap(outOfOrderLocation,outOfOrderLocation-1);
			outOfOrderLocation--;
			compare_count++;
		}
		//swap()
	//}
}
/*for(int i=1;i<=sizem;i++){
	compare_count++;
	if(VectorSorter::data[i]<VectorSorter::data[i-1]){
		int outOfOrderLocation  = i;
		//temp = VectorSorter::data[i];
		Element temp(data[i].get_value());
		do{
			//swap(outOfOrderLocation,outOfOrderLocation-1);
			data[outOfOrderLocation] = data[outOfOrderLocation-1];
			outOfOrderLocation--;
			compare_count++;
		}while(outOfOrderLocation>0 && VectorSorter::data[outOfOrderLocation-1]>temp);
		//swap()
		data[outOfOrderLocation] = temp;
	}
}*/

}
