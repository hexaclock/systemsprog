#include "my.h"

int main()
{
  char *s = "Work/cs392/src/minishell";
  char **vect = my_str2vect(s);
  while (*vect != NULL)
    {
      my_str(*vect);
      vect++;
    }
  return 0;
}
