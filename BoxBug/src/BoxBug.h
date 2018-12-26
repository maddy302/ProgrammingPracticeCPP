/*
 * BoxBug.h
 *
 *  Created on: 26-Feb-2018
 *      Author: Madhukar
 */

#ifndef SRC_BOXBUG_H_
#define SRC_BOXBUG_H_

class BoxBug {
	 private: int width, height, x,y,direction=45,xmax,xmin,ymax,ymin;
public:
	 BoxBug(int initial_x, int initial_y, int box_width, int box_height);
	    void move();
	    int get_x() const;
	    int get_y() const;

};

#endif /* SRC_BOXBUG_H_ */
