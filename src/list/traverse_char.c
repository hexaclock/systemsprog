#include "mylist.h"

/*pre: takes a pointer to the node to start printing from*/
/*post: prints the list of chars starting from 'start'*/
void traverse_char(t_node *start)
{
  if (start != NULL)
    {
      while(start->elem != NULL)
	{
	  my_char( *( (char *)(start->elem) ) );
	  my_str(" ");
	  if (start->next != NULL)
	    start = start->next;
	  else
	    return;
	}
    }
  else
    my_str("The list is empty.\n");
}
