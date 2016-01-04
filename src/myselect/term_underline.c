#include "myselect.h"

/*
 *turns on highlighting
*/
void term_underline()
{
  tputs(gl_env.underline,1,my_termprint);
}
