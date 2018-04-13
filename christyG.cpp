

//Created by christy guerrero
//christy.cpp

//#include "Common.h"
#include "christyG.h"
//#include "fonts.h"
#include <GL/glx.h>
#include <time.h>
//#include <X11/Xlib.h>
#include <iostream>
#include "fonts.h"
using namespace std;


#define PROFILINGC_ON
//const double OOBILLION = 1.0 / 1e9;
extern struct timespec timeStart, timeCurrent;
extern double timeDiff(struct timespec *start, struct timespec *end);
extern void timeCopy(struct timespec *dest, struct timespec *source);

void printName()
{
 	Rect c;
    c.bot = 820;
    c.left = 200;
	c.center = 0;
	ggprint8b(&c, 16, 0x00ffff00, "christy");
}

void header(int x, int y, int xRES, int yRES)
{
	//red, green, blue
	glColor3ub(10,100,160);
	glPushMatrix();
	//glTranslatef(x,y,0);
	glBegin(GL_QUADS);
		//bottom left
		glVertex2f(xRES-xRES,yRES-90);
		//upper left
		glVertex2f(xRES-xRES,   yRES);
		//upper right
		glVertex2f(     xRES,   yRES);
		//bottom right
		glVertex2f(     xRES,yRES-90);
	glEnd();
	glPopMatrix();
	//Rect c;
	//c.bot = 50;


}

void drawBox(int x, int y)
{
	// 		   red, green, blue
    glColor3ub(100, 100, 160);
    glPushMatrix();
    //glTranslatef(x,y,0);
    glBegin(GL_QUADS);
    	glVertex2f( x-80, y-90);
    	glVertex2f( x-80, y);
    	glVertex2f( x, y);
    	glVertex2f( x, y-90);
    glEnd();
    glPopMatrix();

}

//#ifdef PROFILINGC_OFF
double timer() 
{	
	static double t = 0.0;
	struct timespec ftimeStart, ftimeEnd;
	clock_gettime(CLOCK_REALTIME, &ftimeStart);
	//int a = 200, b=300, c= 400;
	//for(int i=0: i<10; i++){
	//	b=(a&15) - (b&7) - (c&3);
	//	c=(b&31) - (a&7) - (c&3);
	//}
	
	printName();
	clock_gettime(CLOCK_REALTIME, &ftimeEnd);
	t += timeDiff(&ftimeStart, &ftimeEnd);
	drawBox(220, 900);
	Rect time;
	time.bot = 860;
	time.left = 200;
	time.center = 0;
	ggprint8b(&time, 16, 0x00ffff00, "Timer: %f", t);
	return t;
}
//#endif 


