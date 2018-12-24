/*
 * Stack.cpp
 *
 *  Created on: 11-Mar-2018
 *      Author: Madhukar
 */
#include <stdexcept>
#include "Stack.h"
#include <iostream>


int StackFrame::frames = 0;

int Stack::stacks = 0;
Stack::Stack() :top(nullptr) {
	// TODO Auto-generated constructor stub
	stacks++;
}

string Stack::pop(){
	string x="";
	if (empty()) throw logic_error("Popping empty stack");
	x = top->data;
	StackFrame* temp;
	temp = top;
	top = top->link;
	delete temp;
	return x;
}

Stack::Stack(const Stack& other){
	stacks++;
	int len = other.top->frames;
	cout << len << endl;
	StackFrame* temp = new StackFrame();
	temp->data = other.top->data;
	temp->link = other.top->link;
		Stack tempStack1;
for(int i=0;i<len;i++){

	tempStack1.push(temp->data);
	cout<<temp->data<<endl;
	temp = temp->link;

}
for(int i=0;i<len;i++){
string tempPop = tempStack1.pop();
cout<<tempPop<<endl;
	this->push(tempPop);

}
}

/*	StackFrame* temp2 = new StackFrame();
temp2->data = temp->data;
cout<<"temp.data   "<<temp->data<<endl;
temp2->link = temp->link;
top = temp2;*/

void Stack::push(string s){
	StackFrame* x = new StackFrame();
	x->data = s;
	x->link = top;
	top = x;

}

Stack::~Stack() {
	while (!empty()) pop();
}

bool Stack::empty() const
{
	return top == nullptr;
}
Stack& Stack::operator=(const Stack& other){

	if(this->top!=nullptr)
		top->~StackFrame();
	int len = other.top->frames;
			StackFrame* temp = new StackFrame();
	temp->data = other.top->data;
		temp->link = other.top->link;
			Stack tempStack1;
	for(int i=0;i<len;i++){

		tempStack1.push(temp->data);
		temp = temp->link;

	}
	for(int i=0;i<len;i++){
	string tempPop = tempStack1.pop();
		this->push(tempPop);

	}
	tempStack1.~Stack();
	stacks--;
	return *this;
}
