#include "Leveling.h"


void Leveling::IncreaseLevel()
{
	system("cls");

	level++; //Increase the level

	CONSOLE_FONT_INFOEX large;
	large.cbSize = sizeof(large);
	large.nFont = 0;
	large.dwFontSize.X = 0;                   // Width of each character in the font
	large.dwFontSize.Y = 48;                  // Height
	large.FontFamily = FF_DONTCARE;
	large.FontWeight = FW_NORMAL;
	wcscpy(large.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &large);

	string strlevel = to_string(level); //Convert the level integer to a string
	string numlevel = "LEVEL " + strlevel; //Append the level to the 'LEVEL' text


	//cout << "Font: Consolas, Size: 16\n";
	centerstring(numlevel);
	//sleep_for(nanoseconds(10));
	sleep_until(system_clock::now() + seconds(1));
	cout << endl << "Press Enter to continue...";
	cin.ignore();
	system("cls");
	CONSOLE_FONT_INFOEX normal; //This will revert the text size back to normal
	normal.cbSize = sizeof(normal);
	normal.nFont = 0;
	normal.dwFontSize.X = 0;                   // Width of each character in the font
	normal.dwFontSize.Y = 24;                  // Height
	normal.FontFamily = FF_DONTCARE;
	normal.FontWeight = FW_NORMAL;
	wcscpy(normal.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &normal);
}

void Leveling::Gameover()
{
	CONSOLE_FONT_INFOEX large;
	large.cbSize = sizeof(large);
	large.nFont = 0;
	large.dwFontSize.X = 0;                   // Width of each character in the font
	large.dwFontSize.Y = 48;                  // Height
	large.FontFamily = FF_DONTCARE;
	large.FontWeight = FW_NORMAL;
	wcscpy(large.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &large);

	system("cls");

	string gameover = "GAMEOVER";
	//cout << "Font: Consolas, Size: 48\n";
	centerstring(gameover);

	sleep_until(system_clock::now() + seconds(1)); //Wait for 1 second
	system("cls");

	CONSOLE_FONT_INFOEX normal; //This will revert the text size back to normal
	normal.cbSize = sizeof(normal);
	normal.nFont = 0;
	normal.dwFontSize.X = 0;                   // Width of each character in the font
	normal.dwFontSize.Y = 24;                  // Height
	normal.FontFamily = FF_DONTCARE;
	normal.FontWeight = FW_NORMAL;
	wcscpy(normal.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &normal);
}

//This function will center the string that is passed into the function in the center of the screen
void centerstring(string s)
{
	int l = s.length(); //Find the length of the string
	int pos = (int)((80 - l) / 2);

	//For the width of the screen window, display a space to center the text
	for (int i = 0; i<pos; i++)
		cout << " ";
	cout << s; //Display the string

}