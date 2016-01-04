#include "my.h"

/*
 *pre: takes a char* and search term char
 *post: returns index of last match.
 *returns -1 if no match.
*/
int my_strrindex(char *s, char c)
{
  unsigned int i;
  unsigned int curmatch;
  char found;

  if(s != NULL)
    for(i=0,found=0; s[i] != '\0'; ++i)
      if(s[i] == c)
	{
	  curmatch = i;
	  found = 1;
	}
  if (found==1)
    return curmatch;
  return -1;
}
