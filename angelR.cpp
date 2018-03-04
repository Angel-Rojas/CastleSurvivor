/*
 * Author: Angel Rojas
 * filename: angelR.cpp
 *
 *
 */
#include <iostream>
#include "Common.h"
#include "angelR.h"
#include "fonts.h"
#define POW  "Pow!"
using namespace std;

// Global Variables
static int zombies_killed = 0;
static int next_level = 1;
static int wave_count = 1;
int counter = 0;
static bool Next = false;

// This function will increment the Wave counter.
void incrementWave()
{
	wave_count++;
	return;	
}

// This function will reset the Wave counter.
void resetWave()
{
	if (wave_count >= 2) {
		wave_count = 1;
	} else {
		wave_count = 1;
	}
}

// This function will display the Wave counter.
void displayWave()
{
	Rect text;
	text.bot = 640;
	text.left = 10;
	text.center = 0;
	//int zombiesKill = kills;
	ggprint8b(&text, 16, 0x00ffff00, "Current Wave: %i", wave_count);
}

// This function simply welcomes the player.
void printWelcome()
{
    cout << "Welcome, Player 1" << endl;
    return;
}

void powText()
{
    cout << POW << endl;
    return;
}

void incrementZombiesKilled()
{
	zombies_killed++;
	return;	
}

// Finally works correctly. '&' is important.
bool changeBoolean(bool &input)
{
	if (input == true) {
		input = false;
	} else {
		input = true;
	}
	//cout << input << endl;
	return input;
}

void zombieKillCount()
{
	extern int zombies_killed;
	Rect textBox;
	textBox.bot = 650;
	textBox.left = 10;
	textBox.center = 0;
	//int zombiesKill = kills;
	ggprint8b(&textBox, 16, 0x00ffff00, "Zombie Kill Count: [ %i]", zombies_killed);
	//ggprint8b(&textBox, 16, 0x00ffff00, "Zombie Kill Count! [ %i]", zombies_killed);
} 

void resetKillCount()
{
	if (zombies_killed >= 1) {
		zombies_killed = 0;
	} else {
		zombies_killed = 0;
	}
}

void nextLevel2()
{
	extern int next_level; 
	extern int xres, yres;
	void render();
	next_level = 2;
	//Clear screen
	glClear(GL_COLOR_BUFFER_BIT);
	Rect text;
	text.bot = 900 / 2;
	text.left = 1250 / 2;
	text.center = 0;
	//int zombiesKill = kills;
	ggprint8b(&text, 16, 0x00ffff00, "NEXT LEVEL: %i", next_level);
	ggprint8b(&text, 16, 0x00ffff00, "O - Okay");
	// Wait a second for printed message to be read
	//sleep(2);
	//render();
	next_level++;
	//return;
}

void checkNextLevel()
{
	//cout << zombies_killed << endl;
	if (counter == 5) {
		Next = true;
		counter = 0;
	} if (zombies_killed == 5 && Next) {
		nextLevel2();
	}
}
