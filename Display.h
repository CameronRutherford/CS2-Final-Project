//Project: Make a working videogame
//File: Define the Display class that keeps track of all the things that are to be displayed on the screen, as well as having the functionality of displaying everything
//Last Updated on: 05/13/2017
//             by: Cameron Rutherford

////////////////////////////////
//            NOTE            //
////////////////////////////////
//The screen is displayed in a conventional coordinate system with (0,0) being the bottom left corner
//		0		1		2		3		4		5		6		7		....
//
//...
//
//6
//
//5
//
//4
//
//3
//
//2
//
//1
//
//0

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "Enemies.h"
#include "Environment.h"


using namespace std;

class Display {
private:
	vector<vector<char>> pixels;  //used to keep track of the pixels on the screen/when printing the screen itself
	void _delete(); //Removes all the pixels in the screen
	void space_screen(); //Fills the screen with the default character
	char default_char = ' ';
	void populate_screen(); //Runs through all the entities stored in the Display and stores the assosciated pixels in the pixel array
	int numplayerkilled = 0;
public:
	
	Display(); //uses the space screen as the default constructor
	void print(); //prints the screen
	vector<Entity *> Entities; //stores all of the entities to be printed to the screen
	bool PlayerEnvironmentCollision(); //Checks for the player colliding with the environment
	bool EnemyEnvironmentCollision(); //Checks for the enemy colliding with the environment
	void PlayerKillEnemies(); //Checks for the player colliding with the enemy and kills the enemy if so
	bool EnemyKillPlayer(); //Checks for the enemy colliding with the player and kills the player if so
	int getnumplayerkilled() {return numplayerkilled; }
	void ResetEnemies(Enemies *); //This removes all the enemies from the screen and pushes back all the enemies from the storage class
								  //used if ever the two would contain different enemies (i.e. if one was killed or one was added)
	void DeleteEnemies(Enemies *); //Deletes enemies from the screen and also deletes enemies from the storage class
	void NewEnvironment(Environment *); //Adds a new environment to the screen and deletes the old one
};

#endif