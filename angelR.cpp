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
static int zombiesKilled = 0;
static int nextLevel = 1;
int counter = 0;
static bool Nextlvl = false;

void printHello()
{
    cout << "Hello World!" << endl;
    return;
}

void powText()
{
    cout << POW << endl;
    return;
}

void incrementZombiesKilled()
{
	zombiesKilled++;
	return;	
}

// DOESNT WORK AS INTENDED yet
bool changeBoolean(bool input)
{
	if (input == true) {
		input = false;
	} else {
		input = true;
	}
	cout << input << endl;
	return input;
}

void zombieKillCount()
{
	extern int zombiesKilled;
	Rect textBox;
	textBox.bot = 650;
	textBox.left = 10;
	textBox.center = 0;
	//int zombiesKill = kills;
	ggprint8b(&textBox, 16, 0x00ffff00, "Zombie Kill Count! [ %i]", zombiesKilled);
	//ggprint8b(&textBox, 16, 0x00ffff00, "Zombie Kill Count! [ %i]", zombiesKilled);
	//return;
} 

void nextLevel2()
{
	extern int nextlevel; 
	extern int xres, yres;
	void render();
	nextLevel = 2;
	//Clear screen
	glClear(GL_COLOR_BUFFER_BIT);
	Rect text;
	text.bot = 900 / 2;
	text.left = 1250 / 2;
	text.center = 0;
	//int zombiesKill = kills;
	ggprint8b(&text, 16, 0x00ffff00, "NEXT LEVEL: %i", nextLevel);
	ggprint8b(&text, 16, 0x00ffff00, "O - Okay");
	// Wait a second for printed message to be read
	//sleep(2);
	//render();
	nextLevel++;
	//return;
}

void checkNextLevel()
{
	//cout << zombiesKilled << endl;
	if (counter == 5) {
		Nextlvl = true;
		counter = 0;
	} if (zombiesKilled == 5 && Nextlvl) {
		nextLevel2();
	}
}
