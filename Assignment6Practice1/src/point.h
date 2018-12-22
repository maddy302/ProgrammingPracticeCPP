#ifndef POINT_H
#define POINT_H

class Point
{
public:
   Point(int x, int y);
   int x() const;
   int y() const;
private:
   int _x;
   int _y;
};

#endif
