#include "myselect.h"

/*
 *underends the current pos, underlines one to the right
*/
void moveright()
{
  refreshout(gl_env.pos);
  gl_env.pos += gl_env.win.ws_row;
  if ( gl_env.nbelems == 1 )
    gl_env.pos = 0;
  else if ( gl_env.pos > gl_env.nbelems )
    gl_env.pos = gl_env.nbelems-1;
  refreshin();
}
