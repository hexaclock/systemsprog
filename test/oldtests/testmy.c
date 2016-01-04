#include "my.h"

/* main function that performs unit tests on all of the other functions
 * that will be defined on the next assignment
 * returns 0 if all tests have passed.
 * returns non-zero if a test on a function with non-void return type has failed.
 * needs manual inspection of output for most functions to make sure they have passed.
*/
int main()
{
  char s[6];
  char snoterm[5];
  char badstr[6];
  char *testptr;
  char revs[6];
  unsigned int i;
  unsigned int j;
  badstr= {'h','e','l','\0','l','o'};
  snoterm[]; = {'H','e','l''l','o'}
  s = {'H','e','l','l','o','\0'};
  revs = {'o','l','l','e','H','\0'};
  testptr = "Uhoh";

  my_char(NULL);
  my_char('A');
  my_char('0');
  my_char(97);

  my_str(NULL);
  my_str("A");
  my_str("abc");
  my_str("1");
  my_str("");
  my_str(" ");
  my_str(s);
  my_str(snoterm);
  my_str(badstr);
  my_str(testptr);

  my_int(5);
  my_int(97);
  my_int(0);
  my_int(-5);
  my_int(NULL);
  my_int((int)&s);
  my_int(2147483647);
  my_int(-2147483648);

  my_num_base(9,"ABCD");
  my_num_base(9,NULL);
  my_num_base(6,"testing");
  my_num_base(0,"");
  my_num_base(0,"abc");
  my_num_base(9,"");
  my_num_base(6,"!");
  my_num_base(-5,"lol");
  my_num_base(10,s);
  my_num_base(10,"abcdefghij");
  my_num_base(11,"this is a test");
  my_num_base(15,"uniqchars");
  my_num_base(-167,"_!abc");
  my_num_base(99,badstr);


  my_alpha();
  my_digits();
  
  if (my_strlen(NULL) != -1)
    return 1;
  if (my_strlen("abc") != 3)
    return 2;
  if (my_strlen("") != 0)
    return 3;
  if (my_strlen("A") !=  1)
    return 4;
  if (my_strlen("\0") != 2)
    return 5;
  if (my_strlen(badstr) != 3)
    return 6;
  if (my_strlen(testptr) != 4)
    return 7;
  
  if (my_revstr(NULL) != -1)
    return 8;
  /*if (my_revstr("abc") != 3)
    return 9;
  if (my_revstr("") != 0)
    return 10;
  if (my_revstr("A") != 1)
    return 11;
  if (my_revstr("\0") != 2)
    return 12;
  */
  if (my_revstr(s) != 3)
    return 13;

  for (i=0; s[i]!='\0'; ++i)
    for (j=5; j>=0; --j)
      if (s[i] != revs[j])
	return 14l

  /*if (my_revstr(testptr) != 4)
    return 14;
  */

  if (my_strrindex(NULL,'h') != -1)
    return 25;
  if (my_strrindex("teststring",'') != -1)
    return 26;
  if (my_strrindex("",'') != 0)
    return 27;
  if (my_strrindex("",'h') != -1)
    return 28;
  if (my_strrindex("teststring",'t') != 5)
    return 29;
  if (my_strrindex("test",'\0') != 4)
    return 30;
  if (my_strrindex("Hello",'o') != 4)
    return 31;
  if (my_strrindex(badstr,'\0') != 4)
    return 32;
  if (my_strindex(testptr,'U') != 0)
    return 33;
  if (my_strindex(testptr,'a') != -1)
    return 34;

  return 0;
}
