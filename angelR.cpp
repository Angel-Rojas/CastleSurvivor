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

int zombiesKilled = 0;

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

void zombieKillCount()
{
	extern int zombiesKilled;
	Rect textBox;
	textBox.bot = 640;
	textBox.left = 10;
	textBox.center = 0;
	//int zombiesKill = kills;
	ggprint8b(&textBox, 16, 0x00ffff00, "Zombie Kill Count!!  %i", zombiesKilled);
	//ggprint8b(&textBox, 16, 0x00ffff00, "Zombie Kill Count!!  tester");
	//return;
} 
