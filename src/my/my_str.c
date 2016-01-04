#include "my.h"

/*
 *pre: takes a char*, character array, or string
 *post: prints it
*/
void my_str(char * s)
{
  if (s != NULL)
    for(; *s!='\0'; ++s)
      my_char(*s);
}
