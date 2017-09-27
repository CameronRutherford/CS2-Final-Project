#ifndef LEVELING_H_
#define LEVELING_H_
#include <string>
#include <iostream>
#include <cwchar>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <string>

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
using namespace std;

void centerstring(string s);

class Leveling {
private:
	int level = 1; //Level that the player is on
public:
	void IncreaseLevel(); //This function will display the 'LEVEL' text and increase the level that the player is currently on
	void Gameover(); //'GAMEOVER' text
};

#endif
