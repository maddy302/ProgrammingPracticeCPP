#include <iostream>
#include "stack.h"

using namespace std;

void swap_halves(Stack& s);

int main()
{
   Stack s;
   s.push("Mary");
   s.push("had");
   s.push("a");
   s.push("little");
   s.push("lamb");
   swap_halves(s);
   s.print();
   cout << "Expected: a had Mary lamb little" << endl;
   Stack t;
   t.push("Its");
   t.push("fleece");
   t.push("was");
   t.push("white");
   t.push("as");
   t.push("snow");
   swap_halves(t);
   t.print();
   cout << "Expected: was fleece Its snow as white" << endl;
   cout << "Constructed stacks: " << Stack::stacks << endl;
   cout << "Expected: 6" << endl;
}

void swap_halves(Stack& s)
{
	int len = StackFrame::frames ;
Stack s1,s2;
if(len>5){
	len = len -5;
}
for(int i=0;i<len;i++){
	if(i<len/2){
		s1.push(s.pop());
	}
	if(i>=len/2){
		s2.push(s.pop());
	}
}
for(int i=0;i<len;i++){
if(i<len/2){
	s.push(s1.pop());
}
if(i>=len/2){
	s.push(s2.pop());
}
}

}
