#include "myselect.h"

/*
 *prints all of the elements in the gl_env.elements array nicely
*/
void show_elems()
{
  /* cols */
  int x;
  /* rows */
  int y;
  int i;
  int max;
  
  ioctl(0,TIOCGWINSZ,&gl_env.win);
  term_clear();
  gl_env.flag = 0;
  for (i=0,x=0,y=0,max=0; i<gl_env.nbelems; ++i, ++y)
    {
      if (y >= gl_env.win.ws_row)
	{
	  y = 0;
	  x += (max+3);
	  max = 0;
	}
      if (max < gl_env.elements[i].size)
	{
	  max = gl_env.elements[i].size;
	  if (x+max > gl_env.win.ws_col)
	    {
	      term_clear();
	      my_str("Enlarge window");
	      gl_env.flag = 1;
	      break;
	    }
	}
      gl_env.elements[i].x = x;
      gl_env.elements[i].y = y;
      refreshout(i);
    }
  if (!gl_env.flag)
    refreshin();
}
