//Project: Make a working videogame
//File: Define the functions of the enemies class to contain enemies and the different enemies assosciated with it
//Last Updated on: 05/13/2017
//             by: Cameron Rutherford
#include "Enemies.h"

Enemy::Enemy(int x, int y) : Entity(x, y) //this is the base class for enemies that uses polymophism and inheritance to appropriately store enemies
{
	Iam("Enemy"); //makes sure the enemy is identified as an enemy
	prev_x = x;
	prev_y = y;
}

//this enemy only moves in the four cardinal directions

CompassEnemy::CompassEnemy(int x, int y) : Enemy(x,y) //this just pushes back the design for the enemy
{
	pixels.push_back(Pixel(0, 0, '<', *this));
	pixels.push_back(Pixel(1, 0, '>', *this));
	pixels.push_back(Pixel(1, 1, '^', *this));
	pixels.push_back(Pixel(0, 1, 'v', *this));
}

void CompassEnemy::move(char direction) //this defines the way the enemy moves (in the four directions)
{
	switch (direction) {
	case 'u':
		(*y_position)++;
		break;
	case 'd':
		(*y_position)--;
		break;
	case 'r':
		(*x_position)++;
		break;
	case 'l':
		(*x_position)--;
		break;
	
	}
}

Entity * Enemies::getEnt(int index) //returns the entity for the enemy at the desired index
{
	return AllEnemies.at(index)->getEnt();
}


void Enemies::moveEnemy(int index, char direction)  //moves the enemy at the desired index
{
	if (!AllEnemies.at(index)->getEnt()->isdead()) { //makes sure not to move the enemy if it is dead - not entirely sure if this check is necessary
		AllEnemies.at(index)->move(direction);
	}
}

void Enemies::revertEnemy(int index) //reverts an enemy at the desired index
{
	AllEnemies.at(index)->revert();
}

void Enemies::updateEnemy(int index) //updates an enemy at the desired index
{
	AllEnemies.at(index)->update();
}

//this enemy only moves in the four diagonal directions

DiagonalEnemy::DiagonalEnemy(int x, int y) : Enemy(x,y) //this just pushes back the design for the enemy
{
	pixels.push_back(Pixel(0, 1, '\\', *this));
	pixels.push_back(Pixel(1, 1, '/', *this));
	pixels.push_back(Pixel(1, 0, '/', *this));
	pixels.push_back(Pixel(0, 0, '\\', *this));
}

void DiagonalEnemy::move(char direction) //this defines the way the enemy moves (in the four directions)
{
	switch (direction) {
	case 'u':
		(*y_position)++;
		(*x_position)++;
		break;
	case 'd':
		(*y_position)--;
		(*x_position)--;
		break;
	case 'r':
		(*x_position)++;
		(*y_position)--;
		break;
	case 'l':
		(*x_position)--;
		(*y_position)++;
		break;

	}
}

void Enemies::addEnemy() //randomly adds an enemy to one of the four corners
{
	Direction Direction;
	char place = Direction.GetDirection(true); //checks for a what corner to put the enemy - u = bottom right, d = bottom left, r = top right, l = top left
	char enemy = Direction.GetDirection(true); //checks for what type of enemy to spawn - u = d = Diagonal Enemy, r = l = Compass Enemy
	switch (place) {
	case 'u':
		if (enemy == 'r' || enemy == 'l') {
			AllEnemies.push_back(new CompassEnemy(SCREEN_WIDTH - 4, 4));
		}
		else {
			AllEnemies.push_back(new DiagonalEnemy(SCREEN_WIDTH - 4, 4));
		}
		break;
	case 'd':
		if (enemy == 'r' || enemy == 'l') {
			AllEnemies.push_back(new CompassEnemy(4, 4));
		}
		else {
			AllEnemies.push_back(new DiagonalEnemy(4, 4));
		}
		break;
	case 'l':
		if (enemy == 'r' || enemy == 'l') {
			AllEnemies.push_back(new CompassEnemy(4, SCREEN_HEIGHT - 4));
		}
		else {
			AllEnemies.push_back(new DiagonalEnemy(4, SCREEN_HEIGHT - 4));
		}
		break;
	case 'r':
		if (enemy == 'r' || enemy == 'l') {
			AllEnemies.push_back(new CompassEnemy(SCREEN_WIDTH - 4, SCREEN_HEIGHT - 4));
		}
		else {
			AllEnemies.push_back(new DiagonalEnemy(SCREEN_WIDTH - 4, SCREEN_HEIGHT - 4));
		}
		break;
	}
}

void Enemies::DeleteEnemies() //removes all enemies, used when updating the level
{
	AllEnemies.clear();
}

void Enemies::upDateEnemies() //removes an enemy from the class if it is "dead"
{
	for (int i = 0; i < AllEnemies.size(); i++) { //for all enemies
		if (AllEnemies[i]->isdead()) { //if it is dead
			AllEnemies.erase(AllEnemies.begin() + i); //remove it
		}
	}
}
