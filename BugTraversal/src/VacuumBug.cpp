/*
 * VacuumBug.cpp
 *
 *  Created on: 26-Feb-2018
 *      Author: Madhukar
 */

#include "VacuumBug.h"

VacuumBug::VacuumBug(int region_width, int region_height) {
	// TODO Auto-generated constructor stub
	x = 0;
	y = 0;
	direction =0;
	regionWidth = region_width-1;
	regionHeight = region_height-1;
}

void VacuumBug::move(){


	if(direction==0){
		if(x==regionWidth && y == regionHeight){
			direction = -1;
		}
	else if(x==regionWidth){
			y = y + 1;
			direction =1;
		}
		else{
			x = x + 1;
		}
	}
	else{
		if(x==regionWidth && y == regionHeight){
					direction = -1;
				}
	else if(x==0){
			y = y + 1;
			direction =0;
		}else{
			x = x -1;
		}
	}
}

int VacuumBug::get_x() const{
	return x;
}

int VacuumBug::get_y() const{
	return y;
}


