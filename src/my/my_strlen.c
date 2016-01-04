#include "my.h"

/*
 *pre: takes a char*
 *post: returns the length of it
*/
int my_strlen(char *s)
{
  unsigned int i;
  if (s == NULL)
    return -1;
  for (i = 0; s[i] != '\0'; ++i);
  return i;
}
