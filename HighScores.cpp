#include "HighScores.h"

void HighScore(int score)
{
	system("cls"); ///can be removed, for testing purposes only
	string NameEntry = " ";			//Creates string for entry of name if broke highscore
	vector<int> Highscores;			//Creates a vector integers for highscores
	vector<string>Highnames;		//Creates vector of strings for names
	PullHighScore(Highscores);		//Grabs scores from text file
	PullHighName(Highnames);		//Grabs names from text file
	int x = CheckHighScore(Highscores, score);		///NEEDS TO BE REPLACED //Creates integer for checker function
	MakeHighScore(Highscores);		//Writes high scores to the file

	if (score == 0) {
		ShowHighScores(Highscores, Highnames);
	}

	else if (x == 0) //Didn't get a high score
	{
		cout << "Sorry, you didn't get a high score." << endl << endl;
		ShowHighScores(Highscores, Highnames);	//Displays highscores
	}

	else if (x == 1)  //Got first high score
	{
		cout << "Congrats! You got the top score!" << endl;
		cout << "Please enter a name: " << endl;	//Prompt for player to enter name for highscore
		cin >> NameEntry;	//Players enters name for highscore
		cout << endl;
		MakeHighName(Highnames, x, NameEntry);	//Writes to file with updated name
		ShowHighScores(Highscores, Highnames);	//Displays highscores
	}

	else if (x == 2)  //Got second high score
	{
		cout << "Wow! You got second! Shoot for the top!" << endl;
		cout << "Please enter a name: " << endl;	//Prompt for player to enter name for highscore
		cin >> NameEntry;	//Players enters name for highscore
		cout << endl;
		MakeHighName(Highnames, x, NameEntry);	//Writes to file with updated name
		ShowHighScores(Highscores, Highnames);	//Displays highscores
	}

	else if (x == 3)  //Got third high score
	{
		cout << "Awesome, you got third! I know you can do better though!" << endl;
		cout << "Please enter a name: " << endl;	//Prompt for player to enter name for highscore
		cin >> NameEntry;	//Players enters name for highscore
		cout << endl;
		MakeHighName(Highnames, x, NameEntry);	//Writes to file with updated name
		ShowHighScores(Highscores, Highnames);	//Displays highscores
	}
	cout << endl << "Press Enter to continue...";
	cin.ignore(2);
	system("cls");
}

void PullHighScore(vector<int> &Highscores)		//Pulls out of the file 
{
	ifstream fin;
	fin.open("\\\\cs1\\CS_Projects\\CS172FinalHighscores\\Scores.txt");	//File location can be changed

	if (fin.fail())							//If the file can't be opened
	{
		cout << "Can't open file" << endl;	//Display error message
	}

	string line;							//Creates string called line to be compared to entire line in file

	for (int i = 0; i < 3; i++)				//Runs 3 times
	{
		getline(fin, line);					//Grabs the entirety of line in text file
		Highscores.push_back(stoi(line));	//Pushes onto vector
	}
}

void MakeHighScore(vector<int> &Highscores)		//Writes onto txt file
{
	ofstream fout;
	fout.open("\\\\cs1\\CS_Projects\\CS172FinalHighscores\\Scores.txt");    //File location can be changed

	if (fout.fail())						//If the file can't be opened
	{
		cout << "Can't open file" << endl;	//Display error message
	}

	for (int i = 0; i < 3; i++)				//Runs 3 times
	{
		fout << Highscores[i] << endl;		//Writes scores to the file
	}
}

void PullHighName(vector<string> &Highnames)	//Pulls out of the file
{
	ifstream fin;
	fin.open("\\\\cs1\\CS_Projects\\CS172FinalHighscores\\Names.txt");    //File location can be changed

	if (fin.fail())							//If the file can't be opened
	{
		cout << "Can't open file" << endl;	//Display error message
	}

	string line;							//Creates string called line to be compared to entire line in file

	for (int i = 0; i < 3; i++)				//Runs 3 times
	{
		getline(fin, line);					//Grabs entirety of line in file
		Highnames.push_back(line);			//Pushes onto vector
	}
}

void MakeHighName(vector<string> &Highnames, int place, string name) //1 means first, 2 means second, 3 means third //Writes to txt file
{
	ofstream fout;
	fout.open("\\\\cs1\\CS_Projects\\CS172FinalHighscores\\Names.txt");    //File location can be changed

	if (fout.fail())						//If file can't be opened
	{
		cout << "Can't open file" << endl;	//Display error message
	}

	if (place == 1)							//If the player came in first place
	{
		Highnames[2] = Highnames[1];		//Shift names down
		Highnames[1] = Highnames[0];
		Highnames[0] = name;				//Set new name as first name
	}

	else if (place == 2)					//If the player came in second place
	{
		Highnames[2] = Highnames[1];		//Shift name down
		Highnames[1] = name;				//Set new name as second name
	}

	else if (place == 3)					//If the player came in third place
	{
		Highnames[2] = name;				//Set new name as third name
	}

	for (int i = 0; i < 3; i++)				//Runs 3 times
	{
		fout << Highnames[i] << endl;		//Writes names to file
	}

}

int CheckHighScore(vector<int> &Highscores, int moves)		//Checks if player got new high score
{
	if (Highscores[0] < moves)								//If player beat first place
	{
		Highscores[2] = Highscores[1];						//Replace scores
		Highscores[1] = Highscores[0];
		Highscores[0] = moves;								//Player's score set to first
		return 1;
	}

	else if (Highscores[1] < moves)							//If player only beat second place
	{
		Highscores[2] = Highscores[1];						//Replace score
		Highscores[1] = moves;								//Player's score set to second
		return 2;
	}

	else if (Highscores[2] < moves)							//If player only beat third place
	{
		Highscores[2] = moves;								//Player's score set to third
		return 3;
	}
	return 0;
}

void ShowHighScores(vector<int> Highscores, vector<string> Highnames)				  //Displays highscores
{
	string HighScoreDisplay = "HIGH SCORES\n";										  //Sets title of high scores
	string HighScoreLine = "----------------------------------------------\n";		  //Sets line of high scores
	centerstring(HighScoreDisplay);													  //Centers title
	centerstring(HighScoreLine);													  //Centers line
	for (int i = 0; i < 3; i++)														  //Runs 3 times
	{
		string nameCombo = Highnames[i] + "     " + to_string(Highscores[i]) + "\n";  //Sets combo of name and score
		centerstring(nameCombo);													  //Centers combo
	}
}
