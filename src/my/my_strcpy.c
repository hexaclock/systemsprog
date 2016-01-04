#include "my.h"

/*
 *pre: takes a dst buffer and src buffer (both char*)
 *post: copies all of src to dst, overwriting anything in dst.
 *returns dst.
 */
char *my_strcpy(char *dst, char *src)
{
  unsigned int i;

  if (dst == NULL)
    return NULL;
  if (src == NULL)
    return dst;

  for (i=0; src[i] != '\0'; ++i)
    {
      dst[i] = src[i];
    }
  dst[i] = '\0';
  return dst;
}
