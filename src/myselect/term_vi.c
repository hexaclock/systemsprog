#include "myselect.h"

/*
 *turns cursor off
*/
void term_vi()
{
  tputs(VICAP,1,my_termprint);
}
