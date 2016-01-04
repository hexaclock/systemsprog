#include "my.h"

/*
 *pre: takes an int
 *post: prints an int
*/
void my_int(int n)
{
  unsigned int revnum, tmp;
  tmp = n;
  if (n<0)
    {
      my_char(45);
      tmp = ~n + 1;
    }
  for(revnum = 1; revnum<=(tmp/10); revnum = revnum*10)
    ;
  for(; revnum>0; tmp=tmp%revnum,revnum=revnum/10)
    my_char(48+(tmp/revnum));
}
