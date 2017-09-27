#include "Menu.h"

void showMenu(int hoverChoice) {
	switch (hoverChoice) {
	case 0:
		cout << "Start Game <---" << endl
			<< "View High Scores" << endl
			<< "Exit Game" << endl;
		break;
	case 1:
		cout << "Start Game" << endl
			<< "View High Scores <---" << endl
			<< "Exit Game" << endl;
		break;
	case 2:
		cout << "Start Game" << endl
			<< "View High Scores" << endl
			<< "Exit Game <---" << endl;
		break;
	}
}

int Menu() {
	while (1)
	{
		int c = 0;
		static int choice = 0; //Saves the case choice of the player from the menu
		showMenu(choice); //Dislpays the menu
		switch ((c = getch())) {
		case KEY_UP: //Increase the choice case
			if (choice >= 1) {
				choice--;
			}
			break;
		case KEY_DOWN: //Decrease the choice case
			if (choice <= 1) {
				choice++;
			}
			break;
		case KEY_LEFT: //Currently does nothing for the left arrow
					   // key left
			break;
		case KEY_RIGHT: //Currently does nothing for the right arrow
						// key right
			break;
		case KEY_ENTER: //Select the choice and return the integer
			return choice;
		default:
			break;
		}
		system("CLS");
		//cout << c << endl << endl;  //Uncomment to see the key that was pressed
	}
}