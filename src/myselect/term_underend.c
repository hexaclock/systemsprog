#include "myselect.h"

/*
 *disables underlining
*/
void term_underend()
{
  tputs(gl_env.under_end,1,my_termprint);
}
