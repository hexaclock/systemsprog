#include "my.h"

/*
 *pre: takes a vector (pointer to a char*)
 *post: returns a single char* made up of all of the strings in the vector
*/
char *my_vect2str(char **vect)
{
  char *str;
  char *bstr;
  char **cpvect;
  unsigned int bufsize;

  if (vect != NULL)
    {
      for (cpvect = vect; *cpvect != NULL; cpvect++)
	bufsize += (my_strlen(*cpvect) + 1);
      
      str = (char *)(xmalloc(bufsize+1));
      bstr = str;
      for (; *vect != NULL; vect++)
	{
	  for (; **vect != '\0'; (*vect)++)
	    {
	      *str = **vect;
	      str++;
	    }
	  *str = ' ';
	  str++;
	}
      *(--str) = '\0';
      return bstr;
    }
  return "";
}
  
