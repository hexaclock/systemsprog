#include "myselect.h"

/*
 *turns of highlighting
*/
void term_standend()
{
  tputs(gl_env.stand_end,1,my_termprint);
}
