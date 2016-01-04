#include "myselect.h"

/*
 *pre: takes coordinates int x, int y
 *post: moves to position at x,y
*/
void term_move(int x, int y)
{
  tputs(tgoto(gl_env.move,x,y),1,my_termprint);
}

/*
 *pre: takes a position as int i
 *post: moves position to element at int i
*/
void term_move_to_item(int i)
{
  term_move(gl_env.elements[i].x,gl_env.elements[i].y);
}
