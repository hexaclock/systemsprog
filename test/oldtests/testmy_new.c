#include "my.h"
/* main function that performs unit tests on all of the other functions
 * that will be defined on the next assignment
 * returns 0 if all tests have passed.
 * returns non-zero if a test on a function with non-void return type has failed.
 * needs manual inspection of output for most functions to make sure they have passed.
 */
int main()
{
  char s[] = {'H','e','l','l','o','\0'};
  char snoterm[] = {'H','e','l','l','o'};
  char badstr[] = {'h','e','l','\0','l','o'};
  char numstring[] = {'0','1','2','3','4','5','6','7','8','9','\0'};
  char one[] = {'t','\0'};
  char *testptr = "Uhoh";
  char revs[] = {'o','l','l','e','H','\0'};
  char blank[] = "";
  unsigned int i;
  unsigned int j;
  int maxneg;
  maxneg = 1 << (8*sizeof(int) - 1);
  
  #if 0
  my_str("Doing my_char tests");
  my_char('\n');
  my_char('A');
  my_char('\n');
  my_char('0');
  my_char('\n');
  my_char(97);
  my_char('\n');
 
  my_str("Doing my_str tests");
  my_str("Testing NULL");
  my_str(NULL);
  my_char('\n');
  my_str("A");
  my_char('\n');
  my_str("abc");
  my_char('\n');
  my_str("1");
  my_char('\n');
  my_str("Testing blank");
  /*my_char('\n');*/
  my_str("");
  my_char('\n');
 
  my_str("Space");
  my_str(" ");
  my_char('\n');
  
  my_str(s);
  my_char('\n');
  my_str(badstr);
  my_char('\n');
  my_str(testptr);
  my_char('\n');
  #endif

  my_int(12345);
  my_char('\n');
  my_int(0);
  my_char('\n');
  my_int(-12345);
  my_char('\n');
  my_int(120000);
  my_char('\n');
  my_int(maxneg);
  my_char('\n');
  my_int(maxneg + 5);
  my_char('\n');
  my_int(-987654321);

  my_alpha();
  my_digits();

  my_char('\n');
  my_int(my_strlen(""));
  my_char('\n');
  my_int(my_strlen(NULL));
  my_char('\n');
  my_int(my_strlen("hi"));
  my_char('\n');
  my_int(my_strlen(s));
  my_char('\n');
  my_str("Testing my_revstr");
  my_revstr(s);
  my_str(s);
  my_char('\n');
  if (my_revstr(NULL) != -1)
    return 1;
  my_str(NULL);
  if (my_revstr(blank) != 0)
    return 2;
  my_str(blank);

  my_revstr(revs);
  my_str(revs);
  my_char('\n');
  my_str(numstring);
  my_revstr(numstring);
  my_char('\n');
  my_str(numstring);
  my_char('\n');
  my_revstr(one);
  my_str(one);
  my_char('\n');
  my_str("my_revstr testing complete.");
  my_char('\n');

  my_str("Checking return vals of strindex");
  if (my_strindex(NULL,'h') != -1)
    return 15;
  if (my_strindex("",'h') != -1)
    return 18;
  if (my_strindex("teststring",'t') != 0)
    return 19;
  if (my_strindex("Hello",'o') != 4)
    return 21;
  if (my_strindex(testptr,'U') != 0)
    return 23;
  if (my_strindex(testptr,'a') != -1)
    return 24;
  my_char('\n');
  my_str("strindex tests passed\n");
  
  my_str("Checking return vals of strrindex");
  if (my_strrindex(NULL,'h') != -1)
    return 25;
  if (my_strrindex("",'h') != -1)
    return 28;
  if (my_strrindex("teststring",'t') != 5)
    return 29;
  if (my_strrindex("Hello",'o') != 4)
    return 31;
  if (my_strindex(testptr,'U') != 0)
    return 33;
  if (my_strindex(testptr,'a') != -1)
    return 34;
  my_char('\n');
  my_str("strrindex tests passed\n");

  my_str("Testing my_num_base\n");
  my_num_base(47,"01234");
  my_char('\n');
  my_num_base(9,NULL);
  my_num_base(7,"testing");
  my_char('\n');
  my_num_base(0,"");
  
  my_num_base(0,"abc");
  my_char('\n');
  my_num_base(9,"");
  my_num_base(6,"!");
  my_char('\n');
  my_num_base(-5,"lol");
  my_char('\n');
  my_num_base(9,"BLAH");
  my_char('\n');
  my_num_base(maxneg,"01");
  my_char('\n');
  my_num_base(47,"01234567");
  my_char('\n');
  my_num_base(-295,"01");
  my_char('\n');
  my_num_base(0,"");
  my_num_base(0,"0123456789");
  my_char('\n');
  my_num_base(-0,"012345");
  my_char('\n');

  my_num_base(100,"01234567");
  my_char('\n');
  my_num_base(15,"");
  return 0;
}
