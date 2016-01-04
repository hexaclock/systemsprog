#include "myselect.h"

/*
 *pre: automatically takes a number of args argc, and a vector of arguments argc
 *post: runs myselect
*/
int main(int argc, char **argv)
{
  char readbuf[4];
  int numread;
  unsigned int i;
  
  /* check argc > 1 */
  if (argc <= 1)
    {
      my_str("usage: ");
      my_str(argv[0]);
      my_panic(" <list of strings>",1);
    }
  /* get all cap stuff */
  init_caps();
  /* change I/O settings */
  init_terminal();
  /* setup gl_env elements array */
  setup_elems(argc-1,argv+1);
  /* handle window change */
  signal(SIGWINCH,show_elems);
  /* display the elements */  
  show_elems();
  
  while ( (numread=read(0,readbuf,3)) > 0 )
    {
      readbuf[numread] = '\0';
      (void) check_character(readbuf);
      /* be nice to CPU */
      usleep(1500);
    }
  /* restore termcaps */
  restore_terminal();
  return 0;
}
