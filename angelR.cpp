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
using namespace std;

// Define some 'Magic Numbers', or other usable variables
#define POW  "Pow!"
#define FULLH  "[====>]"
#define YOFFSET  31
#define MOREYOFFSET  41
#define XOFFSET  150
#define blue 0xab0000cc
#define yellow 0x00ffff00

// Global Variables
static int zombie_kills = 0;
static int next_level = 1;
static int wave_count = 1;
int counter = 0;
static bool Next = false;
static int State = 0;

// enumerator of Health Bars.
enum HealthBar {
	FULL,
	THREEFOURTHS,
	HALF,
	QUARTER,
	EMPTY
};

// enumerator of Games' States.
enum GameStates {
	HEALTHY,
	HITONCE,
	HITTWICE,
	HITTHRICE,
	DEAD
};


// Function that actually displays player health bar.
void displayHealth(int input,int ypos, int xpos)
{
	int Meter = input;
	switch (Meter) {
		case FULL:
			Rect text;
			text.bot = ypos - 20;
			text.left = xpos / 11;
			text.center = 0;
			ggprint8b(&text, 16, yellow, "Health %s", FULLH);
			break;
		case THREEFOURTHS:
			break;
		case HALF:
			break;
		case QUARTER:
			break;
		case EMPTY:
			break;
		default: 
			Rect t;
			t.bot = 870;
			t.left = 250;
			t.center = 0;
			ggprint8b(&t, 16, yellow, "Health ");
	}
}

// This func serves to decide which Healthbar to Render.
void playerState(int healthbar, int ypos, int xpos) 
{
	switch (healthbar) {
        case HITONCE:
            displayHealth(THREEFOURTHS,ypos,xpos);
            break;
        case HITTWICE:
            displayHealth(HALF,ypos,xpos);
            break;
        case HITTHRICE:
            displayHealth(QUARTER,ypos,xpos);
            break;
        case DEAD:
            displayHealth(EMPTY,ypos,xpos);
            break;

        default:
            displayHealth(FULL,ypos,xpos);
    }
}

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
void displayWave(int ypos, int xpos)
{
	Rect text;
	// bot = 640, left = 10, center = 0
	text.bot = ypos - MOREYOFFSET;
	text.left = xpos;
	text.center = 0;
	ggprint8b(&text, 16, yellow, "Current Wave: %i", wave_count);
}

// This function simply welcomes the player.
void printWelcome()
{
    cout << "Welcome, Player 1" << endl;
    return;
}

// This function prints out a statement each time you fire.
void powText()
{
    cout << POW << endl;
    return;
}

// A function called from anywhere to incr. zombie kill count.
void incrementZombiesKilled()
{
	zombie_kills++;
	return;	
}

// 'changeBoolean()' will "flip" the value of any bool sent to it.
// Finally works correctly. '&' is important.
bool changeBoolean(bool &input)
{
	if (input == true) {
		input = false;
	} else {
		input = true;
	}
	return input;
}

//'zombieKillCount(int)' is a func that displays total zombies killed.
void zombieKillCount(int ypos)
{
	extern int zombie_kills;
	Rect text;
	text.bot = ypos - YOFFSET;
	text.left = 10;
	text.center = 0;
	//int zombiesKill = kills;
	ggprint8b(&text, 16, yellow, "Zombie Kill Count: [ %i]", zombie_kills);
} 

// This will reset the zombie kill counter when called.
void resetKillCount()
{
	if (zombie_kills >= 1) {
		zombie_kills = 0;
	} else {
		zombie_kills = 0;
	}
}

// 'nextLevel2()' prints the next level to screen.
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
	ggprint8b(&text, 16, yellow, "NEXT LEVEL: %i", next_level);
	ggprint8b(&text, 16, yellow, "O - Okay");
	// Wait a second for printed message to be read
	//sleep(2);
	next_level++;
	//return;
}

// 'checkNextLevel()' checks to see if next level is imminent.
void checkNextLevel()
{
	if (counter == 5) {
		Next = true;
		counter = 0;
	} if (zombie_kills == 5 && Next) {
		nextLevel2();
	}
}
