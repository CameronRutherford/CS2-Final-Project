//Project: Make a working videogame
//File: Define the environment class constructor that was defined in the header file
//Last Updated on: 05/13/2017
//             by: Cameron Rutherford
#include "Environment.h"

Environment::Environment(int level) : Entity(0,0) //Custom constructor that you pass an int for the assosciated floor layout
{
	Iam("Environment"); //makes sure the environment is identified as an environment

	//this block should always be added to the screen as it makes it so that there is a one "pixel" wide border to the screen
	for (int i = 0; i < SCREEN_WIDTH; i++) {
		pixels.push_back(Pixel(i, 0, '*', *this));
		pixels.push_back(Pixel(i, SCREEN_HEIGHT - 1, '*', *this));
	}
	for (int i = 1; i < 19; i++) {
		pixels.push_back(Pixel(0, i, '*', *this));
		pixels.push_back(Pixel(SCREEN_WIDTH - 1, i, '*', *this));
	}

	//this code can be edited to make it so that the screen actually meaningfully changes, but right now it is just a proof of concept
	switch (level) {
	case 0: 
		pixels.push_back(Pixel(SCREEN_WIDTH - 10, 10, '1', *this));
		break;
	case 1:
		pixels.push_back(Pixel(SCREEN_WIDTH - 10, 10, '2', *this));
		break;
	case 2:
		pixels.push_back(Pixel(SCREEN_WIDTH - 10, 10, '3', *this));
		break;
	case 3:
		pixels.push_back(Pixel(SCREEN_WIDTH - 10, 10, '4', *this));
		break;
	case 4:
		pixels.push_back(Pixel(SCREEN_WIDTH - 10, 10, '5', *this));
		break;
	default:
		break;
	}
}