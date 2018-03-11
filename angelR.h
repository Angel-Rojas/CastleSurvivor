/*
 * Angel Rojas's functions
 * filename: angelR.h
 */
#ifndef _ANGEL_FUNCS_
#define _ANGEL_FUNCS_
void printWelcome();
void zombieKillCount(int,int);
int incrementZombiesKilled(int&);
float initZombiePosition(int,int&);
double angelsTimer(int,int);
void timerBox(int&,int&);
void displayMenu(int,int);
void pauseGame(int,int);
void endGameScreen();
void endTheGame(int&,bool&,int&);
void stateHitOnce(int&);
void stateHitTwice(int&);
void stateHitThrice(int&);
void statePlayerDead(int&);
extern int zombie_pos;

#endif

