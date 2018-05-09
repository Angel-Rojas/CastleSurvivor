

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

#define ALPHA 1
#define PROFILINGC_ON
//const double OOBILLION = 1.0 / 1e9;
extern struct timespec timeStart, timeCurrent;
extern double timeDiff(struct timespec *start, struct timespec *end);
extern void timeCopy(struct timespec *dest, struct timespec *source);
class Image {
public:
	int width, height;
	unsigned char *data;
	~Image() { delete [] data; }
	Image(const char *fname) {
		if (fname[0] == '\0')
			return;
		//printf("fname **%s**\n", fname);
		int ppmFlag = 0;
		char name[40];
		strcpy(name, fname);
		int slen = strlen(name);
		char ppmname[80];
		if (strncmp(name+(slen-4), ".ppm", 4) == 0)
			ppmFlag = 1;
		if (ppmFlag) {
			strcpy(ppmname, name);
		} else {
			name[slen-4] = '\0';
			//printf("name **%s**\n", name);
			sprintf(ppmname,"%s.ppm", name);
			//printf("ppmname **%s**\n", ppmname);
			char ts[100];
			//system("convert img.jpg img.ppm");
			sprintf(ts, "convert %s %s", fname, ppmname);
			system(ts);
		}
		//sprintf(ts, "%s", name);
		FILE *fpi = fopen(ppmname, "r");
		if (fpi) {
			char line[200];
			fgets(line, 200, fpi);
			fgets(line, 200, fpi);
			//skip comments and blank lines
			while (line[0] == '#' || strlen(line) < 2)
				fgets(line, 200, fpi);
			sscanf(line, "%i %i", &width, &height);
			fgets(line, 200, fpi);
			//get pixel data
			int n = width * height * 3;			
			data = new unsigned char[n];			
			for (int i=0; i<n; i++)
				data[i] = fgetc(fpi);
			fclose(fpi);
		} else {
			printf("ERROR opening image: %s\n",ppmname);
			exit(0);
		}
		if (!ppmFlag)
			unlink(ppmname);
	}
};
//Image img[3] = {"./x.ppm", "./explosion.ppm", "./bship.ppm"};
Image img[5] = {"images/castle2.png","images/castlebricks.jpg", "images/grasstest_1.png","images/zombie2.png", "images/logo.png"};
GLuint castleTex;
GLuint barTex;
GLuint backTex;
GLuint zombieTex;
GLuint logoTex;
Image *castleImage = NULL;
Image *barImage = NULL;
Image *backImage = NULL;
Image *zombieImage = NULL;
Image *logoImage = NULL;

unsigned char *buildAlphaData(Image *img)
{
	//add 4th component to RGB stream...
	int i;
	int a,b,c;
	unsigned char *newdata, *ptr;
	unsigned char *data = (unsigned char *)img->data;
	newdata = (unsigned char *)malloc(img->width * img->height * 4);
	ptr = newdata;
	for (i=0; i<img->width * img->height * 3; i+=3) {
		a = *(data+0);
		b = *(data+1);
		c = *(data+2);
		*(ptr+0) = a;
		*(ptr+1) = b;
		*(ptr+2) = c;
		//get largest color component...
		//(ptr+3) = (unsigned char)((
		//		(int)*(ptr+0) +
		//		(int)*(ptr+1) +
		//		(int)*(ptr+2)) / 3);
		//d = a;
		//if (b >= a && b >= c) d = b;
		//if (c >= a && c >= b) d = c;
		//(ptr+3) = d;
		*(ptr+3) = (a|b|c);
		ptr += 4;
		data += 3;
	}
	return newdata;
}

void image_opengl(void)
{

	int h, w;
    glClear(GL_COLOR_BUFFER_BIT);
	//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.0f);

	//glBindTexture(GL_TEXTURE_2D, 0);
	glEnable(GL_TEXTURE_2D);

//	glBindTexture(GL_TEXTURE_2D, 0);

    castleImage = &img[0];
    barImage = &img[1];
    backImage = &img[2];
    zombieImage = &img[3];
    logoImage = &img[4];

	glGenTextures(1, &castleTex);
    glGenTextures(1, &barTex);
    glGenTextures(1, &backTex);
    glGenTextures(1, &zombieTex);
    glGenTextures(1, &logoTex);
    //---------------------
    //castle
	w = castleImage->width;
	h = castleImage->height;
	glBindTexture(GL_TEXTURE_2D, castleTex);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, w, h, 0,GL_RGB, GL_UNSIGNED_BYTE, castleImage->data);
     //---------------------
    //bar
	w = barImage->width;
	h = barImage->height;
	glBindTexture(GL_TEXTURE_2D, barTex);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, w, h, 0,GL_RGB, GL_UNSIGNED_BYTE, barImage->data);
   
   
   
   //----------------------------
    //background
    w = backImage->width;
    h = backImage->height;
    glBindTexture(GL_TEXTURE_2D, backTex);
   	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, w, h, 0,GL_RGB, GL_UNSIGNED_BYTE, backImage->data);
 //----------------------------
  //zombie
    w = zombieImage->width;
    h = zombieImage->height;
    glBindTexture(GL_TEXTURE_2D, zombieTex);
   	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, w, h, 0,GL_RGB, GL_UNSIGNED_BYTE, zombieImage->data);
    //-----------------------
    //logo
    w = logoImage->width;
    h = logoImage->height;
    glBindTexture(GL_TEXTURE_2D, logoTex);
   	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, w, h, 0,GL_RGB, GL_UNSIGNED_BYTE, logoImage->data);



	//glBindTexture(GL_TEXTURE_2D, 0);
}


void printName()
{
 	Rect c;
    c.bot = 820;
    c.left = 200;
	c.center = 0;
	ggprint8b(&c, 16, 0x00ffff00, "christy");
}

void iTex(int x, int y)
{
 //-----------background
    glClearColor(1.0, 1.0, 1.0, 1.0);
	//glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
   	glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.0f);
    glBindTexture(GL_TEXTURE_2D, backTex);
	glBegin(GL_QUADS);
    //float w = (730.0/1250.0);
    //float h = (526.0/900.0);
        glTexCoord2f(0.0f, 1.0); glVertex2i(0, 0);
	    glTexCoord2f(0.0f, 0.0f); glVertex2i(0, y);
		glTexCoord2f(1.0, 0.0f); glVertex2i(x, y);
		glTexCoord2f(1.0, 1.0); glVertex2i(x, 0);        
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_ALPHA_TEST);
    glPopMatrix();

   //---------castle brick bar
    glClearColor(1.0, 1.0, 1.0, 0.8);
   // glClear(GL_COLOR_BUFFER_BIT);
  //  glColor3f(0.6f, 0.6f, 0.6f);
    glPushMatrix();
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.0f);
    glBindTexture(GL_TEXTURE_2D, barTex);
    glBegin(GL_QUADS);
        //bl
		glTexCoord2f(0.0f, 0.0f); glVertex2f(0,50);
        //ul
		glTexCoord2f(0.0f, 1.0f);glVertex2f(x-x,y-60);
        //ur
		glTexCoord2f(1.0f, 1.0f);glVertex2f(x-1150,y-60);
        //br
		glTexCoord2f(1.0f, 0.0f);glVertex2f(x-1150,50);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_ALPHA_TEST);
    glPopMatrix();
 
 //------actual castle
    
    glClearColor(1.0, 1.0, 1.0, 0.8);
    glPushMatrix();
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.0f);
    glBindTexture(GL_TEXTURE_2D, castleTex);
    glBegin(GL_QUADS);
        //bl
		glTexCoord2f(0.0f, 0.0f); glVertex2f(-20,250);
        //ul
		glTexCoord2f(0.0f, 1.0f);glVertex2f(-20,y-250);
        //ur
		glTexCoord2f(1.0f, 1.0f);glVertex2f(x-1150,y-250);
        //br
		glTexCoord2f(1.0f, 0.0f);glVertex2f(x-1150,250);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_ALPHA_TEST);
    glPopMatrix();
}

void logoTexture(int x, int y){
    //---------logo
    glClearColor(1.0, 1.0, 1.0, 0.8);
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.0f);
    glBindTexture(GL_TEXTURE_2D, logoTex);
    glBegin(GL_QUADS);
	    glTexCoord2f(1.0f, 1.0f);glVertex2f(x-190,y-300);
		glTexCoord2f(1.0f, 0.0f);glVertex2f(x-190, 100);
    	glTexCoord2f(0.0f, 0.0f); glVertex2f(190,100);
		glTexCoord2f(0.0f, 1.0f);glVertex2f(190,y-300);
	glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_ALPHA_TEST);
    glPopMatrix();


      

}

void zomTex(){
    float width = 30.0f;
    //glEnable(GL_TEXTURE_2D);
    glClearColor(1.0, 1.0, 1.0, 0.8);
    glPushMatrix();
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.0f);
    glBindTexture(GL_TEXTURE_2D, zombieTex);
    glBegin(GL_QUADS);
        
		glTexCoord2f(0.0f, 1.0f); glVertex2f(-width,-width);
        
		glTexCoord2f(0.0f, 0.0f);glVertex2f(-width,width);
        
		glTexCoord2f(1.0f, 0.0f);glVertex2f(width,width);
        
		glTexCoord2f(1.0f, 1.0f);glVertex2f(width,-width);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_ALPHA_TEST);
    glPopMatrix();
    
}

    
/*void header(int x, int y){
    glColor3ub(100, 100, 160);
    glPushMatrix();
    glBegin(GL_QUADS);
         //bottom left
        glVertex2f(x-x,y-60);
        //upper left
         glVertex2f(x-x,  y);
        //upper right
        glVertex2f(   x,y);
        //bottom right
       glVertex2f(    x,y-60);
    glEnd();
    glPopMatrix();
}*/
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



















