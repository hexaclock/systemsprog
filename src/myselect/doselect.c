#include "myselect.h"

/*
 *toggles highlighting on current position
*/
void doselect()
{
  if (gl_env.elements[gl_env.pos].mode)
    gl_env.elements[gl_env.pos].mode = 0;
  else
    {
      gl_env.elements[gl_env.pos].mode = 1;
      movedown();
    }
  refreshin();
}
