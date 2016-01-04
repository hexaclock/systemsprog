#include "my.h"
/*
 *pre: takes a char *s1, char *s2, and unsigned int n
 *post: creates a new string of s1 and the the first n bytes of s2.
 *returns the new string.
 */
char *my_strnconcat(char *s1, char *s2, unsigned int n)
{
  unsigned int lens1, lens2;
  unsigned int i = 0;
  unsigned int j = 0;
  char *ret;

  if (s1 == NULL && s2 == NULL)
    return NULL;

  lens1 = my_strlen(s1);
  lens2 = my_strlen(s2);

  if (s1 == NULL)
    lens1 = 0;

  if (n > lens2)
    n = lens2;

  ret = (char *)xmalloc((lens1+n+1)*sizeof(char));

  if (s1 != NULL)
    for(i=0; s1[i]!='\0'; ++i)
      ret[i] = s1[i];

  if (s2 != NULL)
    for(j=0; j < n; ++j)
      ret[i+j] = s2[j];

  ret[i+j] = '\0';

  return ret;
}
