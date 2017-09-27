//Project: Make a working videogame
//File: Define the Direction class that is used to randomly generate a direction
//Last Updated on: 05/13/2017
//             by: Cameron Rutherford

#ifndef GENERATING_DIRECTION_H_
#define GENERATING_DIRECTION_H_

using namespace std;

class Direction {
private:
public:
	char GetDirection(bool reset); //generates a random direction (u,d,l,r), and doesn't give the same direction unless you reset
};

#endif