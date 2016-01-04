#include "my.h"
/*
 *pre: takes a char *s, and an unsigned int n.
 *post: prints the char *s, and exits with error code n.
 */
void my_panic(char *s, unsigned int n)
{
  if (s != NULL)
    my_str(s);
  exit(n);
}
