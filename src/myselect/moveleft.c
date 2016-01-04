#include "myselect.h"

/*
 *underends the current position, underlines the one directly to the left
*/
void moveleft()
{
  refreshout(gl_env.pos);
  gl_env.pos -= gl_env.win.ws_row;
  if ( gl_env.nbelems == 1 )
    gl_env.pos = 0;
  else if ( gl_env.pos < 0 )
    gl_env.pos = 0;
  refreshin();
}
