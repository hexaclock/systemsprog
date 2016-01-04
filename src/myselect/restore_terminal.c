#include "myselect.h"

/*
 *restores saved capabilities of terminal when myselect was started
*/
void restore_terminal()
{
  struct termio line;
  line = gl_env.line_backup;

  term_clear();
  term_ve();
  ioctl(0,TCSETA,&line);
  dup2(gl_env.stdio_backup,1);
}
