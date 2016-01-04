#define _SERVER_
#include "minitalk.h"

struct s_env
{
  pid_t clipid;
  char    done;
}       gl_env;


/*
 *pre: takes a signal
 *post: prints "Bye!" and exits
*/
void bye(int sig)
{
  my_str("\nBye!\n");
  exit(0);
}

/*
 *needs to be called 8 times to create a char..
 *pre: takes a signal (SIGUSR1 or SIGUSR2)
 *post: prints the char by interpreting SIGUSR1 as 1, SIGUSR2 as 0
*/
void getchar(int sig)
{
  static unsigned char c;
  static char count;
  if (sig == SIGUSR2)
    {
      //my_int(0);
      c = c << 1;
      count++;
    }
  if (sig == SIGUSR1)
    {
      //my_int(1);
      if (c==0)
	c = c + 1;
      else
	c = (c << 1) + 1;
      count++;
    }
  if (count == 8)
    {
      c = c >> 1;
      my_char(c);
      //my_char('\n');
      if (c == 0)
	gl_env.done = 1;
      count = 0;	    
      c = 0;
    }
}

/*
 *pre: takes pid and a bit (0 or 1)
 *post: sends the bit to input pid, returns 0 on success, 1 on failure
*/
int sendbit(pid_t srvpid, char bit)
{
  if (bit == 0)
    return kill(srvpid,SIGUSR2);
  if (bit == 1)
    return kill(srvpid,SIGUSR1);
  return 1;
}

/*
 *pre: takes a pid
 *post: sends the input pid to the process pid
*/
void acksend(unsigned int p)
{
  unsigned int cpid = p;
  char bit;
  char i;
  for (i=0; i<(8*sizeof(pid_t)); ++i)
    {
      bit = p >> (8*sizeof(pid_t)-1);
      //my_int(bit);
      if (sendbit(cpid,bit))
	my_panic("Problem sending bit to client\n",3);
      p = p << 1;
      usleep(2000);
    }
  //  my_char('\n');
}

/*
 *needs to be called 8 times
 *pre: takes SIGUSR1 or SIGUSR2 (interprets as binary sigs)
 *post: sets the global gl_env.clipid
*/
void recvpid(int sig)
{
  static unsigned int p;
  if (gl_env.clipid == 0)
    {
      p = 0;
    }
  //0 bit
  if (sig == SIGUSR2)
    {
      p = p << 1;
      //my_int(0);
    }
  //1 bit
  else if (sig == SIGUSR1)
    {
      //my_int(1);
      if (p==0)
	p = p + 1;
      else
	p = (p << 1) + 1;
    }
  gl_env.clipid = p;
}

/*
 *drives the server, exits on Ctrl+C (SIGINT)
*/
int main()
{
  unsigned int w;
  my_str("Server PID: ");
  my_int(getpid());
  my_char('\n');
  signal(SIGINT, bye);
  while (1)
    {
      gl_env.clipid = 0;
      //1 bit
      signal(SIGUSR1, recvpid);
      //0 bit
      signal(SIGUSR2, recvpid);
      for (w=0; w<(8*sizeof(pid_t)); ++w)
	pause();
      my_char('\n');
      my_str("Msg from client with PID: ");
      my_int(gl_env.clipid);
      my_char('\n');
      acksend(gl_env.clipid);
      signal(SIGUSR1, getchar);
      signal(SIGUSR2, getchar);
      while (!gl_env.done)
	pause();
      my_char('\n');
      gl_env.done = 0;
    }
  return 0;
}
