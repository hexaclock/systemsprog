#include "my.h"

/*
 *pre: takes a char *
 *post: copies it to a new memory address and return a pointer to it
 */
char *my_strdup(char *s)
{
  unsigned int i;
  unsigned int slen;
  char *ret;
  if (s == NULL)
    return NULL;
  slen = my_strlen(s);
  ret = (char *)xmalloc((1+slen) * sizeof(char)); 
  for (i=0; i<=slen+1; ++i)
    ret[i] = s[i];
  return ret;
}
