#include "my.h"

/*
 *pre: takes an int and a char*
 *post: prints int in base specified by char*
*/
void my_num_base(int i, char *s)
{
  unsigned int frombase;
  unsigned int tobase;
  unsigned int maxponent;
  unsigned char p;
  tobase = my_strlen(s);
  frombase = i;

  if (s==NULL || tobase==0)
    {
      my_str("Base not valid\n");
      return;
    }
  if (i<0)
    {
      my_char('-');
      frombase = ~i + 1;
    }
  if (i==0)
    {
      my_char(s[i]);
      return;
    }
  if (tobase == 1)
    {
      for(;frombase>0;--frombase)
	my_char(s[0]);
      return;
    }
  /*my_int(frombase);*/
  for (maxponent=1; maxponent<frombase; maxponent*=tobase)
      ;
  p = 0;
  while (maxponent>0)
    {
      /* if statement gets rid of prefix 0 */
      if (!( (p == 0) && ((frombase / maxponent) == 0) ))
	{
	  my_char(s[(frombase / maxponent)]);
	  frombase -= (maxponent*(frombase/maxponent));
	}
      p = 1;
      maxponent = maxponent / tobase;
    }
}
