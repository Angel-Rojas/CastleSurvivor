/*
 * nygel aton
 *
 *
 */
#include "Common.h"
#include "nygelA.h"
#include "fonts.h"
#include <ctime>
//globals
int castleHealth;
int actualHealth;

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

int castleHealthToStates(int ch,int fullCh)
{
    //ch is castle health its the one actually decreasing
    //fullCH is castle health if full, should never change
    //full-75% health
    if(ch >(fullCh/75))
	return 1;
    //75-50% health
    else if((fullCh/75) >= ch || ch > 50)
	return 2;
    //50-25% health
    else if((fullCh/50) >= ch || ch > 25)
	return 3;
    //dead
    else
	return 4;
}

int attackLoop(int zombies,int state)
{

    //attack loop
    for(int i = 0; i < zombies; i++){
	actualHealth -= 5;
	state = castleHealthToStates(castleHealth,actualHealth);
    }
    //random math function to slow down so act as a sleep
    int x = 100;
    for (int i=0; i < 3000; i++){
	x = x % 3 * 1.24 + 76.0 * x;
    }
    return state;
}
/*void zombieDemensions(Vec &a){
    a->vert[0][0] = 0;
    a->vert[0][1] = 0;
    a->vert[1][0] = 30;
    a->vert[1][1] = 0;
    a->vert[2][0] = 30;
    a->vert[2][1] = 70;
    a->vert[3][0] = 0;
    a->vert[3][1] = 70;

} */

//void checkDeleteZombies(Asteroids &a, Bullet &b){

//}
