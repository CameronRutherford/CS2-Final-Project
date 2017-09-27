//Project: Make a working videogame
//File: Define the main function and play the actual game
//Last Updated on: 05/13/2017
//             by: Cameron Rutherford
//					(and Garrett Jones)
//					(and Jarin Manuel)


#include "Display.h"
#include "Player.h"
#include "GettingInput.h"
#include "Environment.h"
#include "Enemies.h"
#include "Leveling.h" 
#include "GeneratingDirection.h"
#include "Menu.h"
#include "HighScores.h"

using namespace std;


int main() {
	system("CLS");
	int moves_per_level = 100; //this keeps track of the moves recquired to update the level
	int moves_per_enemy = 10; //this keeps track of the moves per enemy spawned

	CONSOLE_FONT_INFOEX normal; //This will revert the text size back to normal
	normal.cbSize = sizeof(normal);
	normal.nFont = 0;
	normal.dwFontSize.X = 0;                   // Width of each character in the font
	normal.dwFontSize.Y = 24;                  // Height
	normal.FontFamily = FF_DONTCARE;
	normal.FontWeight = FW_NORMAL;
	wcscpy(normal.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &normal);

	ShowConsoleCursor(false); //removes the flashing of the cursor
	
	bool done = false;
	while (!done) {
		int choice = Menu(); //Call the Menu function and given the players choice: start game, view highscores, or exit game

		if (choice == 0) { //Start the game
			system("CLS");

			Display Screen;
			Player p1(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
			Enemies Enemies;
			Leveling player;
			Direction Direction;

			Screen.Entities.push_back(p1.getEnt()); //add the player to the screen
			Screen.NewEnvironment(new Environment(0)); //add the level environment to the screen

			Screen.print();
			cout << "Moves: " << p1.getMoves() << endl;
			cout << "Enemies killed: " << Screen.getnumplayerkilled() << endl;

			int c = 0;

			while (1)
			{
				c = 0;
				bool successful = false;
				while (!successful) {
					switch ((c = getch())) { //getch stalls the console until an input is detected
											 //Each direction moves the player in the assosciated direction
											 //Space stalls the player and updates the screen
					case KEY_UP:
						p1.up(); //key up
						successful = true;
						break;
					case KEY_DOWN:
						p1.down(); // key down
						successful = true;
						break;
					case KEY_LEFT:
						p1.left(); // key left
						successful = true;
						break;
					case KEY_RIGHT:
						p1.right(); // key right
						successful = true;
						break;
					case KEY_SPACE:
						successful = true;
						break;
					default:
						break;
					}

					while (Screen.PlayerEnvironmentCollision()) { //this test to see if the player moved into the environment
						successful = false; //if they did get the input again
						p1.revert(); //move the player back to the previous position
					}
				}

				system("CLS");

				p1.update(); //update the player's previous position

				Screen.PlayerKillEnemies(); //Checks to see if the player tried to kill an enemy, and removes them from the screen's entitiest if they did
				Enemies.upDateEnemies(); //Removes any enemies if they were killed from the storage class for the enemeies

				int enemy_index = 0;
				while (enemy_index < Enemies.getsize()) { //for every enemy that is stored
					int count = 1;
					Enemies.moveEnemy(enemy_index, Direction.GetDirection(true)); //move the enemy with a random input into their movement algorithm
					while (Screen.EnemyEnvironmentCollision() && count < 4) { //this checks to see if the enemy collided with the environment
																			  //while also only trying to move the enemy in each of the four directions once

						Enemies.revertEnemy(enemy_index); //if they collided, move them back
						Enemies.moveEnemy(enemy_index, Direction.GetDirection(false)); //move them in a new random direction
						count++; //update the number of attempts there have been at moving
					}
					Enemies.updateEnemy(enemy_index); //update the appropriate enemy
					enemy_index++; //start checking for a new enemy
				}
				if (Screen.EnemyKillPlayer()) { //check to see if the enemy kills the player
					break;
				}

				Screen.print();
				cout << "Moves: " << p1.getMoves() << endl;
				cout << "Enemies killed: " << Screen.getnumplayerkilled() << endl;

				if (p1.getMoves() % moves_per_level == 0) { //update the the environment if the player has moved 100 times
					static int level_count = 0;
					level_count++;
					moves_per_level += (100 + level_count * 50);
					if (level_count % 2 == 0 && moves_per_enemy > 5) { //every 2 levels, and if the enemy spawn rate is greater than 5
						moves_per_enemy--;
					}
					Screen.NewEnvironment(new Environment(level_count % 5)); //update the environment
					p1.reset(); //reset the position of the player
					p1.decreaseMoves(); //this just decreases the move count as for some reason the player skips a move when updating the level if this isn't there

					player.IncreaseLevel(); //This displays the new level

					Screen.DeleteEnemies(&Enemies); //removes all the enemies from the storage class as this is a design desicion to clear the screen of enemies

					Screen.print();
					cout << "Moves: " << p1.getMoves() << endl;
					cout << "Enemies killed: " << Screen.getnumplayerkilled() << endl;
				}
				else if (p1.getMoves() % moves_per_enemy == 0) { //spawn an enemy every 10 moves

					Enemies.addEnemy(); //add a random enemy to one of the four courners randomly

					Screen.ResetEnemies(&Enemies); //makes sure the screen properly updates the enemies on the screen

					for (int i = 0; i < Enemies.getsize(); i++) {
						Enemies.updateEnemy(i); //if you don't update every enemy, the previous position may not work, not 100% sure
					}

					system("CLS");
					Screen.print();
					cout << "Moves: " << p1.getMoves() << endl;
					cout << "Enemies killed: " << Screen.getnumplayerkilled() << endl;
				}
			}
			player.Gameover(); //trigger the game over screen if the player ever dies
			HighScore(p1.getMoves());
		}
		else if (choice == 1) { //View highscores
			HighScore(0);
		}
		else if (choice == 2) { //Exit the game
			done = true;
		}
	}	
	return 0;
}