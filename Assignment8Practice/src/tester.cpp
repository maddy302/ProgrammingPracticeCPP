/*
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;


void parse_time(string time, int& hours, int& minutes);
class ParseError : public runtime_error
{
public:
   ParseError(const string& what);
};

ParseError::ParseError(const string& what) : runtime_error(what) {}

void parse_time(string time, int& hours, int& minutes)
{  // Implementation without error checking
	   int i = 1;
	 if(time.length()<6)
		 throw out_of_range("out_of_range");

	   if (isdigit(time[i])) {
		   if(((time[i - 1] - '0')*10)+time[i] - '0'<=12 && ((time[i - 1] - '0')*10)+time[i] - '0'!=0){
	      hours = 10 * (time[i - 1] - '0') + time[i] - '0';
	      i++;
	   }
		   else{
		   		   throw range_error("range_error");
		   	   }
	   }
	   else {
	   	      hours = time[i - 1] - '0';
	   	      if(hours ==0){
	   	    	throw range_error("range_error");
	   	      }
	   	   }
	   i += 2;
	   minutes = 10 * (time[i - 1] - '0') + time[i] - '0';
	   if(minutes>59 || minutes < 0){
		   throw range_error("range_error");
	   }
	   i += 2;
	   char x = time[i];
	   if(!isdigit(time[1]) && time.length()>7 )
		   throw ParseError("time not valid: "+time);
	   if(time[i]=='a' || time[i]=='p'){
	   if (time[i] == 'a') {
	      if (hours == 12) hours = 0;
	   } else {
	      if (hours != 12) hours += 12;
	   }
	   }else{
		   throw ParseError("time not valid: "+time);
	   }

}

void test(string time, int h, int m, string e)
{
   int hours = -1;
   int minutes = -1;
   try
   {
      parse_time(time, hours, minutes);
      cout << hours << ":" << minutes << endl;
      if (e == "")
         cout << "Expected: " << h << ":" << m << endl;
      else
         cout << "Expected: " << e << endl;

   }
   catch (ParseError& ex) {
      cout << ex.what() << endl;
      cout << "Expected: ";
      if (e == "") cout << h << ":" << m << endl;
      else cout << e << endl;
   }
   catch (range_error& ex) {
      cout << "range_error" << endl;
      cout << "Expected: ";
      if (e == "") cout << h << ":" << m << endl;
      else cout << e << endl;
   }
   catch (out_of_range& ex) {
      cout << "out_of_range" << endl;
      cout << "Expected: ";
      if (e == "") cout << h << ":" << m << endl;
      else cout << e << endl;
   }
   catch (...)
   {
      cout << "Unexpected exception" << endl;
      cout << "Expected: ";
      if (e == "") cout << h << ":" << m << endl;
      else cout << e << endl;
   }
}

int main()
{
   test("1:23 am", 1, 23, "");
   test("1:23 pm", 13, 23, "");
   test("12:23 pm", 12, 23, "");
   test("12:23 am", 0, 23, "");
   test("1:23 qm", -1, -1, "time not valid: 1:23 qm");
   test("1:23am", -1, -1, "time not valid: 1:23am");
   test("1:23 am ", -1, -1, "time not valid: 1:23 am");
   test("1:23", -1, -1, "out_of_range");
   test("1", -1, -1, "out_of_range");
   test("1:63 am", -1, -1, "range_error");
   test("0:13 am", -1, -1, "range_error");
   test("13:13 am", -1, -1, "range_error");

   return 0;
}
*/

/*

#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;
#include <list>
using namespace std;

*
   Remove the elements at position 0, 2, 4, 6, ..., of the
   linked list.
   Use an iterator.

void removeEvenPositions(list<int>& lst)
{
	list<int>::iterator it;
	int i = 0;
	//cout<<lst.size()<<endl;
	it = lst.begin();
	for(int i=0;i<lst.size();i++){
		it = lst.erase(it);
		it++;

	}

}
void removeEvenPositions(list<int>& lst);

int main()
{
   list<int> nums = { 1, 1, 2, 3, 5, 8, 13, 21, 34 };
   removeEvenPositions(nums);
   copy(nums.begin(), nums.end(),
      ostream_iterator<int>(cout, " "));
   cout << endl;
   cout << "Expected: 1 3 8 21" << endl;
   list<int> nums2 = { 1, 4, 9, 16, 25, 36 };
   removeEvenPositions(nums2);
   copy(nums2.begin(), nums2.end(),
      ostream_iterator<int>(cout, " "));
   cout << endl;
   cout << "Expected: 4 16 36" << endl;
   return 0;
}
*/



#include <list>
#include <iostream>
#include <iomanip>
#include <list>
#include <iterator>
using namespace std;

/**
   You are given an iterator to the beginning of a list and a
   reverse iterator to the end of the list. Using these iterators,
   determine if the second half of the list is a mirror image of the
   first. For example, 1 2 3 4 4 3 2 1 and 1 2 3 4 3 2 1 should pass the test,
   but 1 2 3 4 1 2 3 4 should not.

   Hint: https://stackoverflow.com/questions/15202978/compare-vectortiterator-with-vectortreverse-iterator
*/
/*
bool secondHalfMirrorsFirst(list<int>::iterator begin, list<int>::reverse_iterator rbegin);

int main()
{
   cout << boolalpha;
   list<int> nums = { 1, 1, 2, 3,5, 3, 2, 1, 1 };
   cout << secondHalfMirrorsFirst(nums.begin(), nums.rbegin()) << endl;
   cout << "Expected: true" << endl;
  list<int> nums2 = { 1, 2, 3, 5, 5, 3, 2, 1 };
   cout << secondHalfMirrorsFirst(nums2.begin(), nums2.rbegin()) << endl;
   cout << "Expected: true" << endl;
   list<int> nums3 = { 1, 1, 2, 3, 5, 8, 13, 21, 34 };
   cout << secondHalfMirrorsFirst(nums3.begin(), nums3.rbegin()) << endl;
   cout << "Expected: false" << endl;
   list<int> nums4 = { 1, 1, 2, 3, 4, 2, 1, 1 };
   cout << secondHalfMirrorsFirst(nums4.begin(), nums4.rbegin()) << endl;
   cout << "Expected: false" << endl;
   return 0;
}
bool secondHalfMirrorsFirst(list<int>::iterator begin, list<int>::reverse_iterator rbegin)
{bool status = false;


while (begin != rbegin.base() && begin != (rbegin + 1).base()){
	cout<<"begin "<<*begin<<" ,  rbegin "<<*rbegin;
	rbegin++;
	begin++;
}
list<int>::iterator copy = begin;
int length=0;
while(copy!=rbegin.base()){
length++;
copy++;
}
int i=0;
//cout<<length<<endl;
while(i<length/2){
	//cout<<" Begin is "<<*begin<<" Rbegisadsn is "<<*rbegin<<endl;
	if(*begin==*rbegin)
		status = true;
	else{
		status =false;
		break;
	}
	i++;
	begin++;
	rbegin++;
}
//cout<<status;
	return status;
}
*/



#include <iostream>
#include <list>
#include <vector>
#include <string>


using namespace std;

template<typename I> void swap(I begin, I end);

template<typename C> void print(const C& c)
{
   cout << "{ ";
   for (auto p = c.begin(); p != c.end(); p++) cout << *p << " ";
   cout << "}" << endl;
}

template<typename E> void print(const E* a, int n)
{
   cout << "{ ";
   for (auto i = 0; i != n; i++) cout << a[i] << " ";
   cout << "}" << endl;
}


int main()
{
   int a[] = { 1, 2, 3, 4, 5, 6 };
   swap(a, a + 6);
   print(a, 6);
   cout << "Expected: { 2 1 4 3 6 5 }" << endl;
   vector<string> words = { "Mary", "had", "a", "little", "lamb" };
   swap(words.begin(), words.end());
   print(words);
   cout << "Expected: { had Mary little a lamb }" << endl;
   list<double> numbers = { 1, 0.5, 0.25, 0.125 };
   swap(numbers.begin(), numbers.end());
   print(numbers);
   cout << "Expected: { 0.5 1 0.125 0.25 }" << endl;
   string name = "Wilma";
   swap(name.begin(), name.end());
   cout << name << endl;
   cout << "Expected: iWmla" << endl;

   return 0;
}

/*
  You are given two STL iterators begin and end.

  Complete this template function that swaps neighboring elements
  of the range given by [begin, end). As always, you can assume that
  end is reachable from begin.

  If the length of the range is odd, the last element is unchanged.
*/

template<typename I> void swap(I begin, I end)
{

/*	I iter2;
	end--;
while(begin!=end){
	 iter2 = begin;
	iter2++;
	std::swap(*begin,*iter2);
	if(begin!=end){
		begin++;
	}
		if(begin!=end){
		begin++;
		}
		//iter2++;
}*/
	end--;
	while(begin!=end){
		iter_swap(begin,begin++);
		if(begin!=end)
			begin++;
	}

}


