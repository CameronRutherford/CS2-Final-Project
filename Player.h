//Project: Make a working videogame
//File: Define the player class used to identify a player and distinguish it from other enemies. A player is an Entity
//Last Updated on: 05/13/2017
//             by: Cameron Rutherford

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Entity.h"

class Player: public Entity {
private:
	void movementAlgorithm(char direction); //this is used to easily change the way in which the player moves
											//could be used in the future for things like power ups or moving in weird ways by adding things to the class
public:
	Player(int x, int y); //use the correct x and y starting coords here in the custom constructor to make the player start in the right position
	void up() { movementAlgorithm('u'); }
	void down() { movementAlgorithm('d'); }
	void right() { movementAlgorithm('r'); }
	void left() { movementAlgorithm('l'); }
	void reset(); //resets the position of the character to the centre of the screen
};

#endif