/*
 *Description:
 *This header file specifies the signatures of functions that can be used for various general purposes (mostly string manipulation, string printing).
*/
#ifndef _MY_H_
#define _MY_H_

#ifndef NULL
#define NULL ((void *)0)
#endif

#include <unistd.h>
#include <stdlib.h>

/*Assignment 1*/
void my_char(char);
void my_str(char *);
void my_int(int);
void my_num_base(int,char *);
void my_alpha();
void my_digits();
int my_strlen(char *);
int my_revstr(char *);
int my_strindex(char *, char);
int my_strrindex(char *, char);

/*Assignment 2*/
void *xmalloc(int);
char *my_strdup(char *);
char *my_strcpy(char *, char *);
char *my_strncpy(char *, char *, unsigned int);
int my_strcmp(char *, char *);
int my_strncmp(char *, char *, unsigned int);
char *my_strconcat(char *, char *);
char *my_strnconcat(char *, char *, unsigned int);
char *my_strcat(char *, char *);
void my_panic(char *, unsigned int);
char *my_strfind(char *, char);
char *my_strrfind(char *, char);

/*Assignment 4 ~ pipes*/

/*
  |hello|cool|class|NULL|
  input vector points to hello
  function should return:
  |h|e|l|l|o| |c|o|o|l| |c|l|a|s|s|\0|
  *don't call strconcat
  *be aware of empty strings, NULL(s)
  *NULL=>NULL
  *stop at NULL or \0
  if char **vect->NULL ==> ""

  *recommendation: leave for last
 */
char *my_vect2str(char **);

/* Assignment 5 ~ minishell */
char **my_str2vect(char *);

/* Assignment 6 ~ minitalk */
int my_atoi(char *);

#endif

