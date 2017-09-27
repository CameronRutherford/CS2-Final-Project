//Project: Make a working videogame
//File: Define the environment class that is used as a boundary for the players and the enemies
//Last Updated on: 05/13/2017
//             by: Cameron Rutherford
#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_

#include "Entity.h"

class Environment : public Entity {
public:
	Environment(int); //Custom constructor that you pass an int for the assosciated floor layout
};

#endif