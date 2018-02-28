/*
by: Abdullah Aljahdali
*/


Button *makeButton(char *title,
                       float x,
                       float y,
                       float w,
                       float h,
  void (*action)(float, float)) {
    Button *b = (Button*)malloc(sizeof(Button));
    strcpy(title, b->title);
    b->x = x;
    b->y = y;
    b->width = w;
    b->height = h;
    b->action = action;
}

int isPointerInsideButton(float x, float y, Button *b) {
  return (b->x < x && x < b->x+b->w && b->y < y && y < b->y+b->h);
}
void logGameStatus(int type) {
  char *status;

  switch (type) {
    case PLAYING:
      printf("Current status is: playing\n");
      break;

    case PLAYING:
      printf("Current status is: playing\n");
      break;

    case PLAYING:
      printf("Current status is: playing\n");
      break;

    default: printf("Current status is: Unkown(%d)\n", type);
  }
}
