#include "myselect.h"

/*
 *clears the terminal screen
*/
void term_clear()
{
  tputs(gl_env.clear,1,my_termprint);
}
