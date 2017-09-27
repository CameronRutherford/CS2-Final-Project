//Project: Make a working videogame
//File: Define the player class functions used to identify a player and distinguish it from other enemies. A player is an Entity
//Last Updated on: 05/13/2017
//             by: Cameron Rutherford
#include "Player.h"

void Player::movementAlgorithm(char direction) //this is used to easily change the way in which the player moves
											   //could be used in the future for things like power ups or moving in weird ways by adding things to the class
{
	switch (direction) {
		case 'u':
			(*y_position) += 2;
			break;
		case 'd':
			(*y_position) -= 2;
			break;
		case 'r':
			(*x_position) += 2;
			break;
		case 'l':
			(*x_position) -= 2;
			break;
	}
}

Player::Player(int x, int y) : Entity(x,y) //use the correct x and y starting coords here in the custom constructor to make the player start in the right position
{
	Iam("Player"); //makes sure a player is identifies as a player

	//this just defines the design of the player and can be changed if wanted
	//try to make the "Sprite" of the player centred on the 0,0 offset to ensure aesthetically pleasing player starting position
	pixels.push_back(Pixel(-1, -1, '\\', *this));
	pixels.push_back(Pixel(0, -1, '_', *this));
	pixels.push_back(Pixel(1, -1, '/', *this));
	pixels.push_back(Pixel(-1, 0, '<', *this));
	pixels.push_back(Pixel(1, 0, '>', *this));
	pixels.push_back(Pixel(-1, 1, '/', *this));
	pixels.push_back(Pixel(0, 1, 'T', *this));
	pixels.push_back(Pixel(1, 1, '\\', *this));
}

void Player::reset() //resets the position of the character to the centre of the screen
{
	*x_position = SCREEN_WIDTH / 2;
	*y_position = SCREEN_HEIGHT / 2;
	this->update();
}

