#define _CLIENT_
#include "suckit.h"

int sockfd;

/*
 *pre: takes a signal
 *post: sends /exit to the server and exits client
*/
void bye(int sig)
{
  int n;
  if ( (n=write(sockfd,"/exit",6) < 0) )
    my_panic("Could not send /exit signal to server.",6);
  close(sockfd);
  my_panic("Bye!\n",0);
}

/*
 *pre: takes a signal
 *post: prints message, and exits with return code 4
*/
void alrmfnc(int sig)
{
  my_panic("Did not receive ACK from server.\n",4);
}

/*
 *pre: automatically takes a vector of arguments and the # of arguments
 *post: drives the client program; connects to server and allows the sending
 *of messages to it.
*/
int main(int argc, char **argv)
{
  struct sockaddr_in srv;
  struct hostent *hst;
  unsigned short portnum;
  char nickbuf[NICKMAX];
  char msgbuf[MSGMAX];
  char ack;
  char msgack;
  char nickack;
  int n;
  ack = 0;
  signal(SIGALRM, alrmfnc);
  signal(SIGINT, bye);
  if (argc != 3)
    {
      my_str("Usage: ");
      my_str(argv[0]);
      my_str(" <hostname/IP> <port #>\n");
      exit(1);
    }
  portnum = my_atoi(argv[2]);
  if (portnum < 1 || portnum > 65535)
    my_panic("Port number must be in range 1-65535\n",1);
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if ((hst=gethostbyname(argv[1])) == NULL)
    my_panic("Failed to resolve hostname\n",2);
  memset(&srv,0,sizeof(srv));
  srv.sin_family = AF_INET;
  srv.sin_port = htons(portnum);
  memcpy(&srv.sin_addr.s_addr, hst->h_addr, hst->h_length);
  //at this point we should have successfuly connected to the server.//
  my_str("Nickname: ");
  n = read(0, nickbuf, NICKMAX-1);
  if (n<0)
    my_panic("Error reading input.\n",5);
  if (n==1)
    my_panic("Please specify a nickname next time\n",6);
  nickbuf[n-1] = '\0';
  /* connect to server */
  if (connect(sockfd,(struct sockaddr *)&srv,sizeof(srv)) < 0)
    my_panic("Failed to connect to host\n",3);
  alarm(3);
  while (!ack)
    {
      n = read(sockfd, &ack, 1);
      usleep(3500);
    }
  alarm(0);
  my_str("Connected to server!\n");
  //send nick to server
  write(sockfd, nickbuf, my_strlen(nickbuf));
  alarm(5);
  while (!nickack)
    {
      n = read(sockfd, &nickack, 1);
      usleep(3500);
    }
  alarm(0);
  nickack = 0;
  while (1)
    {
      my_char(':');
      n = read(0, msgbuf, MSGMAX-1);
      if (n<0)
	my_panic("Error reading input.\n",5);
      msgbuf[n-1] = '\0';
      if (my_strlen(msgbuf) == 0)
	write(sockfd, msgbuf, 1);
      else
	write(sockfd,msgbuf,my_strlen(msgbuf));
      alarm(3);
      while (!msgack)
	{
	  n = read(sockfd, &msgack, 1);
	  usleep(3500);
	}
      alarm(0);
      if (!my_strcmp(msgbuf,"/exit"))
	{
	  usleep(getpid() % 326);
	  my_panic("Bye!\n",0);
	}
      msgack = 0;
      usleep(3000);
    }
  return 0;
}
