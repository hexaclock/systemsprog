#include "myselect.h"

/*
 *underends current pos, underlines one directly below
*/
void movedown()
{
  refreshout(gl_env.pos);
  ++gl_env.pos;
  if ( gl_env.nbelems==1 || gl_env.pos >= gl_env.nbelems )
    gl_env.pos = 0;
  refreshin();
}
