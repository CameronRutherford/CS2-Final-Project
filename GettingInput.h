//Project: Make a working videogame
//File: Define the code assosciated with getting input from the keyboard as well as making the cursor on the console not show up
//Last Updated on: 05/13/2017
//             by: Cameron Rutherford
#ifndef GETTINGINPUT_H_
#define GETTINGINPUT_H_

#include <conio.h>
#include <Windows.h>
#include <iostream>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_SPACE 32
#define KEY_ENTER 13

void ShowConsoleCursor(bool showFlag);

#endif