#include "my.h"

/*
 *pre: takes a dst buffer, src buffer (both char *), and an unsigned int
 *post: copies the first n bytes of src into dst, overwriting the first n bytes of dst.
 returns a pointer to dst.
*/
char *my_strncpy(char *dst, char *src, unsigned int n)
{
  unsigned int i;

  if (dst == NULL)
    return NULL;
  if (src == NULL)
    return dst;

  for (i=0; i < n; ++i)
    {
      dst[i] = src[i];
      if (src[i] == '\0')
	return dst;
    }
  return dst;
}
