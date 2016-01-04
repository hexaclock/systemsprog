#include "my.h"

#define MAX 512

/*
 *pre: does not take any arguments..
 *post: when run, you get a working (minimal shell) that can be used to execute other commands.
*/
int main()
{
  char buf[MAX];
  char **vect;
  int pid;
  int n;
  int chd;
  unsigned int i;
  
  my_char('\n');
  while (1)
    {
      for (i=0; i<MAX; i++)
	buf[i] = '\0';
      my_str("> ");
      n = read(0, buf, MAX-1);
      if (n<0)
	my_panic("Error reading input.\n",-2);
      buf[n-1] = '\0';
      vect = my_str2vect(buf);
      /* check if command is non-fork */
      if ( my_strcmp(*vect,"cd") == 0 )
	{
	  if (*(vect+1) == NULL)
	    {
	      my_str("Usage: cd <directory>\n");
	    }
	  else if (chdir(*(vect+1)))
	    {
	      my_str("Cannot change directory to ");
	      my_str(vect[1]);
	      my_char('\n');
	    }
	}
      else if ( my_strcmp(*vect,"exit") == 0 )
	{
	  my_str("Bye!\n");
	  exit(0);
	}
      /* otherwise fork */
      else
	{
	  pid = fork();
	  if ( pid == 0 )
	    {
	      if ( execvp(vect[0],vect) )
		my_panic("Command not found.\n",2);
	      exit(0);
	    }
	  else if (pid < 0)
	    my_panic("Fork failed.\n",1);
	  else
	    wait();
	}
    }
  return 0;
}
