//Project: Make a working videogame
//File: Define the enemies class to contain enemies and the different enemies assosciated with it
//Last Updated on: 05/13/2017
//             by: Cameron Rutherford

#ifndef ENEMIES_H_
#define ENEMIES_H_

#include "Entity.h"
#include "GeneratingDirection.h"

using namespace std;

class Enemy : public Entity { //this is the base class for enemies that uses polymophism and inheritance to appropriately store enemies
private:
public:
	virtual void move(char) = 0; //this becomes the appropriate move function for the enemy
	Enemy(int x, int y); //the constructor for enemies in general
};

class CompassEnemy : public Enemy { //this enemy only moves in the four cardinal directions
private:
public:
	CompassEnemy(int x, int y);
	void move(char direction);
};


class DiagonalEnemy : public Enemy { //this enemy only moves in the four diagonal directions
private:
public:
	DiagonalEnemy(int x, int y);
	void move(char direction);
};

class Enemies { //this is the storage class for all enemies
private:
	vector<Enemy *> AllEnemies; //this points to the base class to easily store all enemies
public:
	Entity * getEnt(int index); //returns the entity for the enemy at the desired index
	int getsize() { return AllEnemies.size(); } //returns the amount of enemies
	void moveEnemy(int index, char direction); //moves the enemy at the desired index
	void revertEnemy(int index); //reverts an enemy at the desired index
	void updateEnemy(int index); //updates an enemy at the desired index
	void addEnemy(); //randomly adds an enemy to one of the four corners
	void DeleteEnemies(); //removes all enemies, used when updating the level
	void upDateEnemies(); //removes an enemy from the class if it is "dead"
};

#endif