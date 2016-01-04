#include "my.h"

/*
 *pre: takes char *s1, char *s2
 *post: compares them. returns -1 if s1<s2, 1 if s1>s2, 0 if s1==s2
 */
int my_strcmp(char *s1, char *s2)
{
  int i;

  if (s1 == NULL && s2 != NULL)
    return -1;
  if (s1 == NULL && s2 == NULL)
    return 0;
  if (s1 != NULL && s2 == NULL)
    return 1;

  for (i=0; s1[i]!='\0'; ++i)
    {
      if (s1[i] < s2[i])
	return -1;
      if (s1[i] > s2[i])
	return 1;
    }
  /*we've reached the end of the first string, but need to check
   *for cases like "hell","hello"*/
  if ( (s1[i] == '\0') && (s2[i] != '\0') )
    return -1;
  if ( (s1[i] != '\0') && (s2[i] == '\0') )
    return 1;
  return 0;
}
