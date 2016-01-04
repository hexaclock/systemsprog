#include "my.h"

#define MAX 256

/*
 *General notes: fds[0] is for reading, fds[1] is for writing*
*/

/*
 *pre: automatically takes in the amount of arguments passed and their values
 *post: creates a parent and child process, demonstrates piping between grandparent, parent
 *by printing status to screen along the way.
*/
int main(int argc, char **argv)
{
  char  buf[MAX];
  char  childbuf[MAX];
  char  *str;
  int   fds[2];
  int   sdf[2];
  int   pid;

  pipe(fds);

  /* if failed to fork */
  if (argc < 2)
    {
      my_str("Usage: ");
      my_str(argv[0]);
      my_panic(" arg1 [arg2 arg3 ...]\n",-2);
    }
  if ((pid = fork()) < 0)
    my_panic("Failed at first fork\n",-1);

  /* send str through the pipe */
  str = my_vect2str(&argv[1]);
  if (pid > 0)
    {
      close(fds[0]);
      my_str("Grandparent passing string |"); my_str(str); my_str("| to parent\n");
      /* account for NULL/empty string case */
      if (my_strcmp(str,"") != 0)
	write(fds[1], str, my_strlen(str));
      else
	write(fds[1], str, my_strlen(str)+1);
      wait();
    }
  else
    {
      close(fds[1]);
      buf[read(fds[0], buf, MAX-1)] = '\0';
      my_str("Parent got |"); my_str(buf); my_str("| from grandparent.\n");

      /* create new pipe */
      pipe(sdf);

      /* fork child process */
      if ((pid = fork()) < 0)
	my_panic("Failed at second fork\n",-1);
      
      if (pid > 0)
	{
	  /* writing data from buffer to pipe */
	  my_str("Parent passing string |"); my_str(str); my_str("| to child.\n");
	  /* account for NULL/empty string case */
	  if (my_strcmp(buf,"") != 0)
	    write(sdf[1], buf, my_strlen(buf));
	  else
	    write(sdf[1], buf, my_strlen(buf)+1);
	  wait();
	}
      else
	{
	  close(sdf[1]);
	  /* reading data from buf into childbuf */
	  childbuf[read(sdf[0], childbuf, MAX-1)] = '\0';
	  my_str("Child got |"); my_str(childbuf); my_str("| from parent.\n");
	}
    }
  return 0;
}
