#include "myselect.h"

/*
 *sets terminal options - turns off all unneeded features
*/
void init_terminal()
{
  struct termio line;
  char *name;
  int fd;

  ioctl(0,TCGETA,&line);
  gl_env.line_backup = line;
  line.c_lflag &= ~(ICANON|ISIG|ECHO);
  line.c_cc[VMIN] = READMIN;
  line.c_cc[VTIME] = READTIME;
  ioctl(0,TCSETA,&line);
  if (ttyname(0) != NULL)
    name = ttyname(0);
  else
    my_panic("Terminal not found",1);
  fd = open(name,O_WRONLY);
  gl_env.stdio_backup = dup(1);
  dup2(fd,1);
  term_vi();
  /*init_caps();*/
}
