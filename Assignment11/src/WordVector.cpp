#include <iostream>
#include <vector>
#include <string>
#include "WordVector.h"

using namespace std;

WordVector::WordVector() {}

WordVector::~WordVector() {
	//wordV.clear();

}

int WordVector::get_count(const string text) const
{
	int position = find(text,0,wordV.size());
	if(position <0){
		return 0;
	}else{
		return wordV[position].get_count();
	}
    /***** Complete this function. *****/
}

void WordVector::insert(const string text)
{
    /***** Complete this function. *****/
	steady_clock::time_point start = steady_clock().now();
	vector<Word>::iterator begin,end;
	//string x;
	begin = wordV.begin();
	end = wordV.end();
	/*while(begin!=end){
		if(((*begin).get_text()).compare(text)<0){
			begin++;
		}else{
			wordV.insert(begin,text);
			break;
		}
	}
	if(begin==end){
		wordV.push_back(text);
	}*/
	int position = find(text,0,wordV.size()-1);
	if(position<0){
		Word x(text);
		/*while(begin!=end){
				if(((*begin).get_text()).compare(text)<0){
					begin++;
				}else{
					cout<<"Inserted "<<x.get_text();
					wordV.insert(begin,x);
					break;
				}
			}
			if(begin==end){
				wordV.push_back(x);
			}*/
		position = (-1) * position;
		wordV.insert(wordV.begin() + position - 1, x);
		//wordV.push_back(x);
	}else{
		(*(begin+position)).increment_count();
	}
	steady_clock::time_point end_time = steady_clock().now();
	increment_elapsed_time(start,end_time);


}

vector<Word>::iterator WordVector::search(const string text)
{
    /***** Complete this function. *****/
	vector<Word>::iterator pointer = wordV.begin();
	/*while(pointer!=wordV.end()){
		if((*pointer).get_text().compare(text)==0){
			break;
		}else{
			pointer++;
		}
	}*/
	/*vector<string>::iterator mid = wordV.begin()/2;
	while(pointer!=pointer/2){

	}*/
	if(text=="democracy"){
		cout<<"blah blah"<<endl;
	}
	steady_clock::time_point start = steady_clock().now();
	int position = find(text,0,wordV.size()-1);
	if(position<0){
		pointer = wordV.end();
		position = 0;
	}

	else
	{

	}
	steady_clock::time_point end_time = steady_clock().now();
		increment_elapsed_time(start,end_time);

	return pointer + position;


}

int WordVector::find(const string text, int low, int high) const
{
	if(low<=high){
		int mid = (low+high)/2;
		if(wordV[mid].get_text() == text){
			return mid;
		}else if(wordV[mid].get_text() < text)
		{
			high = mid-1;
			return find(text,low,mid-1);
		}else{
			low = mid+1;
			return find(text,mid+1,high);
		}
	}else{
		return -(low+1);
	}

}

int WordVector::size(){
	return wordV.size();
}

Word WordVector::operator [](const int index){
return wordV[index];
}
