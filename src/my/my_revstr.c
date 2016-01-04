#include "my.h"

/*
 *pre: takes a char*
 *post: reverses it in place
*/
int my_revstr(char *s)
{
  unsigned int lastidx;
  unsigned int length;
  char tmp;
  char *st;
  char *end;
  length = my_strlen(s);
  lastidx = length-1;

  if (s == NULL)
    return -1;
  if (lastidx == -1)
    return 0;
  if (length == 2)
    {
      tmp = s[0];
      s[0] = s[1];
      s[1] = tmp;
      return length;
    }
  if (length % 2 == 0)
    {
    for(st=s,end=s+lastidx; st<=end; ++st,--end)
      {
	tmp = *st;
	*st = *end;
	*end = tmp;
      }
    }
  else
    {
      for(st=s,end=s+lastidx; st!=end; ++st,--end)
	{
	  tmp = *st;
	  *st = *end;
	  *end = tmp;
	}
    }
  return length;
}
