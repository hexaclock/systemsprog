#include "my.h"

int main(int argc, char **argv)
{
  char **vect;
  int i;

  if (argc > 1)
    {
      vect = my_str2vect(argv[1]);
      for (i = 0; vect[i] != NULL; i++)
	{
	  my_str("-->");
	  my_str(vect[i]);
	  my_str("<--\n");
	}
    }
  else
    my_str("Use: ./a.out 'some long string'\n");
  return 0;
}
