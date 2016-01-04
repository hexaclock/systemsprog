#include "my.h"

/*
 *pre: takes a char *s1, char *s2
 *post: copies s2 to the end of s1. returns s1.
 */
char *my_strcat(char *s1, char *s2)
{
  unsigned int i;
  unsigned int j;
  if (s1 == NULL || s2 == NULL)
    return s1;
  for (i=0; s1[i] != '\0'; ++i)
    ;
  for (j=0; s2[j] != '\0'; ++i,++j)
    s1[i] = s2[j];

  s1[i+j+1] = '\0';
  return s1;
}
