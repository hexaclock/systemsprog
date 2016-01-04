#include "myselect.h"

/*
 *takes a char c that's either a \n or a space
 *prints highlighted elements if a \n, or if an ESC just exits.
*/
void getout(char c)
{
  int i;
  if (c == '\n')
    {
      restore_terminal();
      for (i=0; i<gl_env.nbelems; ++i)
	{
	  if (gl_env.elements[i].mode)
	    {
	      my_str(gl_env.elements[i].elem);
	      my_str(" ");
	    }
	}
      exit(0);
    }
  else
    {
      restore_terminal();
      exit(0);
    }
    
}
