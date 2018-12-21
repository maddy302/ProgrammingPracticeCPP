#include <map>
#include <string>
#include<iostream>
#include "WordMap.h"

using namespace std;

WordMap::WordMap() {}

WordMap::~WordMap() {
	//wordM.clear();

}

int WordMap::get_count(const string text) const
{
    /***** Complete this function. *****/
	return wordM.at(text).get_count();
}

void WordMap::insert(const string text)
{
	steady_clock::time_point start = steady_clock().now();
    /***** Complete this function. *****/
	if(wordM.find(text) == wordM.end())
	{
		pair<string,Word> wordX(text, Word(text));
		wordM.insert(wordX);
	}
	else
	{
		wordM.at(text).increment_count();
	}
	steady_clock::time_point end_time = steady_clock().now();
	increment_elapsed_time(start,end_time);
}

map<string, Word>::iterator WordMap::search(const string text)
{
    /***** Complete this function. *****/
	map<string, Word>::iterator it;
	steady_clock::time_point start = steady_clock().now();
	it = wordM.find(text);
	if(text=="democracy"){
		cout<<"blah blah"<<endl;
	}
	steady_clock::time_point end_time = steady_clock().now();
		increment_elapsed_time(start,end_time);
	return it;
}

int WordMap::size(){
	return wordM.size();
}
