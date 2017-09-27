//Project: Make a working videogame
//File: Define the Display class functions that were defined in the header file
//Last Updated on: 05/13/2017
//             by: Cameron Rutherford
#include "Display.h"
#include "GeneratingDirection.h"

void Display::_delete() //Removes all the pixels in the screen - not entirely sure if this is ever used
{
	while (!pixels.empty()) {
		while (!pixels[pixels.size() - 1].empty()) {
			pixels[pixels.size() - 1].pop_back();
		}
	}

}

void Display::space_screen() //Fills the screen with the default character, being ' '
{
	vector<vector<char>> thing(SCREEN_HEIGHT, vector<char>(SCREEN_WIDTH, default_char));
	pixels.swap(thing);
}

void Display::populate_screen() //Runs through all the entities stored in the Display and stores the assosciated pixels in the pixel array
{
	for (unsigned ent_count = 0; ent_count < Entities.size(); ent_count++) { //for every entitiy in the screen
		for (unsigned pix_count = 0; pix_count < Entities[ent_count]->pixels.size(); pix_count++) { //for every pixel in each entity
			Pixel this_pix = Entities[ent_count]->pixels.at(pix_count); //get the pixel
			pixels[this_pix.get_y()][this_pix.get_x()] = this_pix.get_char(); //push the char into the appropriate pixel on the screen
		}
	}
}

Display::Display() //uses the space screen as the default constructor
{
	space_screen();
}

void Display::print() //prints the screen
{
	space_screen(); //resets all the pixels on the screen
	populate_screen(); //appropriately changes the pixels needed to display enemies
	for (int i = pixels.size() - 1; i >= 0; i--) { //outputs all the pixels to the screen in the correct order
		for (int j = 0; j < pixels[i].size(); j++) {
			cout << pixels[i][j];
		}
		cout << endl;
	}
}

bool Display::PlayerEnvironmentCollision() //Checks for the player colliding with the environment
{
	for (unsigned i = 0; i < Entities.size(); i++) { //For every entity on the screen
		for (unsigned j = 0; j < Entities.size(); j++) { //Check against every remaining entity
			if (Entities[i]->whatAmI() == "Player" && //if one of them is a player
				Entities[j]->whatAmI() == "Environment" && //and another is an environment
				*Entities[i] == *Entities[j]) { //and they intersect at any point
				return true; 
			}
		}
	}
	return false;
}

bool Display::EnemyEnvironmentCollision() //Checks for the enemy colliding with the environment
{
	for (unsigned i = 0; i < Entities.size(); i++) { //For every entity on the screen
		for (unsigned j = 0; j < Entities.size(); j++) { //Check against every remaining entity
			if (Entities[i]->whatAmI() == "Enemy" && //if one of them is an enemy
				Entities[j]->whatAmI() == "Environment" && //and another is an environment
				*Entities[i] == *Entities[j]) { //and they intersect at any point
				return true;
			}
		}
	}
	return false;
}

void Display::PlayerKillEnemies() //Checks for the player colliding with the enemy and kills the enemy if so
{
	for (unsigned i = 0; i < Entities.size(); i++) { //For every entity on the screen
		for (unsigned j = 0; j < Entities.size(); j++) { //Check against every remaining entity //HERE
			if (Entities[i]->whatAmI() == "Player" && //if one of them is a player
				Entities[j]->whatAmI() == "Enemy" && //and another is an enemy
				*Entities[i] == *Entities[j]) { //and they intersect at any point
				Entities[j]->kill();
				Entities.erase(Entities.begin() + j);
				numplayerkilled++;
			}
		}
	}
	
}

bool Display::EnemyKillPlayer() //Checks for the enemy colliding with the player and kills the player if so
{
	for (unsigned i = 0; i < Entities.size(); i++) { //For every entity on the screen
		for (unsigned j = 0; j < Entities.size(); j++) { //Check against every remaining entity //HERE
			if (Entities[i]->whatAmI() == "Player" && //if one of them is a player
				Entities[j]->whatAmI() == "Enemy" && //and another is an enemy
				*Entities[i] == *Entities[j]) { //and they intersect at any point
				Entities.erase(Entities.begin() + i); //get rid of the player from the screen - probably not strictly necessary
				return true; //return the player was killed
			}
		}
	}
	return false; //return the player was not killed
}



void Display::ResetEnemies(Enemies * Things) //This removes all the enemies from the screen and pushes back all the enemies from the storage class
											 //used if ever the two would contain different enemies (i.e. if one was killed or one was added)
{
	for (int i = Entities.size() - 1; i >= 0; i--) { //remove all enemies stored on the screen
		if (Entities[i]->whatAmI() == "Enemy") {
			Entities.erase(Entities.begin() + i);
		}
	}
	for (int i = 0; i < Things->getsize(); i++) { //add all enemies from the storage class to the screen
		if (!Things->getEnt(i)->isdead()) {
			this->Entities.push_back(Things->getEnt(i));
		}
	}
}

void Display::DeleteEnemies(Enemies * Things) //Deletes enemies from the screen and also deletes enemies from the storage class
{
	for (int i = Entities.size() - 1; i >= 0; i--) { //remove all enemies from the screen
		if (Entities[i]->whatAmI() == "Enemy") {
			Entities.erase(Entities.begin() + i);
		}
	}
	Things->DeleteEnemies(); //delete all enemies from the storage class
}

void Display::NewEnvironment(Environment * newEnvironment) //Adds a new environment to the screen and deletes the old one
{
	for (int i = Entities.size() - 1; i >= 0; i--) { //deletes the any environments from the screen
		if (Entities[i]->whatAmI() == "Environment") {
			Entities.erase(Entities.begin() + i);
		}
	}
	Entities.push_back(newEnvironment->getEnt()); //adds a new environment
}


