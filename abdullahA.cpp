/*
by: Abdullah Aljahdali
*/
#include "abdullahA.h"


void makeButton(char *title,
                       float x,
                       float y,
                       float w,
                       float h,
                       void (*action)(),
                       Button *b) {
    // Button *b = (Button*)malloc(sizeof(Button));
    strcpy(title, b->title);
    b->x = x;
    b->y = y;
    b->width = w;
    b->height = h;
    b->action = action;
    b->active = 0;
    return b;
}

int isPointerInsideButton(float x, float y, Button *b) {
  return (b->x < x && x < b->x+b->w && b->y < y && y < b->y+b->h);
}

void logGameStatus(int type) {
  char *status;

  switch (type) {
    case PLAYING:
      printf("Current status is: PLAYING\n");
      break;

    case PAUSING:
      printf("Current status is: PAUSING\n");
      break;

    case NEW_GAME:
      printf("Current status is: NEW_GAME\n");
      break;

    default: printf("Current status is: Unknown(%d)\n", type);
  }
}

void logWaveLevel(int type) {
  char *status;

  switch (type) {
    case WAVE_I:
    printf("Current wave level is: 1st\n");
      break;

    case WAVE_II:
    printf("Current wave level is: 2ed\n");
      break;

    case WAVE_III:
    printf("Current wave level is: 3rd\n");
      break;

    case WAVE_IV:
    printf("Current wave level is: 4th\n");
      break;

    case WAVE_V:
    printf("Current wave level is: 5th\n");
      break;

    case WAVE_VI:
    printf("Current wave level is: 6th\n");
      break;
    case WAVE_VII:
    printf("Current wave level is: 7th\n");
      break;

    case WAVE_IIX:
    printf("Current wave level is: 8th\n");
      break;

    case WAVE_IX:
    printf("Current wave level is: 9th\n");
      break;

    case WAVE_X:
    printf("Current wave level is: 10th\n");
      break;

    default: printf("Unsupported wave level");
  }
}



void reinitGameLevel(int waveLevel) {
	switch waveLevel {
		case WAVE_I: {
			// logWaveLevel(WAVE_I);
			// //build 15 asteroids...
			// for (int j=0; j<((waveLevel+1)*ZOMBIES_PER_WAVE); j++) {
			// 	Asteroid *a = new Asteroid;
			// 	a->nverts = 4;
			// 	//zombies are randomized based on ZOMBIES_WIDTH x ZOMBIES_HEIGHT
			// 	a->vert[0][0] =
			// 	a->vert[0][1] =
			// 	a->vert[1][1] =
			// 	a->vert[3][0] = 0;
			// 	a->vert[1][0] =
			// 	a->vert[2][0] = rand()%(ZOMBIES_WIDTH*(waveLevel+1))+ZOMBIES_WIDTH;
			// 	a->vert[2][1] =
			// 	a->vert[3][1] = rand()%(ZOMBIES_HEIGHT*(waveLevel+1))+ZOMBIES_HEIGHT;
			// 	//initializing zombie postion-----------------------
			// 	a->pos[0] = zombie_pos;
			// 	a->pos[1] = (Flt)(rand() % gl.yres - 145);
			// 	a->pos[2] = 0.0f;
			// 	a->angle = 0.0;
			// 	a->rotate = rnd() * 4.0 - 2.0;
			// 	a->color[ZERO] = rnd() + 0.4;
			// 	a->color[1] = rnd() + 0.3;
			// 	a->color[2] = rnd() + 0.2;
			// 	a->vel[0] = -1;//(Flt)(rnd()*2.0-1.0);
			// 	a->vel[1] = (Flt)(rnd()*2.0-1.0);
			// 	//std::cout << "asteroid" << std::endl;
			// 	//add to front of linked list
			// 	a->next = ahead;
			// 	if (g.ahead != NULL)
			// 		g.ahead->prev = a;
			// 	g.ahead = a;
			// 	++g.nasteroids;
			}
		}
		break;
		default
	}
}


int buttonPressed(int x, int y, int game_mode) {
  // if (game_mode!=PLAYING) {
  //   if (y>=320&&y<=345&&x>=555&&x<=705) {
  //     return PLAYING;
  //     // printf("pressed Game_mode(1)\n");
  //   }
  //   else if (y>=370&&y<=395&&x>=555&&x<=705) {
  //     return CREDITS;
  //     // printf("pressed Game_mode(5)\n");
  //   }
  // } else {
  //   if (x>=0&&x<=1249&&y>=0&&y<=90) {
  //     return PAUSED;
  //     // printf("pressed Game_mode(2)\n");
  //   }
  // }
  return -1;
}
