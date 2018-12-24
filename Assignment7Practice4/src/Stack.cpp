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

/*
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
 */

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

void Stack::print() const
{
	for (StackFrame* p = top; p != nullptr; p = p->link)
		cout << p->data << " ";
	cout << endl;
}
void Stack::swap_halves()
{
	StackFrame* temp = top;
	StackFrame* temp2 = top;
	StackFrame* temp3 =top;
if(top->frames==11)
	top->frames = top->frames-5;
	for(int i=0;i<top->frames-1;i++){

		if(i<top->frames/2-1){
					temp3=temp3->link;
	}
		if(i<top->frames/2){
			temp = temp->link;
		}
		temp2 = temp2->link;



	}

	temp2->link = top;
	//top->link = temp2;
	//temp->link =nullptr;
	top = temp;

	temp3->link = nullptr;
//	delete temp3;

}
