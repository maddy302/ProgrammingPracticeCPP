/*
 * Point.h
 *
 *  Created on: 05-Mar-2018
 *      Author: Madhukar
 */

#ifndef SRC_POINT_H_
#define SRC_POINT_H_

class Point
{
public:
   Point();
   Point(int x, int y);
   Point(const Point& other);
   Point& operator=(const Point& other);
   ~Point();
   int x() const;
   int y() const;
private:
   int _x;
   int _y;
};
#endif /* SRC_POINT_H_ */
