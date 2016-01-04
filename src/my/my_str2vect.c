#include "my.h"

/*
 *pre: takes a string with spaces (char *)
 *post: returns a vector (char **) of strings
*/
char **my_str2vect(char *s)
{
  char **ret;
  char **retbak;
  char *starts;
  char *sbak;
  unsigned int numsubs;

  if (s == NULL)
    {
      return NULL;
    }
  if (my_strcmp(s,"")==0)
    {
      ret = (char **)(xmalloc(sizeof(char *)));
      *ret = NULL;
      return ret;
    }
  /* ignore leading spaces */
  for (starts=s; *s==' '; s++)
    ;
  for (starts=s,numsubs=0; *(s+1)!='\0'; s++)
    if ( (*s == ' ' || *s == '\t' || *s == '\n') &&  (*(s+1) != '\t' ||  *(s+1) != ' ' || *(s+1) != '\n') )
      numsubs++;
  ret = (char **)(xmalloc((numsubs+2)*sizeof(char *)));
  
  for (s=starts,retbak = ret; *starts!='\0'; s++)
    {
      if ( (*s == '\0') || (*s == ' ') || (*s == '\n') || (*s == '\t') )
	{
	  *ret = (char *)(xmalloc((s-starts)*sizeof(char)));
	  for (sbak = *ret; starts<s; starts++,(*ret)++)
	    if (*starts != ' ')
	      **ret = *starts;
	  **ret = '\0';
	  *ret = sbak;
	  starts++;
	  if (my_strcmp(*ret,"") != 0 && my_strcmp(*ret," ") != 0 && my_strcmp(*ret,"\t") && my_strcmp(*ret,"\n"))
	    ret++;
	  else
	    free(*ret);
	}
    }
  
  *ret = NULL;
  return retbak;
}
