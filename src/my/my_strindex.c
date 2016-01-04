#include "my.h"

/*
 *pre: takes a char* and search term char
 *post: returns index of first match from front.
 *returns -1 if no match.
*/
int my_strindex(char *s, char c)
{
  unsigned int i;
  if (s!=NULL)
    for(i=0; s[i] != '\0'; ++i)
      if(s[i] == c)
	return i;
  return -1;
}
