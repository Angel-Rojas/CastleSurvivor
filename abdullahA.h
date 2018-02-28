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
  void (*action)(float, float):
} typedef struct Button Button;

Button *makeButton(char *title, float w, float h, void (*action)(float, float));

#endif
