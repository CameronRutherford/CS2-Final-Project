//Project: Make a working videogame
//File: Define the entity class and the pixel class functions which are at the base of displaying things to the screen and moving them around
//Last Updated on: 05/13/2017
//             by: Cameron Rutherford

#include "Entity.h"

Pixel::Pixel(int x, int y, char pixel, Entity thing) //Default constructor for pixel that takes the x and y offset of the pixel to be printed
{
	this->pixel = pixel;
	x_offset = x;
	y_offset = y;
	x_pos = thing.get_x_position();
	y_pos = thing.get_y_position();
}

Entity::Entity(int x, int y) //custom constructor for entity that takes the x and y values for the entity
{
	x_position = new int(x);
	y_position = new int(y);
	prev_x = *x_position; 
	prev_y = *y_position;
}


int * Entity::get_x_position()
{
	return x_position;
}

int * Entity::get_y_position()
{
	return y_position;
}

bool Entity::operator==(Entity & other) //overloading the == operator to check for intersection, a.k.a equality of two entities
{
	for (unsigned i = 0; i < pixels.size(); i++) { //Look through all the pixels of this Entity
		for (unsigned j = 0; j < other.pixels.size(); j++) { //Look through all the pixels of other Entity
			if (pixels.at(i).get_x() == other.pixels.at(j).get_x() &&
				pixels.at(i).get_y() == other.pixels.at(j).get_y()) {
				return true; //if they intersect at any point, say they intersect and return true
			}
		}

	}
	return false;
}
