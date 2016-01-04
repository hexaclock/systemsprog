#include "my.h"

/*
 *usage: char *s = (char *)xmalloc(n * sizeof(char));
 *takes an int n
 *allocates n bytes of memory and returns a pointer to the start
 *of the allocation.
 */

void *xmalloc(int n)
{
  void *p = NULL;
  if (!(p=malloc(n)))
    {
      my_str("Virtual memory exhausted.");
      exit(1);
    }
    return p;
}
