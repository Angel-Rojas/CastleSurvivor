/*
by: Abdullah Aljahdali
*/

#ifndef _ABDULLAH_ALJAHDALI_
#define _ABDULLAH_ALJAHDALI_
#include "Common.h"


enum GameStatus {
  PLAYING = 0,
  PAUSING = 1,
  NEW_GAME = 2
};

enum WAVE {
  WAVE_I = 0,
  WAVE_II = 1,
  WAVE_III = 2,
  WAVE_IV = 3,
  WAVE_V = 4,
  WAVE_VI = 5,
  WAVE_VII = 6,
  WAVE_IIX = 7,
  WAVE_IX = 8,
  WAVE_X = 9,
};

struct Button {
  char *title;
  float width;
  float height;
  float x;
  float y;
  int active;
  void (*action)(float, float);
};

void *makeButton(char *title, float x, float y, float w, float h, void (*action)(), Button *b);
int isPointerInsideButton(float x, float y, Button *b);
void logGameStatus(int type);
void logWaveLevel(int type);
void reinitGameLevel(int waveLevel);

#endif
