

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
Image img[1] = {"images/castlebricks.jpg"};
GLuint castleTex;
Image *castleImage = NULL;

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
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_COLOR_MATERIAL);
	glBindTexture(GL_TEXTURE_2D, 0);

	glEnable(GL_TEXTURE_2D);
	castleImage = &img[0];
	glGenTextures(1, &castleTex);
 
	w = castleImage->width;
	h = castleImage->height;
	glBindTexture(GL_TEXTURE_2D, castleTex);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, w, h, 0,GL_RGB, GL_UNSIGNED_BYTE, castleImage->data);

	glBindTexture(GL_TEXTURE_2D, 0);
}


void printName()
{
 	Rect c;
    c.bot = 820;
    c.left = 200;
	c.center = 0;
	ggprint8b(&c, 16, 0x00ffff00, "christy");
}
/*void hCircle()
{
    glColor3ub(10,100,160);
    t_bsphere s;
    s.center = 0;
    s.radius = 20;
    s.radiusSqr = 20;
}*/


void header(int xRES, int yRES)
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
}

void castle(int x, int y, int w, int h){
  
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.6f, 0.6f, 0.6f);
  //  glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, castleTex);
    glBegin(GL_QUADS);
        //bl
		glTexCoord2f(0.0f, 0.0f);
        glVertex2f(x,y);
        //ul
		glTexCoord2f(0.0f, 1.0f);
        glVertex2f(x,h);
        //ur
		glTexCoord2f(1.0f, 1.0f);
        glVertex2f(w,h);
        //br
		glTexCoord2f(1.0f, 0.0f);
        glVertex2f(w,y);
    glEnd();
	
    glBindTexture(GL_TEXTURE_2D, 0);
//    glPopMatrix();
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
void resizeAstroid(){
	
}

















