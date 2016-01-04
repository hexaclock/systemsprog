#include "my.h"

/*
 *pre: takes a char *
 *post: returns the first number it finds in the string (respects signs).
 *always returns 0 if s is NULL, "", or there is no number in s
*/
int my_atoi(char *s)
{
  int acc;
  int sign;
  char sch;
  if ( s == NULL || (my_strcmp(s,"") == 0) )
    return 0;
  
  for (acc=0,sch=0,sign=1; *s != '\0'; s++)
    {
      if (*s >= '0' && *s <= '9')
	{
	  while (*s  >= '0' && *s <= '9')
	    {
	      acc = 10*acc;
	      acc += *(s++) - 48;
	    }
	  return acc * (int)sign;
	}
      else if (*s == '+' || *s == '-')
	{
	  if (*s == '-')
	      sign *= -1;
	  sch = 1;
	}
      else if (sch)
	return 0;

    }
  return 0;
}
