/*
 * nygel aton
 *
 *
 */
#include "Common.h"
#include "nygelA.h"
#include "fonts.h"
#include <ctime>
void hello()
{
    cout << "Hello World!" << endl;
    return;
}
extern double timeDiff(struct timespec *start, struct timespec *end);
extern void timeCopy(struct timespec *dest, struct timespec *source);
double randomMath()
{
    struct timespec start,stop;
    static double b =0;
    clock_gettime(CLOCK_REALTIME, &start);
    
    long int top = 10e11;
    for(int i =0;i<100;i++){
	top/=7;
    }
     clock_gettime(CLOCK_REALTIME, &stop); 
    b += timeDiff(&start,&stop); 
return b;
}
void timerN (double ts)
{
    //smallest time unti 10^-9s
    //timer is 2mins
  //  randomMath();
  

    static double timeLeft = 1.2e11;
    Rect r; 
    r.bot = 500;
    r.left = 80;
    r.center = 0;
    ggprint8b(&r, 16, 0x00ff0000,"Nygel");
    ggprint8b(&r, 16, 0x00ff0000,"TIME : %lf",(randomMath()));
    ggprint8b(&r, 16, 0x00ff0000,"TIME LEFT: %f",(timeLeft-randomMath()));
}

bool waveCountDown (int xres, int yres)
{
    //smallest time unti 10^-9s
    //timer is 2mins
  //  randomMath();
  

    static double timeLeft = 6000;
    Rect r; 
    r.bot = yres-100;
    r.left = xres/2;
    r.center = 0;
    ggprint8b(&r, 16, 0x00ff0000,"TIME LEFT: %f",timeLeft);
    timeLeft--;
    if(timeLeft == 0 ){
	timeLeft = 6000;
	return false;
    }
    else
	return true;
}
