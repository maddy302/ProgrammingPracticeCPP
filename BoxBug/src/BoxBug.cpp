/*
 * BoxBug.cpp
 *
 *  Created on: 26-Feb-2018
 *      Author: Madhukar
 */

#include "BoxBug.h"

BoxBug::BoxBug(int initial_x, int initial_y, int box_width, int box_height) {
	// TODO Auto-generated constructor stub

	x = initial_x;
	y = initial_y;
	width = box_width ;
	height = box_height;
	 xmax = width-1;
	 xmin = 0;
	 ymax = height-1;
	 ymin = 0;
}

void BoxBug::move() {

	if(direction == 45){
		x = x + 1;
		y = y + 1;
		if(x == xmax && y== ymax){
			direction = -135;
		}else if(x == xmax){
			direction = 135;
		}else if(y == ymax){
			direction = -45;
		}


	}
	else if(direction == 135){
		x = x -1;
		y = y+1;
		if(x == xmin && y==ymax){
			direction = -45;
		}else if(x == xmin){
			direction = 45;
		}else if(y==ymax){
			direction = -135;
		}
	}
	else if(direction == -135){
		x = x -1;
		y = y-1;
		if(x == xmin && y == ymin){
			direction = 45;
		}else if(x == xmin){
			direction = -45;
		}else if(y== ymin){
			direction = 135;
		}
	}
	else if(direction == -45){
		x = x+1;
		y = y-1;
		if(x == xmax && y==ymin){
			direction = 135;
		}else if(y == ymin){
			direction =45;
		}else if(x == xmax){
			direction = -135;
		}
	}

}

int BoxBug::get_x() const {
return x;
}

int BoxBug::get_y() const {
return y;
}
