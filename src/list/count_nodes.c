#include "mylist.h"

/*pre: takes an t_node* that points to the head node in a list.*/
/*post: returns the number of nodes in the list*/
unsigned int count_nodes(t_node *head)
{
  unsigned int count;
  count = 0;
  
  while(head != NULL)
    {
      ++count;
      head = head->next;
    }

  return count;
}
