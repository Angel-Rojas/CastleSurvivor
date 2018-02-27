

//Created by christy guerrero
//christy.cpp

//#include "Common.h"
#include "christy.h"
#include "fonts.h"
//#include <GL/glx.h>
//#include <X11/Xlib.h>
#include <iostream>
using namespace std;

void printName(){
	Rect c;
	//glClear(GL_COLOR_BUFFER_BIT);
	//
	c.bot = 640;
	c.left = 10;
	c.center = 0;
	ggprint8b(&c, 16, 0x00ffff00, "Christy");	
	//cout << "Christy" << endl;
	//return;
}

