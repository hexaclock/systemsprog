#include "myselect.h"

/*
 *turns on highlighting
*/
void term_standout()
{
  tputs(gl_env.standout,1,my_termprint);
}
