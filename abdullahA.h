/*
by: Abdullah Aljahdali
*/

#ifndef _ABDULLAH_ALJAHDALI_
#define _ABDULLAH_ALJAHDALI_
#include "Common.h"


enum GameStatus {
  NEW_GAME = 0,
  PLAYING = 1,
  PAUSED = 2,
  END_GAME = 3,
  GAME_OVER = 4,
  CREDITS = 5,
};

// enum Buttons {
//   END_GAME = 0,
//   PLAYING = 1,
//   CREDITS = 2,
// };

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
  void (*action)();
};

void makeButton(char *title, float x, float y, float w, float h, void (*action)(), Button *b);
int isPointerInsideButton(float x, float y, Button *b);
void logGameStatus(int type);
void logWaveLevel(int type);
void reinitGameLevel(int waveLevel);
int buttonPressed(int x, int y, int game_mode);
#endif
