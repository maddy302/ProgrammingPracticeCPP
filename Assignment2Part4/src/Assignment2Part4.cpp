//============================================================================
// Name        : Assignment2Part4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Refer below
//============================================================================
/*
  The Chevalier de Blasé, a notorious 17th century gambler, wanted to
  know whether he had higher odds of winning a dice game with four
  dice, where a win meant a pair of 5s and a pair of 6s, or a game
  with six dice, where a win meant four sixes (and two dice
  that are not a six).

  Help him out by writing a simulation that "throws" virtual dice
  with a random number generator.
*/

/*
  Return a random number between 1 and 6.
*/
#include <iostream>
using namespace std;

int die_toss()
{
   return 1 + rand() % 6;
}

/*
  Return true if you got a pair of 5s and 6s.
*/
int game1_wins(int a, int b, int c, int d)
{ bool win = false;
if(a*b*c*d==900)
	win = true;

return win;
}

/*
  Return true if you got four 6s.
*/
int game2_wins(int a, int b, int c, int d, int e, int f)
{	bool win = false;
	int count =0;

/*if( (a*b*c*d*e*f)/(6*6*6*6)<=25 && (a*b*c*d*e*f)/(6*6*6*6)>=1 && (a*b*c*d*e*f)%(6*6*6*6)==0 )*/
	if(a==6) count++;
	if(b==6) count++;
	if(c==6) count++;
	if(d==6) count++;
	if(e==6) count++;
	if(f==6) count++;
	if(count==4)
	win = true;
return win;
}

/*
  Play game 1 for the given number of iterations and return the
  number of wins.
*/
int game1(int iterations)
{int wins = 0,result=0;
	for(int i=0;i<iterations;i++){
		result = game1_wins(die_toss(),die_toss(),die_toss(),die_toss());
		wins = wins + result;
	}

	return wins;
}

/*
  Play game 2 for the given number of iterations and return the
  number of wins.
*/
int game2(int iterations)
{
	int wins = 0,result=0;
		for(int i=0;i<iterations;i++){
			result = game2_wins(die_toss(),die_toss(),die_toss(),die_toss(),die_toss(),die_toss());
			wins = wins + result;
		}

		return wins;
}


int main() {
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	srand(42);
	   cout << game1(1000) << endl;
	   cout << game2(1000) << endl;
	   cout << game1(10000) << endl;
	   cout << game2(10000) << endl;
	   cout << game1(100000) << endl;
	   cout << game2(100000) << endl;
	   cout << game1(1000000) << endl;
	   cout << game2(1000000) << endl;
	return 0;
}
