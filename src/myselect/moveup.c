#include "myselect.h"

/*
 *underends the current position, underlines the one above
*/
void moveup()
{
  refreshout(gl_env.pos);
  --gl_env.pos;
  if ( gl_env.nbelems == 1 )
    gl_env.pos = 0;
  else if ( gl_env.pos < 0 )
    gl_env.pos = gl_env.nbelems-1;
  refreshin();
}
