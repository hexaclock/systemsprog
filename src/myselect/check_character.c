#include "myselect.h"

/*
 *pre: takes a char * for the keypress
 *post: performs the correct function based on keypress
*/
char check_character(char *c)
{
  if (!my_strcmp(c,KU))
    moveup();
  else if (!my_strcmp(c,KD))
    movedown();
  else if (!my_strcmp(c,KR))
    moveright();
  else if (!my_strcmp(c,KL))
    moveleft();
  else if (!my_strcmp(c," "))
    doselect();
  else if (!my_strcmp(c,"\n"))
    getout('\n');
  else if (*c == ESC)
    getout(ESC);
  return 0;
}
