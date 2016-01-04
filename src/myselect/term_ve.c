#include "myselect.h"

/*
 *turns cursor on
*/
void term_ve()
{
  tputs(VECAP,1,my_termprint);
}
