#include "my.h"
/*
 *pre: takes a char *s, and a char c to look for.
 *post: returns a pointer to the last index at which c occurs in s.
 */
char *my_strrfind(char *s, char c)
{
  char *ret = NULL;
  if (s != NULL)
    for (; *s != '\0'; ++s)
      if (*s == c)
	ret = s; 
  return ret;
}
