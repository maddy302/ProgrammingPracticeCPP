/*
 * Stack.h
 *
 *  Created on: 11-Mar-2018
 *      Author: Madhukar
 */

#include <string>
#ifndef SRC_STACK_H_
#define SRC_STACK_H_
using namespace std;
struct StackFrame;

class Stack {
public:
	Stack();
	Stack(const Stack& other);
	Stack& operator=(const Stack& other);
	void push(string s);
	string pop();
	   void swap_halves();
	   void print() const;
	~Stack();
	bool empty() const;
	static int stacks;
private:
	StackFrame* top;
};

struct StackFrame{

	StackFrame* link;
	static int frames;
	StackFrame(){
		frames++;
	}
	StackFrame(const StackFrame& other){
		frames++;
	}
	~StackFrame() {
		link = nullptr;
		data="666";
		frames--;
	}


private:
	string data;
	friend void Stack::push(string);
	friend void Stack::print() const;
	friend string Stack::pop();

};



#endif /* SRC_STACK_H_ */
