#define _CLIENT_
#include "minitalk.h"

char gl_ack;

/*
 *pre: takes a pid, and a bit (0 or 1)
 *post: sends the bit to the pid using binary SIGUSR1/SIGUSR2. returns 0 on success, non-zero on failure
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
 *pre: takes pid of the server
 *post: sends this program's pid to the server pid
*/
void sendmypid(pid_t srvpid)
{
  unsigned int mypid = getpid();
  char bit;
  char i;
  my_str("Client PID: ");
  my_int(mypid);
  my_char('\n');
  for (i=0; i<(8*sizeof(pid_t)); ++i)
    {
      bit = mypid >> (8*sizeof(pid_t)-1);
      //my_int(bit);  
      if (sendbit(srvpid,bit))
	my_panic("Problem sending bit to server\n",3);
      mypid = mypid << 1;
      usleep(2000);
    }
  //  my_char('\n');
}

/*
 *needs to be called 8 times
 *pre: takes SIGUSR1 or SIGUSR2
 *post: sets gl_ack if we are sent this program's pid
*/
void ackset(int sig)
{
  static unsigned int p = 0;
  //0 bit
  if (sig == SIGUSR2)
    {
      p = p << 1;
    }
  //1 bit
  else if (sig == SIGUSR1)
    {
      if (p==0)
	p = p + 1;
      else
	p = (p << 1) + 1;
    }
  if (getpid() == p)
    {
      my_str("ACK Received!\n");
      gl_ack = 1;
    }
}

/*
 *pre: takes pid of the server, and a character
 *post: sends the character to the server using SIGUSR1 and SIGUSR2
*/
void sendchar(pid_t srvpid, unsigned char c)
{
  char bit;
  char i;
  char loopmax = 8*sizeof(char);
  if (c == '\0')
    loopmax = (8*sizeof(char))+1;
  for (i=0; i<loopmax; ++i)
    {
      bit = c >> (8*sizeof(char)-1);
      //my_int(bit);
      if (sendbit(srvpid,bit))
	my_panic("Problem sending bit to server\n",3);
      c = c << 1;
      usleep(2000);
    }
  //my_char('\n');
}

/*
 *pre: takes pid of the server and a char *
 *post: sends the char* to the specified server pid
*/
void sendmsg(pid_t srvpid, char *msg)
{
  for (; *msg != '\0'; msg++)
    sendchar(srvpid,*msg);
  sendchar(srvpid,*msg);
}

/*
 *pre: takes a signal
 *post: prints error message, exits program
*/
void alrmfnc(int sig)
{
  my_panic("Did not receive ACK from server.\n",4);
}

/*
 *drives client program.
 *pre: automatically takes the number of arguments supplied 
 and the arguments themselves
 *post: sends arguments to supplied arg specifying server pid.
 *shows usage message on invalid args
*/
int main(int argc, char **argv)
{
  pid_t srvpid;
  char *msg;
  signal(SIGUSR1, ackset);
  signal(SIGUSR2, ackset);
  signal(SIGALRM, alrmfnc);
  gl_ack = 0;
  if (argc < 3)
    {
      my_str("Usage: ");
      my_str(argv[0]);
      my_char(' ');
      my_str("<server PID> <your message>\n");
      my_panic("",1);
    }
  if ( (srvpid = my_atoi(argv[1])) < 1 )
    my_panic("Server PID cannot be less than 1\n",2);
  msg = my_vect2str(&argv[2]);
  sendmypid(srvpid);
  alarm(3);
  while (!gl_ack)
    pause();
  alarm(0);
  my_str("Sending message...\n");
  sendmsg(srvpid,msg);
  my_str("Message sent!\n");
  return 0;    
}
