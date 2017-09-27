//Project: Make a working videogame
//File: Define the Direction class functions defined in the header file
//Last Updated on: 05/13/2017
//             by: Cameron Rutherford
#include "GeneratingDirection.h"
#include <ctime>
#include <iostream>

char Direction::GetDirection(bool reset)
{
	static bool up = false;
	static bool down = false;
	static bool left = false;
	static bool right = false;

	if (reset == true) { //reset all the directions if necessary
		up = false;
		down = false;
		left = false;
		right = false;
	}

	srand(time(NULL)); //seed the random number generator

	for (;;) { //this could easily be a while true loop but I figured this looked cool and I wanted to try it
		int x = rand() % 5;
		switch (x) { //return the appropriate direction. If you have already given it, try again
		case 0:
			if (!down) {
				down = true;
				return 'd';
			}
			break;
		case 1:
			if (!up) {
				up = true;
				return 'u';
			}
			break;
		case 3:
			if (!left) {
				left = true;
				return 'l';
			}
			break;
		case 4:
			if (!right) {
				right = true;
				return 'r';
			}
			break;
		}
	}
}
