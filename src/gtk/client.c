#define _CLIENT_
#include "suckit.h"
#include <gtk/gtk.h>

int sockfd;
struct senv
{

  /* stuff for main window */
  GtkWidget *mainwin;
  GtkWidget *hbox;
  GtkWidget *vbox;
  GtkWidget *cxhbox;
  GtkWidget *conbutton;
  GtkWidget *exitbutton;
  GtkWidget *sendbutton;
  GtkWidget *mainhalign;
  GtkWidget *mainvalign;
  GtkWidget *msgfield;
  GtkEntryBuffer *msgbuf;
  GtkWidget *conbtnimg;
  GtkWidget *exitbtnimg;
  GtkWidget *sendbtnimg;

  /* stuff for connect window */
  GtkWidget *conwindow;
  GtkWidget *hostlabel;
  GtkWidget *portlabel;
  GtkWidget *nicklabel;
  GtkWidget *hostfield;
  GtkWidget *portfield;
  GtkWidget *nickfield;
  GtkEntryBuffer *hostbuf;
  GtkEntryBuffer *portbuf;
  GtkEntryBuffer *nickbuf;
  GtkWidget *con_vbox;
  GtkWidget *con_host_hbox;
  GtkWidget *con_port_hbox;
  GtkWidget *con_nick_hbox;
  GtkWidget *okbtn;
  GtkWidget *cancelbtn;
  GtkWidget *con_btn_hbox;
  GtkWidget *okbtnimg;
  GtkWidget *cancelbtnimg;

  /* stuff for exit window */
  GtkWidget *exitwindow;
  GtkWidget *exitlabel;
  GtkWidget *exit_vbox;
  GtkWidget *exit_hbox;
  GtkWidget *yesexitbtn;
  GtkWidget *noexitbtn;
  GtkWidget *yesexitbtnimg;
  GtkWidget *noexitbtnimg;

  char connected;
  
} gl_env;

/*
 *disconnects server and sets appropriate variables + buttons
*/
void disconnect()
{
  int n;
  if (gl_env.connected == 1)
    {
      n=write(sockfd,"/exit",6);
      close(sockfd);
    }
  gl_env.connected = 0;
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(gl_env.conbutton),FALSE);
  //  my_str("Disconnected from server!\n");
}

/*
 *pre: takes a GtkWidget and arbitrary data
 *post: disconnects from server and quits client
*/
void gtkquit(GtkWidget *w, gpointer data)
{
  disconnect();
  gtk_main_quit();
}

/*
 *pre: takes a signal
 *post: sends /exit to the server and exits client
*/
void bye(int sig)
{
  disconnect();
  gtk_main_quit();
}

/*
 *shows the connect window
*/
void show_conwindow()
{
  gtk_widget_show(gl_env.conwindow);
}

/*
  pre: take a hostname, port #, and nickname
  post: tries to connect to server, returns non-zero if failure
*/
char connect_to_server(char *hostname, unsigned short portnum, char *nick)
{
  struct sockaddr_in srv;
  struct hostent *hst;
  char ack;
  char nickack;
  int n;

  ack = 0;
  nickack = 0;

  if (portnum < 1 || portnum > 65535)
    {
      my_str("Port number must be in range 1-65535\n");
      disconnect();
      return 1;
    }
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if ((hst=gethostbyname(hostname)) == NULL)
    {
      my_str("Could not resolve hostname\n");
      disconnect();
      return 2;
    }
  memset(&srv,0,sizeof(srv));
  srv.sin_family = AF_INET;
  srv.sin_port = htons(portnum);
  memcpy(&srv.sin_addr.s_addr, hst->h_addr, hst->h_length);
  /* connect to server */
  if (connect(sockfd,(struct sockaddr *)&srv,sizeof(srv)) < 0)
    {
      my_str("Could not connect to server\n");
      disconnect();
      return 3;
    }
  alarm(3);
  while (!ack)
    {
      n = read(sockfd, &ack, 1);
      usleep(3500);
    }
  alarm(0);
  my_str("Connected to server!\n");
  //at this point we should have successfuly connected to the server.//
  //send nick to server
  write(sockfd, nick, my_strlen(nick));
  alarm(5);
  while (!nickack)
    {
      n = read(sockfd, &nickack, 1);
      usleep(3500);
    }
  alarm(0);
  nickack = 0;
  gl_env.connected = 1;

  return 0;
}

/*
 *pre: takes a signal
 *post: prints message, and exits with return code 4
*/
void alrmfnc(int sig)
{
  close(sockfd);
  gl_env.connected = 0;
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(gl_env.conbutton),FALSE);
  my_str("Did not receive ACK from server.\n");
  disconnect();
  //my_panic("Did not receive ACK from server.\n",4);
}

/*
 *pre: takes a GtkWidget and arbitrary data
 *post: hides the connect window, handles button connect button appropriately
*/
void close_connect_window(GtkWidget *w, gpointer data)
{
  if (gl_env.connected == 0)
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(gl_env.conbutton),FALSE);
  if (gl_env.connected == 1)
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(gl_env.conbutton),TRUE);
  gtk_widget_hide(gl_env.conwindow);
}

/*
 *pre: takes a GtkWidget and arbitrary data
 *post: sends msg from gl_env.msgbuf to server
*/
void sendtext(GtkWidget *w, gpointer data)
{
  char *text;
  char msgack;
  int n;

  msgack = 0;
  signal(SIGALRM, alrmfnc);
  signal(SIGINT, bye);

  if (gl_env.connected)
    {
      text = (char *)gtk_entry_buffer_get_text(gl_env.msgbuf);
      alarm(2);
      if (my_strlen(text) == 0)
	n = write(sockfd,"",1);
      else 
	n=write(sockfd,text,my_strlen(text));

      if (!my_strcmp(text,"/exit") && gl_env.connected)
	{
	  usleep(getpid() % 326);
	  disconnect();
	  msgack = 1;
	  alarm(0);
	}
      while (!msgack && gl_env.connected)
	{
	  n = read(sockfd, &msgack, 1);
	  usleep(3500);
	}
      alarm(0);
      msgack = 0;
      usleep(3000);
      gtk_entry_set_text(GTK_ENTRY(gl_env.msgfield),"");
      gtk_entry_buffer_set_text(gl_env.msgbuf,"",-1);
    }
}

/*
 *pre: takes a GtkWidget and arbitrary data
 *post: gets data from host, port, nick bufs, and attempts to
  connect to server using that info
*/
void try_connect(GtkWidget *w, gpointer data)
{
  const gchar *host = gtk_entry_buffer_get_text(gl_env.hostbuf);
  const gchar *port = gtk_entry_buffer_get_text(gl_env.portbuf);
  const gchar *nick = gtk_entry_buffer_get_text(gl_env.nickbuf);
  if (!gl_env.connected)
    {
      if (!connect_to_server((char *)host,(unsigned short)my_atoi((char *)port),(char *)nick))
	{
	  gtk_widget_hide(gl_env.conwindow);
	  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(gl_env.conbutton),TRUE);
	}
    }
}

/*
  pre: takes a GtkWidget and arbitrary data
  post: shows connection window or disconnects depending
  on connect button state
*/
void connect_button_callback(GtkWidget *widget, gpointer data)
{
  if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
    {
      /* toggle button is down, need to launch connect window */
      show_conwindow();
    }
  else
    {
      /* toggle button is up, need to disconnect */
      disconnect();
    }
}

/*
 *pre: takes a GtkWidget and arbitrary data
 *post: shows the exit confirm window
*/
void show_exit_confirm_win(GtkWidget *w, gpointer data)
{
  gtk_widget_show(gl_env.exitwindow);
  gtk_widget_show(gl_env.exit_hbox);
  gtk_widget_show(gl_env.yesexitbtn);
  gtk_widget_show(gl_env.noexitbtn);
}

/*
 *pre: takes a GtkWidget and arbitrary data
 *post: hides the exit confirm window
*/
void hide_exit_confirm_win(GtkWidget *w, gpointer data)
{
  gtk_widget_hide(gl_env.exitwindow);
  gtk_widget_hide(gl_env.exit_hbox);
  gtk_widget_hide(gl_env.yesexitbtn);
  gtk_widget_hide(gl_env.noexitbtn);
}

/*
 *pre: takes a number of arguments and a vector of arguments
 *post: sets up the entire gtk environment (windows, buttons, etc).
  displays the main window.
*/
void gtk_setup(int argc, char **argv)
{
  /* GTK setup */
  gtk_init(&argc,&argv);

  gl_env.mainwin = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gl_env.conwindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gl_env.exitwindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 
  gtk_window_set_default_size(GTK_WINDOW(gl_env.mainwin),600,200);
  gtk_window_set_default_size(GTK_WINDOW(gl_env.conwindow),200,400);
  gtk_window_set_default_size(GTK_WINDOW(gl_env.exitwindow),225,75);
  gtk_window_set_resizable(GTK_WINDOW(gl_env.mainwin),FALSE);
  gtk_window_set_resizable(GTK_WINDOW(gl_env.conwindow),FALSE);
  gtk_window_set_resizable(GTK_WINDOW(gl_env.exitwindow),FALSE);
  gtk_widget_set_size_request(gl_env.mainwin,600,200);
  gtk_widget_set_size_request(gl_env.conwindow,200,400);
  gtk_widget_set_size_request(gl_env.exitwindow,225,75);

  gtk_window_set_position(GTK_WINDOW(gl_env.mainwin),GTK_WIN_POS_CENTER);

  gl_env.hbox = gtk_hbox_new(FALSE,1);
  gl_env.vbox = gtk_vbox_new(FALSE,1);
  gl_env.cxhbox = gtk_hbox_new(FALSE,1);
  gl_env.exit_hbox = gtk_hbox_new(FALSE,1);
  gl_env.conbutton = gtk_toggle_button_new_with_label("Connect");
  gl_env.exitbutton = gtk_button_new_with_label("Exit");
  gl_env.sendbutton = gtk_button_new_with_label("Send");
  gl_env.msgbuf = gtk_entry_buffer_new(NULL,-1);
  gl_env.msgfield = gtk_entry_new_with_buffer(gl_env.msgbuf);

  gl_env.con_vbox = gtk_vbox_new(FALSE,10);
  gl_env.con_host_hbox = gtk_hbox_new(FALSE,1);
  gl_env.con_port_hbox = gtk_hbox_new(FALSE,1);
  gl_env.con_nick_hbox = gtk_hbox_new(FALSE,1);
  gl_env.con_btn_hbox = gtk_hbox_new(FALSE,1);
  gl_env.hostlabel = gtk_label_new("host");
  gl_env.portlabel = gtk_label_new("port");
  gl_env.nicklabel = gtk_label_new("nick");
  gl_env.hostbuf = gtk_entry_buffer_new(NULL,-1);
  gl_env.portbuf = gtk_entry_buffer_new(NULL,-1);
  gl_env.nickbuf = gtk_entry_buffer_new(NULL,-1);
  gl_env.hostfield = gtk_entry_new_with_buffer(gl_env.hostbuf);
  gl_env.portfield = gtk_entry_new_with_buffer(gl_env.portbuf);
  gl_env.nickfield = gtk_entry_new_with_buffer(gl_env.nickbuf);
  gl_env.okbtn = gtk_button_new_with_label("OK");
  /*gl_env.okbtnimg = gtk_image_new_from_file("images/okbtnimg.png");
  gtk_button_set_image(GTK_BUTTON(gl_env.okbtn),gl_env.okbtnimg);
  gtk_image_set_from_file(GTK_IMAGE(gl_env.okbtnimg),"images/okbtnimg.png");*/
  gl_env.cancelbtn = gtk_button_new_with_label("CANCEL");

  gl_env.exit_vbox = gtk_vbox_new(FALSE,1);
  gl_env.exit_hbox = gtk_hbox_new(FALSE,1);
  gl_env.exitlabel = gtk_label_new("Are you sure?");
  gl_env.yesexitbtn = gtk_button_new_with_label("YES");
  gl_env.noexitbtn = gtk_button_new_with_label("NO");
  /*gtk_entry_set_max_length(gl_env.msgfield,MSGMAX);*/

  gtk_widget_set_size_request(gl_env.msgfield,500,25);
  gtk_widget_set_size_request(gl_env.conbutton,75,30);
  gtk_widget_set_size_request(gl_env.exitbutton,75,30);
  gtk_widget_set_size_request(gl_env.sendbutton,60,30);
  gtk_widget_set_size_request(gl_env.okbtn,60,30);
  gtk_widget_set_size_request(gl_env.cancelbtn,60,30);

  gtk_container_add(GTK_CONTAINER(gl_env.mainwin),gl_env.vbox);
  gtk_box_pack_start(GTK_BOX(gl_env.vbox),gl_env.hbox,TRUE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(gl_env.vbox),gl_env.cxhbox,TRUE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(gl_env.hbox),gl_env.msgfield,TRUE,FALSE,1);
  gtk_box_pack_start(GTK_BOX(gl_env.hbox),gl_env.sendbutton,TRUE,FALSE,1);
  gtk_box_pack_start(GTK_BOX(gl_env.cxhbox),gl_env.conbutton,TRUE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(gl_env.cxhbox),gl_env.exitbutton,TRUE,FALSE,0);

  gtk_container_add(GTK_CONTAINER(gl_env.conwindow),gl_env.con_vbox);
  gtk_box_pack_start(GTK_BOX(gl_env.con_host_hbox),gl_env.hostlabel,TRUE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(gl_env.con_host_hbox),gl_env.hostfield,TRUE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(gl_env.con_port_hbox),gl_env.portlabel,TRUE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(gl_env.con_port_hbox),gl_env.portfield,TRUE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(gl_env.con_nick_hbox),gl_env.nicklabel,TRUE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(gl_env.con_nick_hbox),gl_env.nickfield,TRUE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(gl_env.con_btn_hbox),gl_env.okbtn,TRUE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(gl_env.con_btn_hbox),gl_env.cancelbtn,TRUE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(gl_env.con_vbox),gl_env.con_host_hbox,TRUE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(gl_env.con_vbox),gl_env.con_port_hbox,TRUE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(gl_env.con_vbox),gl_env.con_nick_hbox,TRUE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(gl_env.con_vbox),gl_env.con_btn_hbox,TRUE,FALSE,0);

  gtk_box_pack_start(GTK_BOX(gl_env.exit_vbox),gl_env.exitlabel,TRUE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(gl_env.exit_vbox),gl_env.exit_hbox,TRUE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(gl_env.exit_hbox),gl_env.yesexitbtn,TRUE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(gl_env.exit_hbox),gl_env.noexitbtn,TRUE,FALSE,0);
  gtk_container_add(GTK_CONTAINER(gl_env.exitwindow),gl_env.exit_vbox);

  g_signal_connect(G_OBJECT(gl_env.conwindow),"delete_event",G_CALLBACK(close_connect_window),NULL);
  g_signal_connect(G_OBJECT(gl_env.mainwin),"destroy",G_CALLBACK(gtkquit),NULL);
  g_signal_connect(G_OBJECT(gl_env.conbutton),"clicked",G_CALLBACK(connect_button_callback),NULL);
  g_signal_connect(G_OBJECT(gl_env.exitbutton),"clicked",G_CALLBACK(show_exit_confirm_win),NULL);
  g_signal_connect(G_OBJECT(gl_env.sendbutton),"clicked",G_CALLBACK(sendtext),NULL);
  g_signal_connect(G_OBJECT(gl_env.yesexitbtn),"clicked",G_CALLBACK(gtkquit),NULL);
  g_signal_connect(G_OBJECT(gl_env.noexitbtn),"clicked",G_CALLBACK(hide_exit_confirm_win),NULL);
  g_signal_connect(G_OBJECT(gl_env.exitwindow),"delete_event",G_CALLBACK(hide_exit_confirm_win),NULL);
  g_signal_connect(G_OBJECT(gl_env.okbtn),"clicked",G_CALLBACK(try_connect),NULL);
  g_signal_connect(G_OBJECT(gl_env.cancelbtn),"clicked",G_CALLBACK(close_connect_window),NULL);
  g_signal_connect(G_OBJECT(gl_env.msgfield),"activate",G_CALLBACK(sendtext),NULL);

  /* show the main window and its widgets */
  gtk_widget_show(gl_env.mainwin);
  gtk_widget_show(gl_env.hbox);
  gtk_widget_show(gl_env.vbox);
  gtk_widget_show(gl_env.cxhbox);
  gtk_widget_show(gl_env.conbutton);
  gtk_widget_show(gl_env.exitbutton);
  gtk_widget_show(gl_env.sendbutton);
  gtk_widget_show(gl_env.msgfield);
  gtk_widget_show(gl_env.exit_vbox);
  gtk_widget_show(gl_env.exit_hbox);
  gtk_widget_show(gl_env.yesexitbtn);
  gtk_widget_show(gl_env.noexitbtn);
  gtk_widget_show(gl_env.exitlabel);

  gtk_widget_show(gl_env.hostlabel);
  gtk_widget_show(gl_env.portlabel);
  gtk_widget_show(gl_env.nicklabel);
  gtk_widget_show(gl_env.hostfield);
  gtk_widget_show(gl_env.portfield);
  gtk_widget_show(gl_env.nickfield);
  gtk_widget_show(gl_env.con_vbox);
  gtk_widget_show(gl_env.con_host_hbox);
  gtk_widget_show(gl_env.con_port_hbox);
  gtk_widget_show(gl_env.con_nick_hbox);
  gtk_widget_show(gl_env.okbtn);
  gtk_widget_show(gl_env.cancelbtn);
  gtk_widget_show(gl_env.con_btn_hbox);

  gtk_main();
}


/*
 *pre: automatically takes a vector of arguments and the # of arguments
 *post: drives the client program w/ GTK GUI
*/
int main(int argc, char **argv)
{
  struct hostent *hst;
  unsigned short portnum;
  char nickbuf[NICKMAX];
  char msgbuf[MSGMAX];
  char msgack;
  int n;
  gl_env.connected = 0;

  signal(SIGALRM, alrmfnc);
  signal(SIGINT, bye);
  
  gtk_setup(argc,argv);

  return 0;
}
