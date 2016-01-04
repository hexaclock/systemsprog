#include "my.h"

/*
 *pre: takes a char
 *post: prints the char
*/
void my_char(char c)
{
  write(1,&c,1);
}
