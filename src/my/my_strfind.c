#include "my.h"
/*
 *pre: takes a char *s, and a char c to find
 *post: returns first pointer to first iteration of c.
 */
char *my_strfind(char *s, char c)
{
  if (s != NULL)
    for (; *s != '\0'; ++s)
      if (*s == c)
	return s; 
  return NULL;
}
