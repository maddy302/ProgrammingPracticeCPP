/*
 * Element.cpp
 *
 *  Created on: 22-Apr-2018
 *      Author: Madhukar
 */

#include <iostream>
#include "Element.h"

using namespace std;

// Static member variables, which are global to the class.
long Element::copy_count;
long Element::destructor_count;

Element::Element()         : value(0) {}
Element::Element(long val) : value(val) {}

/***** Complete this file. *****/

Element::Element(const Element& other){
	this->value = other.get_value();
	copy_count++;
}
Element::~Element(){
	destructor_count++;
}

long Element::get_copy_count(){
	return Element::copy_count;
}

 long Element::get_destructor_count(){
	return Element::destructor_count;
}

long Element::get_value()const {
	return this->value;
}

 void Element::reset(){
	Element::copy_count = 0;
	Element::destructor_count=0;
}

bool operator ==(const Element& a1, const Element& a2){
	return a1.value==a2.value;
}

bool operator < (const Element& a1, const Element& a2){
	return a1.value<a2.value;
}

bool operator > (const Element& a1, const Element& a2){
	return a1.value>a2.value;
}

ostream& operator <<(ostream& outs,const Element& a1){
	outs<<a1.get_value();
	return outs;
}
