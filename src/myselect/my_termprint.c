#include "myselect.h"

/*
 *pre: takes an integer int i
 *post: prints i to screen
*/
int my_termprint(int i)
{
  return write(1,&i,1);
}
