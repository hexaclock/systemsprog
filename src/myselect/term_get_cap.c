#include "myselect.h"

/*
 *pre: takes a char *cap for the sane human representation of the termcap
 *post: returns the actual string representation of the termcap
*/
char *term_get_cap(char *cap)
{
  char area[2048];
  char *str;
  
  if ( (str = tgetstr(cap,(char **)&area) ) == NULL )
    my_panic("Could not get area of terminal",2);
  return str;
}
