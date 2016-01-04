#define _SERVER_
#include "suckit.h"

char nickbuf[NICKMAX];

/*
 *pre: takes a signal
 *post: prints goodbye msg, exits server with return code 0
*/

void byesrv(int sig)
{
  usleep(getpid()*40 + 3000);
  my_str("Caught Ctrl+C. Bye!\n");
  exit(0);
}

/*
 *pre: takes a signal
 *post: disconnects client, and prints disconnect msg
*/
void byecli(int sig)
{
  usleep(getpid()*40 + 3000);
  my_str("***");
  my_str(nickbuf);
  my_str(" disconnected\n");
  /* usleep(getpid()*90 + 3000); */
  exit(0);
}

/*
 *pre: takes a msg, and a nickname buffer
 *post: interprets the given command in msgbuf.
 *performs necessary actions as given by command
 *returns -1 if command not recognized. 0-2 depending
 *on command given
*/
int intrpcmd(char *msgbuf, char *nickbuf)
{
  char *cmd;
  unsigned int msglen;
  unsigned int nicklen;
  int i;
  int j;
  msglen = my_strlen(msgbuf);
  nicklen = my_strlen(nickbuf);
  cmd = (char*)xmalloc(CMDMAX*sizeof(char));
  for (i=0; msgbuf[i] != ' '; ++i)
    if (i < 15)
      cmd[i] = msgbuf[i];
  cmd[i] = '\0';
  if (!my_strncmp(msgbuf,"/exit",5))
    {
      my_str("***");
      my_str(nickbuf);
      my_str(" disconnected\n");
      free(cmd);
      return 0;
    }
  if (!my_strncmp(msgbuf,"/nick ",6) && my_strlen(msgbuf) > 6)
    {
      my_str("***");
      my_str(nickbuf);
      my_str(" changed names to ");
      for (i=i+1,j=0; msgbuf[i] != '\0'; ++i, ++j)
	nickbuf[j] = msgbuf[i];
      nickbuf[j] = '\0';
      my_str(nickbuf);
      my_str("\n");
      free(cmd);
      return 1;  
    }
  if (!my_strncmp(msgbuf,"/nick",5) && my_strlen(msgbuf) <= 6)
    {
      my_str("Please specify a nickname\n");
      return 3;
    }
  if (!my_strncmp(msgbuf,"/me ",4) && my_strlen(msgbuf) > 4)
    {
      my_str("***");
      my_str(nickbuf);
      msgbuf = msgbuf + i;
      my_str(msgbuf);
      my_str("\n");
      free(cmd);
      return 2;
    }
  if (!my_strncmp(msgbuf,"/me",3) && my_strlen(msgbuf) <= 4)
    {
      my_str("Please specify an action\n");
      return 5;
    }
  free(cmd);
  my_str("Command not recognized\n");
  return -1;
		      
}

/*
 *pre: automatically takes a vector of arguments and the # of arguments
 *post: drives the server program by setting up a listener and forking
 *on new client connections.
*/
int main(int argc, char **argv)
{
  struct sockaddr_in srv;
  struct sockaddr_in cli;
  unsigned short portnum;
  int sockfd;
  int clisockfd;
  int clilen;
  int pid;
  int n;
  char msgbuf[MSGMAX];
  char ackbit = 1;
  n = 0;
  signal(SIGINT,byesrv);
  if (argc != 2)
    {
      my_str("Usage: ");
      my_str(argv[0]);
      my_str(" <port #>\n");
      exit(1);
    }
  portnum = my_atoi(argv[1]);
  if (portnum < 1 || portnum > 65535)
    my_panic("Port number must be in range 1-65535\n",1);
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  memset(&srv, 0, sizeof(srv));
  srv.sin_addr.s_addr = INADDR_ANY;
  srv.sin_family = AF_INET;
  srv.sin_port = htons(portnum);

  if (bind(sockfd,(struct sockaddr *)&srv,sizeof(srv)) < 0)
    my_panic("Can't bind to port\n",2);
  listen(sockfd, 5);
  clilen = sizeof(cli);
  while(1)
    {
      if ( (clisockfd = accept(sockfd,(struct sockaddr *)&cli,&clilen)) < 0)
	my_panic("Failed to accept connection on socket\n",3);
      pid = fork();
      if (pid < 0)
	{
	  my_panic("Fork failed\n",4);
	}
      else if (pid > 0)
	{
	  close(clisockfd);
	  continue;
	}
      else
	{
	  //child
	  //send ack
	  close(sockfd);
	  write(clisockfd, &ackbit, 1);
	  //get & print nickname
	  n = read(clisockfd, nickbuf, NICKMAX-1);
	  if (n<0)
	    my_panic("Error reading from client.\n",5);
	  //send ack
	  write(clisockfd, &ackbit, 1);
	  nickbuf[n] = '\0';
	  my_str("***");
	  my_str(nickbuf);
	  my_str(" connected\n");
	  //get & print msg
	  while (1)
	    {
	      signal(SIGINT,byecli);
	      n = read(clisockfd, msgbuf, MSGMAX-1);
	      if (n<0)
		my_panic("Error reading from client.\n",5);
	      if (n > 0)
		{
		  //send ack
		  write(clisockfd, &ackbit, 1);
		  //display msg
		  msgbuf[n] = '\0';
		  if (msgbuf[0] == '/')
		    {
		      //client disconnected
		      if (intrpcmd(msgbuf, nickbuf) == 0)
			exit(0);
		    }
		  else
		    {
		      my_str(nickbuf);
		      my_str(": ");
		      my_str(msgbuf);
		      my_str("\n");
		    }
		  usleep(4000);
		}
	    }
	}
      return 0;
    }
}
