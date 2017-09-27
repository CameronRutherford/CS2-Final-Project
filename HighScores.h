#ifndef HIGHSCORES_H_
#define HIGHSCORES_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include "Leveling.h"

using namespace std;

void HighScore(int score);
void MakeHighScore(vector<int> &Highscores);	//Writes scores to text file
void PullHighScore(vector<int> &Highscores);	//Takes scores from text file
void MakeHighName(vector<string> &Highnames, int place, string name); //Writes names to text file //1 means first, 2 means second, 3 means third
void PullHighName(vector<string> &Highnames);	//Takes names from text file
int CheckHighScore(vector<int> &Highscores, int moves); //Checks if player got a high score// 0 means no high score, 1 means first, 2 means second, 3 means third
void ShowHighScores(vector<int> Highscores, vector<string> Highnames); //Displays list of highscores and names

#endif