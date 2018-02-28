/*
by: Abdullah Aljahdali
*/


Button *makeButton(char *title,
                       float w,
                       float h,
  void (*action)(float, float)) {
    Button *b = (Button*)malloc(sizeof(Button));
    strcpy(title, b->title);
    b->width = w;
    b->height = h;
    b->action = action;
}
