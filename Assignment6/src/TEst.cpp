#include <vector>
#include <iostream>
#include "Book.h"

int main1()
{
	Book b1("ISBN","Last","FIrst","Title","categpry");
	vector<Book> x;
	cout<<x.size()<<endl;
	x.push_back(b1);
	cout<<x.size()<<endl;
}
