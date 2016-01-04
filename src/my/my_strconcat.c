#include "my.h"
/*
 *pre: takes a char *s1, and a char *s2
 *post: creates a new string of s1 and s2.
 * returns pointer to the new string.
 */
char *my_strconcat(char *s1, char *s2)
{
  unsigned int lens1;
  unsigned int lens2;
  unsigned int i;
  char *ret;

  lens1 = my_strlen(s1);
  lens2 = my_strlen(s2);

  if (s1 == NULL)
    lens1 = 0;
  if (s2 == NULL)
    lens2 = 0;

  ret = (char *)xmalloc((lens1+lens2+1)*sizeof(char));

  if (s1 != NULL)
    for(i=0; i < lens1; ++i)
      ret[i] = s1[i];

  if (s2 != NULL)
    for(i=0; i <= lens2; ++i)
      ret[i+lens1] = s2[i];

  if (s1 == NULL && s2 == NULL)
    return NULL;

  return ret;
}
