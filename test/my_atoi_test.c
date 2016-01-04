#include "my.h"

int main()
{
  if ( my_atoi("") != 0 )
    my_panic("problem with test 1",1);

  if ( my_atoi("Hello") != 0 )
    my_panic("problem with test 2",2);

  if ( my_atoi("123Hello") != 123 )
    {
      my_int(my_atoi("123Hello"));
      my_panic("problem with test 3",3);
    }

  if ( my_atoi("45.6") != 45 )
    my_panic("problem with test 4",4);

  if ( my_atoi("-34.6haha") != -34 )
    {
      my_int(my_atoi("-34.6haha"));
      my_panic("problem with test 5",5);
    }

  if ( my_atoi("   \t    \n   567a    ") != 567 )
    my_panic("problem with test 6",6);

  if ( my_atoi("   5   6    ") != 5 )
    my_panic("problem with test 7",7);

  if ( my_atoi("+34 is my #") != 34 )
    my_panic("problem with test 8",8);

  if ( my_atoi("+---++--a+-7") != 0 )
    my_panic("problem with test 9",9);

  if ( my_atoi("+-- +--7") != 0 )
    my_panic("problem with test 10",10);

  if ( my_atoi("-+-7") != 7 )
    my_panic("problem with test 11",11);

  if ( my_atoi("+---7") != -7 )
    my_panic("problem with test 12",12);

  my_str("All tests passed!\n");

  return 0;
}
