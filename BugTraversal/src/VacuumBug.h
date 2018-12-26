/*
 * VacuumBug.h
 *
 *  Created on: 26-Feb-2018
 *      Author: Madhukar
 */

#ifndef SRC_VACUUMBUG_H_
#define SRC_VACUUMBUG_H_

class VacuumBug {
private:
int x,y,regionWidth,regionHeight,direction;
public:
	VacuumBug(int region_width, int region_height);
	void move();
	int get_x() const;
	int get_y() const;
};

#endif /* SRC_VACUUMBUG_H_ */
