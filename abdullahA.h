/*
by: Abdullah Aljahdali
*/

#ifndef _ABDULLAH_ALJAHDALI_
#define _ABDULLAH_ALJAHDALI_
#include "Common.h"

struct Button {
  char *title;
  float width;
  float height;
  float x;
  float y;
  void (*action)(float, float):
} typedef struct Button Button;

Button *makeButton(char *title, float x, float y, float w, float h, void (*action)(float, float));
int isPointerInsideButton(float x, float y, Button *b);
#endif
