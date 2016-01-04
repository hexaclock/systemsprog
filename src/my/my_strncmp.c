#include "my.h"

/*
 *pre: takes a char *s1, char *s2, and unsigned int n.
 *post: compares the first n bytes of each.
 *returns -1 if s1<s2, 0 if s1==s2, 1 if s1>s2
 */
int my_strncmp(char *s1, char *s2, unsigned int n)
{
  int i;

  if (s1 == NULL && s2 != NULL)
    return -1;
  if (s1 == NULL && s2 == NULL)
    return 0;
  if (s1 != NULL && s2 == NULL)
    return 1;
  if (n == 0)
    return 0;

  for (i=0; i<n; ++i)
    {
      if (s1[i] < s2[i])
	return -1;
      if (s1[i] > s2[i])
	return 1;
      if ((s1[i] == '\0') && (s2[i] != '\0'))
	return -1;
      if ((s1[i] != '\0') && (s2[i] == '\0'))
	return 1;
    }
  return 0;
}
