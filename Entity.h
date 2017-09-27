//Project: Make a working videogame
//File: Define the entity class and the pixel class which are at the base of displaying things to the screen and moving them around
//Last Updated on: 05/13/2017
//             by: Cameron Rutherford

#ifndef ENTITY_
#define ENTITY_

#include <vector>
#include <iostream>
#include <string>

#define SCREEN_WIDTH 80 //used as the size of the screen. changing this changes the dimensions of the game
#define SCREEN_HEIGHT 20 //used to make some places where they are used more obvious

using namespace std;

class Entity;
class Pixel;

class Pixel {
private:
	int * x_pos; //points to the base x position of the entity
	int * y_pos; //points to the base y position of the entity
	int x_offset; //x offset of the pixel from the pointed position
	int y_offset; //y offset of the pixel from the pointed position
	char pixel; //character of the pixel to be printed
public:
	Pixel(int, int, char, Entity); //Default constructor for pixel that takes the x and y offset of the pixel to be printed
	int get_x() { return *x_pos + x_offset; }; //Getters and setters for the private variables
	int get_y() { return *y_pos + y_offset; };
	char get_char() { return pixel; };
	void set_x_offset(int x) { x_offset = x; }
	void set_y_offset(int y) { y_offset = y; }
	void set_char(char c) { pixel = c; }
};

class Entity {
private:
	int moves = 0; //keeps track of the moves specifically for the player
	bool dead = false; //checks to see if the entity is dead, specifically for enemies
	string WhatAmI; //used to figure out if it is a player, enemy or environment
public:
	string whatAmI() { return WhatAmI; } //returns what the thing is (i.e. "Environment","Player","Enemy")
	int * x_position; //this stores the x coord of the bottom left of the entity
	int * y_position; //this stores the y coord of the bottom left of the entity
	int prev_x; //used to keep track of the previos position of the entity in case you cannot move in a certain direction
	int prev_y;
	Entity(int, int); //custom constructor for entity that takes the x and y values for the entity
	vector<Pixel> pixels;
	int * get_x_position(); //getters and setters for the positions
	int * get_y_position(); //don't know why they aren't defined here but they really should be...
	Entity * getEnt() { return this; } //returns a pointer to the entity so that when you change the entity, you can change it easily on the screen
	void update() { prev_x = *x_position; prev_y = *y_position; if (WhatAmI == "Player") { moves++; } } //either updates the previous position if the move was "allowed"
	void revert() { *x_position = prev_x; *y_position = prev_y; } //or reverts the move as it was deemed "illegal"
	bool operator==(Entity &other); //overloading the == operator to check for intersection, a.k.a equality of two entities
	int getMoves() { return moves; }; //getter for the moves
	void decreaseMoves() { moves--; } //decreases the move count if specifically necessary
	void kill() { dead = true; } //sets the state of the entity to dead
	bool isdead() { return dead; } //determines whether the entity is dead or not
protected:
	void Iam(string WhatAmI) { this->WhatAmI = WhatAmI; } //is used in all the things that are Entities to identify what they are
														  //I tried to use polymorphism here but it broke too many other things
};

#endif