#include "myselect.h"

/*
 *pre: takes an int i for the number of elements, and the names of the elements as a vector
 *post: sets them into an array of elements
*/
void setup_elems(int i, char **elems)
{
  int numelems;
  
  numelems = i;
  gl_env.elements = (t_elem *)xmalloc((i+4)*sizeof(t_elem));
  gl_env.nbelems = numelems;
  for (i=0; i<numelems; ++i)
    {
      gl_env.elements[i].elem = my_strdup(elems[i]);
      gl_env.elements[i].size = my_strlen(elems[i]);
      gl_env.elements[i].x = 0;
      gl_env.elements[i].y = 0;
      gl_env.elements[i].mode = 0;
    }
  
}
