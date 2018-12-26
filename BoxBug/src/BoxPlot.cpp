/*A bug lives in a box of width w and height h, at an integer position (x, y), 0 ≤ x < w and 0 ≤ y < h. In each move, it moves diagonally until it hits one of the walls or a corner. If it hits a wall, its direction is reflected. If it hits a corner, it turns around. When constructed with a given position, the bug initially moves towards increasing x- and y-positions.

Here is a trace of a bug in a box of width 10 and height 3 when move is called 5 times.

+----------+
|      1 5 |
|     0 2 4|
|        3 |
+----------+*/

#include <iostream>
#include <vector>
#include "BoxBug.h"


using namespace std;

int main()
{
   int width;
   int height;
   int initial_x;
   int initial_y;
   int moves;
   cin >> width >> height >> initial_x >> initial_y >> moves;

   vector<vector<char>> box;
   for (int y = 0; y < height; y++)
   {
      box.push_back(vector<char>());
      for (int x = 0; x < width; x++)
         box[y].push_back(' ');
   }
   BoxBug b(initial_x, initial_y, width, height);
   box[initial_y][initial_x] = '0';
   for (int move = 1; move <= moves; move++)
   {
      b.move();
      box[b.get_y()][b.get_x()] = '0' + (move % 10);
   }
   cout << '+';
   for (int x = 0; x < width; x++) cout << '-';
   cout << '+' << endl;
   for (int y = height - 1; y >= 0; y--)
   {
      cout << "|";
      for (int x = 0; x < width; x++)
      {
         cout << box[y][x];
      }
      cout << "|" << endl;
   }
   cout << '+';
   for (int x = 0; x < width; x++) cout << '-';
   cout << '+' << endl;
}
