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

struct StackFrame{
	string data;
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

};

class Stack {
public:
	Stack();
	Stack(const Stack& other);
	Stack& operator=(const Stack& other);
	void push(string s);
	string pop();

	~Stack();
	bool empty() const;
	static int stacks;
private:
	StackFrame* top;
};

#endif /* SRC_STACK_H_ */
